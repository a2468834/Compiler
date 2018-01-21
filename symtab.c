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
#include "symtab.h"
#include "node.h"

struct SymTable SymbolTable;
static int scope = 1;
static int mScope = 1;
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

void setParamNo(char *s, int paramNo)
{
    for(int i=0; i<SymbolTable.size; i++)
    {
      if(strcmp(s, SymbolTable.entries[i].name) == 0)
        { SymbolTable.entries[i].paramNo = paramNo; }
    }
}

int setValueValid(char *s, int _scope, char valueValid)
{
  for(int i=0; i<SymbolTable.size; i++)
  {
    struct SymTableEntry entry = SymbolTable.entries[i];
    if(strcmp(s, entry.name) == 0 && _scope == entry.scope)
    {
      SymbolTable.entries[i].valueValid = valueValid;
      return 0;
    }
  }
  return-1;
}

struct SymTableEntry* addVariable(
  char *s,
  enum StdType type,
  int arraydepth,
  int idxstart,
  int idxend,
  int isFunction,
  int itsscope,
  int line_no)
{
  if(findSymbol(s, itsscope) != 0)
  {
    printf("Error(%d): duplicate declaration of variable %s\n", line_no, s);
    exit(EXIT_FAILURE);
  }
  // if the name of a variable is the same as a global varable, it means 
  // this variable is that global varable and don't need to add again
  else if(findSymbol(s, 1) != 0)
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
    SymbolTable.entries[index].scope = itsscope;
    SymbolTable.entries[index].paramNo = index;
    SymbolTable.entries[index].valueValid = VALUE_INVALID;

    return &SymbolTable.entries[index];
  }
}

struct nodeType* nthChild(int n, struct nodeType *node)
{
  struct nodeType *child = node->child;
  for(int i=1; i<n; i++)child = child->rsibling;

