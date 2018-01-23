/*  
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: Construct symbol table and do semantic checking
 *  This is the implementation .c file
 *  Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtab.h"
#include "node.h"

struct SymTable SymbolTable;
static int scope = 1;
static int mScope = 1; // main scope
char *curfunc = NULL;

struct SymTableEntry* findSymbol(char *s, int itsscope)
{
  for(int i=0; i<SymbolTable.size; i++)
  {
		struct SymTableEntry entry = SymbolTable.entries[i];
    if(strcmp(s, entry.name) == 0 && itsscope == entry.scope)
      return &SymbolTable.entries[i];
  }
  return 0;
}

struct SymTableEntry* findSymbol_noscope(char *s)
{
  for(int i=0; i<SymbolTable.size; i++)
  {
    if(strcmp(s, SymbolTable.entries[i].name) == 0)
      { return &SymbolTable.entries[i]; }
  }
  return 0;
}

struct SymTableEntry* findSymbol_localVar(char *name, int itsscope, char* owner)
{
  for(int i=0; i<SymbolTable.size; i++)
  {
    struct SymTableEntry entry = SymbolTable.entries[i];
    if(strcmp(entry.name, name) == 0
       && itsscope == entry.scope
       && strcmp(entry.owned_by, owner) == 0)
    {
      return &SymbolTable.entries[i];
    }
  }
  return 0;
}

void setParamNum(char *s, int paramNum)
{
    for(int i=0; i<SymbolTable.size; i++)
    {
      if(strcmp(s, SymbolTable.entries[i].name) == 0)
        { SymbolTable.entries[i].paramNum = paramNum; }
    }
}

int GetParamNum(struct nodeType *arguments_node)
{
  int parameter_number = 0;
  
  if(arguments_node->child_num != 0)
  {
    // if arguments_node has a child, it means that it has at least a 
    // identifier_list and a identifier_type
    struct nodeType *parameter_list_node = arguments_node->child;

    struct nodeType *identifier_list_node = nthChild(1, parameter_list_node);
    struct nodeType *identifier_type_node = nthChild(2, parameter_list_node);

    for(int i=0; i<identifier_list_node->child_num; i++)
    {
      if(identifier_type_node->nodeType == INTEGER)parameter_number++;
      else if(identifier_type_node->nodeType == REAL)parameter_number++;
      else if(identifier_type_node->nodeType == ARRAY)parameter_number++;
      else printf("Error(%d): unidentified type\n", identifier_type_node->line_no);
    }

    while(parameter_list_node->child_num == 3)
    {
      // do the same procedure in the deeper parameter_list node
      parameter_list_node = nthChild(3, parameter_list_node);

      identifier_list_node = nthChild(1, parameter_list_node);
      identifier_type_node = nthChild(2, parameter_list_node);

      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        if(identifier_type_node->nodeType == INTEGER)parameter_number++;
        else if(identifier_type_node->nodeType == REAL)parameter_number++;
        else if(identifier_type_node->nodeType == ARRAY)parameter_number++;
        else printf("Error(%d): unidentified type\n", identifier_type_node->line_no);
      }
    }
  }

  else parameter_number = 0;

  return parameter_number;
}

struct SymTableEntry* addVariable(
  char *s,
  enum StdType type,
  int arraydepth,
  int idxstart,
  int idxend,
  struct index_info index, 
  int isFunction,
  int itsscope,
  int line_no)
{
  // for FUNCTION, PROCEDURE, and global variable
  if(curfunc == NULL)
  {
    if(findSymbol(s, 1) != 0)
    {
      printf("Error(%d): duplicate declaration of variable '%s'\n", line_no, s);
      exit(EXIT_FAILURE);
    }

    else
    {
      int index = SymbolTable.size;
      SymbolTable.size++;

      strcpy(SymbolTable.entries[index].name, s);
      SymbolTable.entries[index].type = type;
      SymbolTable.entries[index].arraydepth = arraydepth;
      SymbolTable.entries[index].idxstart = idxstart;
      SymbolTable.entries[index].idxend = idxend;

      SymbolTable.entries[index].index[0] = index;
      
      SymbolTable.entries[index].isFunction = isFunction;
      strcpy(SymbolTable.entries[index].owned_by, "\0"); // curfunc is NULL
      SymbolTable.entries[index].scope = itsscope;

      return &SymbolTable.entries[index];
    }
  }

  // for local variable
  else
  {
    if(findSymbol_localVar(s, itsscope, curfunc) != 0)
    {
      printf("Error(%d): duplicate declaration of variable '%s'\n", line_no, s);
      exit(EXIT_FAILURE);
    }

    // if the name of a local variable is the same as a global varable, it means 
    // this variable is that global varable and don't need to add again
    if(findSymbol(s, 1) != 0)
    {
      struct SymTableEntry *entry = findSymbol(s, 1);
      return entry;
    }

    else
    {
      int index = SymbolTable.size;
      SymbolTable.size++;

      strcpy(SymbolTable.entries[index].name, s);
      SymbolTable.entries[index].type = type;
      SymbolTable.entries[index].arraydepth = arraydepth;
      SymbolTable.entries[index].idxstart = idxstart;
      SymbolTable.entries[index].idxend = idxend;
      SymbolTable.entries[index].isFunction = isFunction;
      strcpy(SymbolTable.entries[index].owned_by, curfunc);
      SymbolTable.entries[index].scope = itsscope;

      return &SymbolTable.entries[index];
    }
  }
}

struct nodeType* nthChild(int n, struct nodeType *node)
{
  struct nodeType *child = node->child;
  for(int i=1; i<n; i++)child = child->rsibling;

  return child;
}

void semanticCheck(struct nodeType *node)
{
  switch(node->nodeType)
  {
    case ARRAY:
    {
      struct nodeType *start = nthChild(1, node);
      struct nodeType *end = nthChild(2, node);
      struct nodeType *typeNode = nthChild(3, node);

      if ( (start->nodeType != DIGSEQ) || (end->nodeType != DIGSEQ) )
      {
        printf("Error(%d): Array declaration error", node->line_no);
        exit(EXIT_FAILURE);
      }

      node->idxstart = start->iValue;
      node->idxend = end->iValue;
      semanticCheck(typeNode);

      node->arraydepth = typeNode->arraydepth + 1;

      break;
    }

    case FUNCTION:
    {
      scope = mScope;
      
      struct nodeType *function_name_node = nthChild(1, node);
      struct nodeType *arguments_node = nthChild(2, node);
      struct nodeType *function_type_node = nthChild(3, node);

      enum StdType return_type;
      if(function_type_node->nodeType == INTEGER)return_type = TypeInt;
      else if(function_type_node->nodeType == REAL)return_type = TypeReal;
      // actually, a method's type of return value should be either "I" or "F"
      else return_type = TypeInt;

      char* function_name = (char*)malloc(strlen(function_name_node->string)+1);
      strcpy(function_name, function_name_node->string);

      int parameter_number;
      parameter_number = GetParamNum(nthChild(2, node));

      addVariable(function_name, return_type, 0, 0, 0, 1, 1, node->line_no);
      setParamNum(function_name, parameter_number);
      
      scope++;
      
      curfunc = (char*)malloc(strlen(function_name_node->string)+1);
      strcpy(curfunc, function_name_node->string);
      
      semanticCheck(nthChild(2, node));
      semanticCheck(nthChild(4, node));
      semanticCheck(nthChild(5, node));
      
      free(curfunc);
      curfunc = NULL;
      return;
    }

    case PROCEDURE:
    {
      scope = mScope;
      struct nodeType *idNode = nthChild(1, node);
      addVariable(idNode->string, TypeProc, 0, 0, 0, 1, 1, node->line_no);
      
      scope++;
      semanticCheck(nthChild(2, node));
      setParamNum(idNode->string, idNode->rsibling->paramNum);
      semanticCheck(nthChild(3, node));
      semanticCheck(nthChild(4, node));
      
      return;
	  }

	  case NODE_PARAMLIST:
    {
      struct nodeType *typeNode = nthChild(2, node);

      enum StdType valueType;
      int arraydepth = 0;
      int idxstart = 0;
      int idxend = 0;

      if(typeNode->nodeType == INTEGER)valueType = TypeInt;
      else if(typeNode->nodeType == REAL)valueType = TypeReal;
      else if(typeNode->nodeType == ARRAY)
      {
        semanticCheck(typeNode);

        arraydepth = typeNode->arraydepth;        
        idxstart = typeNode->idxstart;
        idxend = typeNode->idxend;
        
        struct nodeType *arrayType = typeNode->ref;
        while(arrayType->nodeType == ARRAY)arrayType = arrayType->ref;

        switch( arrayType->nodeType )
        {
          case INTEGER:
          {
            valueType = TypeInt;
            break;
          }
          case REAL:
          {
            valueType = TypeReal;
            break;
          }
          default:
          {
            printf("Error(%d): unidentified type\n", node->line_no);
            exit(EXIT_FAILURE);
          }
        }
      }
      else
      {
        printf("Error(%d): unidentified type\n", node->line_no);
        exit(EXIT_FAILURE);
      }

      struct nodeType *idList = nthChild(1, node);
      struct nodeType *idNode = idList->child;
      //node->paramNum = 0;

      do{
        if (typeNode->nodeType == ARRAY)
        {
          idNode->idxstart = idxstart;
          idNode->idxend = idxend;
          idNode->arraydepth = arraydepth;
        }

        addVariable(idNode->string, valueType, arraydepth, idxstart, idxend, 0, scope, node->line_no);
        idNode = idNode->rsibling;
      }while(idNode != idList->child);

      if (typeNode->rsibling != NULL)
      {
        struct nodeType *sublist = nthChild(3, node);
        semanticCheck(sublist);
      }

      return;
	  }

    case NODE_DECLARATIONS:
    {
      if (node->child == NULL)break;

      struct nodeType *typeNode = nthChild(2, node);
      enum StdType valueType;
      int arraydepth = 0;
      int idxstart = 0;
      int idxend = 0;

      if(typeNode->nodeType == INTEGER)valueType = TypeInt;
      else if(typeNode->nodeType == REAL)valueType = TypeReal;
      else if (typeNode->nodeType == ARRAY)
      {
        semanticCheck(typeNode);

        arraydepth = typeNode->arraydepth;
        idxstart = typeNode->idxstart;
        idxend = typeNode->idxend;
        struct nodeType *arrayType = typeNode->ref;
        while(arrayType->nodeType == ARRAY)arrayType = arrayType->ref;

        switch( arrayType->nodeType )
        {
          case INTEGER:
          {
            valueType = TypeInt;
            break;
          }
          case REAL:
          {
            valueType = TypeReal;
            break;
          }
          default:
          {
            printf("Error(%d): unidentified type\n", node->line_no);
            exit(EXIT_FAILURE);
          }
        }
      }
      else printf("Error(%d): unidentified type\n", node->line_no);

      struct nodeType *id_list = nthChild(1, node);

      for(int i=0; i<id_list->child_num; i++)
      {
        struct nodeType *id_list_child = nthChild(i+1, id_list);
        if(findSymbol(id_list_child->string, 1) != 0)
        {
          printf("Error(%d): attempt to overload the variable '%s'\n", node->line_no, id_list_child->string);
          exit(EXIT_FAILURE);
        }
        
        else
        {
          addVariable(id_list_child->string, valueType, arraydepth, idxstart, idxend, 0, scope, node->line_no);
        }
      }

      semanticCheck(nthChild(3, node));

      return;
    }

    case NODE_PROCEDURESTMT:
    {
      struct SymTableEntry *entry = findSymbol_noscope(node->string);
      if(entry == 0)
      {
        printf("Error(%d): undeclared procedure \"%s\"\n", node->line_no, node->string);
        exit(EXIT_FAILURE);
      }
      struct nodeType *paramlist = nthChild(1, node);

      if (paramlist != NULL)
      {
        semanticCheck(paramlist);
        if (paramlist->paramNum != node->paramNum)
        {
          printf("Error(%d): wrong number of parameter in \"%s\"\n", node->line_no, node->string);
          exit(EXIT_FAILURE);
        }
      }
      else
      {
        if (node->paramNum != 0)
        {
          printf("Error(%d): wrong number of parameter in \"%s\"\n", node->line_no, node->string);
          exit(EXIT_FAILURE);
        }
      }

      return;
    }

    case NODE_CALLFUNC:
    {
      struct SymTableEntry *entry = findSymbol_noscope(node->string);

      if(entry == 0)
      {
        printf("Error(%d): undeclared function \"%s\"\n", node->line_no, node->string);
        exit(EXIT_FAILURE);
      }

      node->entry = entry;
      node->valueType = entry->type;
      node->isFunction = 1;
      //node->paramNum = entry->paramNum;

      struct nodeType *paramlist = nthChild(1, node);
      semanticCheck(paramlist);

      if (paramlist->paramNum != node->paramNum)
      {
        printf("Error(%d): wrong number of parameter in \"%s\"\n", node->line_no, node->string);
        exit(EXIT_FAILURE);
      }

      return;
    }

    case NODE_VARIABLE:
    {
      struct SymTableEntry *entry = findSymbol(node->string, scope);

      if(entry == 0)
      {
        entry = findSymbol(node->string, 1);

        if(entry == 0)
        {
          printf("Error(%d): undeclared variable \"%s\"\n", node->line_no, node->string);
          exit(EXIT_FAILURE);
        }

        node->isFunction = entry->isFunction;
        //node->paramNum = entry->paramNum;
      }

      node->entry = entry;
      node->valueType = entry->type;
      node->arraydepth = entry->arraydepth;
      node->idxstart = entry->idxstart;
      node->idxend = entry->idxend;

      if (node->arraydepth > 0)
      {
        struct nodeType *tail = nthChild(1, node);
        semanticCheck(tail);

        while(tail->child != NULL)
        {
          node->arraydepth--;
          tail = nthChild(1, tail);
          if (node->arraydepth < 0)
          {
            printf("Error(%d): wrong array dimension of \"%s\"\n", node->line_no, node->string);
            exit(EXIT_FAILURE);
          }
        }
      }

      break;
    }

    case DIGSEQ:
    {
      node->valueType = TypeInt;
      break;
    }

    case REALNUMBER:
    {
      node->valueType = TypeReal;
      break;
    }

    /* Unary operator */
    case NODE_UOP:
    {
      struct nodeType *child = nthChild(1, node);
      semanticCheck(child);
      node->valueType = child->valueType;

      // node->valueType is TypeInt means that it's a integer
      if (node->valueType == TypeInt)node->iValue = child->iValue*(-1);
      else node->rValue = child->rValue*(-1);
      
      break;
    }

      /* You should check the LHS of assign stmt is assignable
         You should also report error if LHS is a function with no parameter 
         (function is not implemented in this sample, you should implement it) */ 
    case NODE_OP:
    {
      struct nodeType *child1 = nthChild(1, node);
      struct nodeType *child2 = nthChild(2, node);
      semanticCheck(child1);
      semanticCheck(child2);

      if( child1->valueType != child2->valueType 
          || child1->arraydepth != child2->arraydepth )
      {
        printf("op:%d\n", node->op);
        printf("child1, child2:\n");
        printf("%d   %d\n", child1->valueType, child2->valueType);
        printf("%d   %d\n", child1->arraydepth, child2->arraydepth);
        printf("Error(%d): type mismatch for operator\n", node->line_no);
        exit(EXIT_FAILURE);
      }

      node->valueType = child1->valueType;
      
      break;
    }

    case ASSIGNMENT:
    {
      struct nodeType *child1 = nthChild(1, node);
      struct nodeType *child2 = nthChild(2, node);
      semanticCheck(child1);
      semanticCheck(child2);
      if (node->nodeType == ASSIGNMENT && child1->isFunction && curfunc != NULL)
      {
        //This is return value
        if(strcmp(child1->string, curfunc) == 0)
        {
          // empty method
        }
        else
        {
          printf("Error(%d): left hand side \"%s\" is not assignable\n", node->line_no, child1->string);
          exit(EXIT_FAILURE);
        }
      }

      /* We only implement the checking for integer and real types
         you should implement the checking for array type by yourself */
      if(child1->valueType != child2->valueType || child1->arraydepth != child2->arraydepth)
      {
        printf("Error(%d): type mismatch for assignment\n", node->line_no);
        exit(EXIT_FAILURE);
      }
      node->valueType = child1->valueType;

      return;
    }

    case NODE_ARGUMENTS:
    {
      if(node->child != NULL)
      {
        struct nodeType *child = nthChild(1, node);
        semanticCheck(child);
        //node->paramNum = child->paramNum;
      }

      return;
    }

    case NODE_EXPRLIST:
    {
      struct nodeType *child = nthChild(1, node);
      //node->paramNum = 0;
      do
      {
        semanticCheck(child);
        //node->paramNum++;
        child = child->rsibling;
      } while(child != node->child);
      
      return;
    }

    case NODE_STMTLIST:
    {
      for(int i=0; i<node->child_num; i++)
      {
        struct nodeType *assignment_node = nthChild(i+1, node);
        semanticCheck(assignment_node);
      }
      break;
    }
  }

  /* Default action for other nodes not listed in the switch-case */
  for(int i=0; i<node->child_num; i++)
  {
    struct nodeType *child = nthChild(i+1, node);
    semanticCheck(child);
  }
}

void printTable()
{
  printf("+-----------------------------------+\n");
  printf("Table size: %d\n", SymbolTable.size);
  printf("+-----------------------------------+\n");

  for (int i=0; i<SymbolTable.size; i++)
  {
    printf("Name: %s ", SymbolTable.entries[i].name);
    printf(", Scope: %d", SymbolTable.entries[i].scope);
    printf(", Type: ");

    if(SymbolTable.entries[i].isFunction == 1)
    {
      printf("FUNCTION (return ");
      if(SymbolTable.entries[i].type == TypeInt)printf("INTEGER)");
      else if(SymbolTable.entries[i].type == TypeReal)printf("REAL)");
      printf(", ParamNo: %d", SymbolTable.entries[i].paramNum);
    }

    else if(SymbolTable.entries[i].arraydepth > 0)
    {
      printf("%dD-", SymbolTable.entries[i].arraydepth);

      if(SymbolTable.entries[i].type == TypeInt)printf("INT-");
      else if(SymbolTable.entries[i].type == TypeReal)printf("REAL-");

      printf("ARRAY");
    }

    else if(SymbolTable.entries[i].type == TypeInt)printf("INTEGER");
    else if(SymbolTable.entries[i].type == TypeReal)printf("REAL");
    else if(SymbolTable.entries[i].type == TypeProc)printf("PROCEDURE");

    printf("\n");
  }
  printf("+-----------------------------------+\n");
}