  return child;
}
/*
int numChild(struct nodeType *node)
{
  
  return ;
}
*/
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
			struct nodeType *idNode = nthChild(1, node);
			struct nodeType *typeNode = nthChild(3, node);

      enum StdType valueType;
      if(typeNode->nodeType == INTEGER)valueType = TypeInt;
			else if(typeNode->nodeType == REAL)valueType = TypeReal;
			//else if(typeNode->nodeType == STRING)valueType = TypeString;
			else valueType = TypeInt;

			idNode->isFunction = 1;
			
      addVariable(
        idNode->string, 
        valueType, 
        0, 
        0, 
        0, 
        idNode->isFunction, 
        1, 
        node->line_no);
			
      scope++;
			curfunc = (char*)malloc(strlen(idNode->string)+1);
			strcpy(curfunc, idNode->string);
			semanticCheck(nthChild(2, node));
			//setParamNo(idNode->string, idNode->rsibling->paramNo);
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
      //printf("add PROCEDURE\n");
      scope++;
      semanticCheck(nthChild(2, node));
      //setParamNo(idNode->string, idNode->rsibling->paramNo);
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
      else if(typeNode->nodeType == STRING)valueType = TypeString;
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
            valueType = TypeInt;
            break;
          case REAL:
            valueType = TypeReal;
            break;
          case STRING:
            valueType = TypeString;
            break;
          default:
          {
            printf("Error(%d): unidentified type %d\n", node->line_no, arrayType->nodeType);
            exit(EXIT_FAILURE);
          }
        }
      }
      else valueType = TypeReal;

      struct nodeType *idList = nthChild(1, node);
      struct nodeType *idNode = idList->child;
      node->paramNo = 0;

      do{
        if (typeNode->nodeType == ARRAY)
        {
          idNode->idxstart = idxstart;
          idNode->idxend = idxend;
          idNode->arraydepth = arraydepth;
        }

        //printf("%d\n", scope);
        addVariable(idNode->string, valueType, arraydepth, idxstart, idxend, 0, scope, node->line_no);
        //printf("add PARAMLIST\n");
        char valueValid = (valueType == TypeInt)? VALUE_I_VALID : VALUE_R_VALID;
        setValueValid(idNode->string, scope, valueValid);
        idNode = idNode->rsibling;
        node->paramNo++;
      }while(idNode != idList->child);

      if (typeNode->rsibling != NULL)
      {
        struct nodeType *sublist = nthChild(3, node);
        semanticCheck(sublist);
        node->paramNo += sublist->paramNo;
      }

      return;
	  }

    case NODE_DECLARATIONS:
    {
      //printTable();
      //printf("%d\n", scope);

      if (node->child == NULL)break;

      struct nodeType *typeNode = nthChild(2, node);
      enum StdType valueType;
      int arraydepth = 0;
      int idxstart = 0;
      int idxend = 0;

      if(typeNode->nodeType == INTEGER)valueType = TypeInt;
      else if(typeNode->nodeType == REAL)valueType = TypeReal;
      else if(typeNode->nodeType == STRING)valueType = TypeString;
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
          case STRING:
          {
            valueType = TypeString;
            break;
          }
          default:
          {
            printf("Error(%d): unidentified type %d\n", node->line_no, arrayType->nodeType);
            exit(EXIT_FAILURE);
          }
        }
      }
      else valueType = TypeReal;

      struct nodeType *idList = nthChild(1, node);
      struct nodeType *idNode = idList->child;
      do
      {
        if (typeNode->nodeType == ARRAY)
        {
          idNode->idxstart = idxstart;
          idNode->idxend = idxend;
          idNode->arraydepth = arraydepth;
        }
        addVariable(idNode->string, valueType, arraydepth, idxstart, idxend, 0, scope, node->line_no);
        //printf("add DECLARATIONS\n");
        idNode = idNode->rsibling;
      } while(idNode != idList->child);

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
      node->paramNo = entry->paramNo;
      struct nodeType *paramlist = nthChild(1, node);

      if (paramlist != NULL)
      {
        semanticCheck(paramlist);
        if (paramlist->paramNo != node->paramNo)
        {
          printf("Error(%d): wrong number of parameter in \"%s\"\n", node->line_no, node->string);
          exit(EXIT_FAILURE);
        }
      }
      else
      {
        if (node->paramNo != 0)
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
      node->paramNo = entry->paramNo;

      struct nodeType *paramlist = nthChild(1, node);
      semanticCheck(paramlist);

      if (paramlist->paramNo != node->paramNo)
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
        node->paramNo = entry->paramNo;

        //printf("%s func:%d\n", node->string, entry->isFunction);
      }

      node->entry = entry;
      node->valueType = entry->type;
      node->arraydepth = entry->arraydepth;
      node->idxstart = entry->idxstart;
      node->idxend = entry->idxend;
      node->valueValid = entry->valueValid;

      //printf("%s valueType:%d\n", node->string, node->valueType);

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
      node->valueValid = child->valueValid;
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
          || child1->arraydepth != child2->arraydepth 
          || child1->valueValid != child2->valueValid 
          )
      {
        printf("Error(%d): type mismatch for operator\n", node->line_no);
        exit(EXIT_FAILURE);
      }

      node->valueValid = child1->valueValid;
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
          setValueValid(child1->string, 1, child2->valueValid);
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
        //printf("valueType child1:%d, child2:%d\n", child1->valueType, child2->valueType);
        //printf("arraydepth child1:%d, child2:%d\n", child1->arraydepth, child2->arraydepth);
        //printf("value child1:%d, child2:%d\n", child1->rValue, child2->iValue);
        printf("Error(%d): type mismatch for assignment\n", node->line_no);
        exit(EXIT_FAILURE);
      }
      /*
      //Check if oprands have been initialized
      if (child1->valueValid == VALUE_INVALID && child1->nodeType == NODE_VARIABLE)
        if (node->nodeType == NODE_OP)
          printf("Warning: use \"%s\" before initialization", child1->string);

      if (child2->valueValid == VALUE_INVALID && child2->nodeType == NODE_VARIABLE)
        printf("Warning: use \"%s\" before initialization", child2->string);
      */
      node->valueType = child1->valueType;
      
      if (node->nodeType == ASSIGNMENT && child1->nodeType == NODE_VARIABLE)
        setValueValid(child1->string, scope, child2->valueValid);

      if (node->nodeType == NODE_OP)
        node->valueValid = child1->valueValid;

      return;
    }

    case NODE_ARGUMENTS:
    {
      if(node->child != NULL)
      {
        struct nodeType *child = nthChild(1, node);
        semanticCheck(child);
        node->paramNo = child->paramNo;
      }

      return;
    }

    case NODE_EXPRLIST:
    {
      struct nodeType *child = nthChild(1, node);
      node->paramNo = 0;
      do
      {
        semanticCheck(child);
        node->paramNo++;
        child = child->rsibling;
      } while(child != node->child);
      
      return;
    }

      //case NODE_STMTLIST:
    }

  /* Default action for other nodes not listed in the switch-case */
  struct nodeType *child = node->child;
  if(child != 0)
  {
    do{
      semanticCheck(child);
      child = child->rsibling;
    }while(child != node->child);
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
    printf(", Type: ");

		if(SymbolTable.entries[i].isFunction == 1)
    {
      printf("FUNCTION (return ");
      if(SymbolTable.entries[i].type == TypeInt)printf("INTEGER)");
      else if(SymbolTable.entries[i].type == TypeReal)printf("REAL)");
    }
		else if(SymbolTable.entries[i].arraydepth > 0)
    {
      printf("%dD-", SymbolTable.entries[i].arraydepth);
      printf("ARRAY");
    }
		else if(SymbolTable.entries[i].type == TypeInt)printf("INTEGER");
		else if(SymbolTable.entries[i].type == TypeReal)printf("REAL");
		else if(SymbolTable.entries[i].type == TypeString)printf("STRING");
		else if(SymbolTable.entries[i].type == TypeProc)printf("PROCEDURE");

		printf(", Scope: %d", SymbolTable.entries[i].scope);
    printf(", ParamNo: %d \n", SymbolTable.entries[i].paramNo);
  }
  printf("+-----------------------------------+\n");
}

