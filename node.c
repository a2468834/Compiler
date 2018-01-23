/*  
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: Construct abstract syntax tree
 *  This is the implementation .c file
 *  Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"

struct nodeType* newNode(int type, int line_no)
{
  struct nodeType *node = (struct nodeType*)malloc(sizeof(struct nodeType));
  node->nodeType = type;
  node->valueValid = VALUE_INVALID;
  node->string = NULL;
  node->parent = NULL;
  node->child = NULL;
  node->lsibling = node;
  node->rsibling = node;
  node->line_no = line_no;
  node->child_num = 0;

  return node;
}

void addChild(struct nodeType *node, struct nodeType *child)
{
  child->parent = node;
  node->child_num++;

  if(node->child == NULL)
  {
    node->child = child;
  }

  else
  {
    child->lsibling = node->child->lsibling;
    child->rsibling = node->child;
    node->child->lsibling->rsibling = child;
    node->child->lsibling = child;
  }
}

void deleteNode(struct nodeType *node)
{
  if(node->string != NULL) free(node->string);
  free(node);
}

void printTree(struct nodeType *node, int ident)
{
    static char blank[1024];

    for(int i=0; i<ident; i++) blank[i] = ' ';
    blank[ident] = 0;

    switch(node->nodeType)
    {
      case NODE_UOP:
        printf("%sUnary\n", blank);
        break;

      case NODE_OP:
        switch(node->op)
        {
          case OP_ADD:
            printf("%s+\n", blank);
            break;
          case OP_SUB:
            printf("%s-\n", blank);
            break;
          case OP_MUL:
            printf("%s*\n", blank);
            break;
          case OP_DIV:
            printf("%s/\n", blank);
            break;
          case OP_GT:
            printf("%s>\n", blank);
            break;
          case OP_LT:
            printf("%s<\n", blank);
            break;
          case OP_GE:
            printf("%s>=\n", blank);
            break;
          case OP_LE:
            printf("%s<=\n", blank);
            break;
          case OP_EQ:
            printf("%s=\n", blank);
            break;
          case OP_NE:
            printf("%s!=\n", blank);
            break;
        }
        ident += 8;
        break;

      case NODE_INT:
        printf("%s%d\n", blank, node->iValue);
        ident += 8;
        break;

      case NODE_SUBPROGRAM:
        printf("%s/subprogram_declaration\n", blank);
        ident += 8;
        break;

      case NODE_SUBPROGRAMS:
        printf("%s/subprogram_declarations\n", blank);
        ident += 8;
        break;

      case NODE_DECLARATIONS:
        printf("%s/declarations\n", blank);
        ident += 8;
        break;

      case NODE_STDTYPE:
        printf("%s/standard_type\n", blank);
        ident += 8;
        break;

      case NODE_SUBPROGRAMHEAD:
        printf("%s/subprogram_head\n", blank);
        ident += 8;
        break;

      case NODE_ARGUMENTS:
        printf("%s/arguments\n", blank);
        ident += 8;
        break;

      case NODE_IDLIST:
        printf("%s/identifier_list\n", blank);
        ident += 8;
        break;

      case NODE_PARAMLIST:
        printf("%s/parameter_list\n", blank);
        ident += 8;
        break;

      case NODE_OPTIONALVAR:
        printf("%s/optional_var\n", blank);
        ident += 8;
        break;

      case NODE_COMPOUND:
        printf("%s/compound_statement\n", blank);
        ident += 8;
        break;

      case NODE_STMTLIST:
        printf("%s/statement_list\n", blank);
        ident += 8;
        break;

      case NODE_OPTIONALSTMT:
        printf("%s/optional_statements\n", blank);
        ident += 8;
        break;

      case NODE_VARIABLE:
        printf("%s/variable: %s, type:%d\n", blank, node->string, node->valueType);
        ident += 8;
        break;

      case NODE_PROCEDURESTMT:
        printf("%s/procedure_statement: %s\n", blank, node->string);
        ident += 8;
        break;

      case NODE_CALLFUNC:
        printf("%s/call_func\n", blank);
        ident += 8;
        break;

      case NODE_SIMPLEEXPR:
        printf("%s/simple_expression\n", blank);
        ident += 8;
        break;

      case NODE_STMT:
        printf("%s/statement\n", blank);
        ident += 8;
        break;

      case NODE_TERM:
        printf("%s/term\n", blank);
        ident += 8;
        break;

      case NODE_EXPR:
        printf("%s/expression\n", blank);
        ident += 8;
        break;

      case NODE_EXPRLIST:
        printf("%s/expression_list\n", blank);
        ident += 8;
        break;

      case NODE_ID:
        printf("%s/id\n", blank);
        break;

      case NODE_FACTOR:
        printf("%s/factor\n", blank);
        ident +=8;
        break;

      case NODE_TAIL:
        printf("%s/tail\n", blank);
        ident +=8;
        break;

      case NODE_ADDOP:
        printf("%s/addop\n", blank);
        ident +=8;
        break;

      case NODE_MULOP:
        printf("%s/mulop\n", blank);
        ident +=8;
        break;

      case NODE_RELOP:
        printf("%s/relop\n", blank);
        ident +=8;
        break;

      case NODE_NUM:
        printf("%s/num\n", blank);
        ident +=8;
        break;

      case NOT:
        printf("%s/NOT\n", blank);
        ident += 8;
        break;

      case NODE_PROG:
        printf("%s/prog\n", blank);
        ident += 8;
        break;


      case ARRAY:
        printf("%s/ARRAY\n", blank);
        ident += 8;
        break;

      case ASSIGNMENT:
        printf("%s/ASSIGNMENT\n", blank);
        ident += 8;
        break;

      case CASE:
        printf("%s/CASE\n", blank);
        ident += 8;
        break;

      case CHARACTER:
        printf("%s%c\n", blank, node->iValue);
        ident += 8;
        break;

      case COLON:
        printf("%s/COLON\n", blank);
        ident += 8;
        break;

      case COMMA:
        printf("%s/COMMA\n", blank);
        ident += 8;
        break;

      case CONST:
        printf("%s/CONST\n", blank);
        ident += 8;
        break;

      case DIGSEQ:
        printf("%s%d\n", blank, node->iValue);
        ident += 8;
        break;

      case DO:
        printf("%s/DO\n", blank);
        ident += 8;
        break;

      case DOTDOT:
        printf("%s/DOTDOT\n", blank);
        break;

      case ELSE:
        printf("%s/ELSE\n", blank);
        ident += 8;
        break;

      case END:
        printf("%s/END\n", blank);
        ident += 8;
        break;

      case FUNCTION:
        printf("%s/FUNCTION\n", blank);
        ident += 8;
        break;

      case IDENTIFIER:
        printf("%s%s\n", blank, node->string);
        ident += 8;
        break;

      case IF:
        printf("%s/IF\n", blank);
        ident += 8;
        break;

      case INTEGER:
        printf("%s/INTEGER\n", blank);
        ident += 8;
        break;

      case LBRAC:
        printf("%s/LBRAC\n", blank);
        break;

      case LPAREN:
        printf("%s/LPRAM\n", blank);
        break;

      case OF:
        printf("%s/OF\n", blank);
        ident += 8;
        break;

      case PBEGIN:
        printf("%s/PBEGIN\n", blank);
        ident += 8;
        break;

      case PROCEDURE:
        printf("%s/PROCEDURE\n", blank);
        ident += 8;
        break;

      case PROGRAM:
        printf("%s/PROGRAM\n", blank);
        ident += 8;
        break;

      case RBRAC:
        printf("%s/RBRAC\n", blank);
        break;

      case REAL:
        printf("%s/REAL\n", blank);
        ident += 8;
        break;

      case REALNUMBER:
        printf("%s%f\n", blank, node->rValue);
        ident += 8;
        break;

      case RPAREN:
        printf("%s/RPAREN\n", blank);
        break;

      case SEMICOLON:
        printf("%s/SEMICOLON\n", blank);
        ident += 8;
        break;

      case STRING:
        printf("%s/STRING\n", blank);
        ident += 8;
        break;

      case THEN:
        printf("%s/THEN\n", blank);
        ident += 8;
        break;

      case VAR:
        printf("%s/VAR\n", blank);
        ident += 8;
        break;

      case WHILE:
        printf("%s/WHILE\n", blank);
        ident += 8;
        break;

      case WRITELN:
        printf("%s/WRITELN\n", blank);
        ident += 8;
        break;

      default:
        printf("%s/default:%d\n", blank, node->nodeType);
        break;
    }

    struct nodeType *child = node->child;
    if(child != NULL)
    {
      do
      {
        printTree(child, ident);
        child = child->rsibling;
      } while(child != node->child);
    }
}

char* printNode(struct nodeType *node)
{
  char *result = (char*)malloc(100*sizeof(char));

  switch(node->nodeType)
  {
    case NODE_UOP:
      strcat(result, "\\NODE_UOP\n");
      break;

    case NODE_OP:
      switch(node->op)
      {
        case OP_ADD:
          strcat(result, "\\OP_ADD\n");
          break;
        case OP_SUB:
          strcat(result, "\\OP_SUB\n");
          break;
        case OP_MUL:
          strcat(result, "\\OP_MUL\n");
          break;
        case OP_DIV:
          strcat(result, "\\OP_DIV\n");
          break;
        case OP_GT:
          strcat(result, "\\OP_GT\n");
          break;
        case OP_LT:
          strcat(result, "\\OP_LT\n");
          break;
        case OP_GE:
          strcat(result, "\\OP_GE\n");
          break;
        case OP_LE:
          strcat(result, "\\OP_LE\n");
          break;
        case OP_EQ:
          strcat(result, "\\OP_EQ\n");
          break;
        case OP_NE:
          strcat(result, "\\OP_NE\n");
          break;
      }
      break;

    case NODE_INT:
      strcat(result, "\\NODE_INT\n");
      break;

    case NODE_SUBPROGRAM:
      strcat(result, "\\NODE_SUBPROGRAM\n");
      break;

    case NODE_SUBPROGRAMS:
      strcat(result, "\\NODE_SUBPROGRAMS\n");
      break;

    case NODE_DECLARATIONS:
      strcat(result, "\\NODE_DECLARATIONS\n");
      break;

    case NODE_STDTYPE:
      strcat(result, "\\NODE_STDTYPE\n");
      break;

    case NODE_SUBPROGRAMHEAD:
      strcat(result, "\\NODE_SUBPROGRAMHEAD\n");
      break;

    case NODE_ARGUMENTS:
      strcat(result, "\\NODE_ARGUMENTS\n");
      break;

    case NODE_IDLIST:
      strcat(result, "\\NODE_IDLIST\n");
      break;

    case NODE_PARAMLIST:
      strcat(result, "\\NODE_PARAMLIST\n");
      break;

    case NODE_OPTIONALVAR:
      strcat(result, "\\NODE_OPTIONALVAR\n");
      break;

    case NODE_COMPOUND:
      strcat(result, "\\NODE_COMPOUND\n");
      break;

    case NODE_STMTLIST:
      strcat(result, "\\NODE_STMTLIST\n");
      break;

    case NODE_OPTIONALSTMT:
      strcat(result, "\\NODE_OPTIONALSTMT\n");
      break;

    case NODE_VARIABLE:
      strcat(result, "\\NODE_VARIABLE\n");
      break;

    case NODE_PROCEDURESTMT:
      strcat(result, "\\NODE_PROCEDURESTMT\n");
      break;

    case NODE_CALLFUNC:
      strcat(result, "\\NODE_CALLFUNC\n");
      break;

    case NODE_SIMPLEEXPR:
      strcat(result, "\\NODE_SIMPLEEXPR\n");
      break;

    case NODE_STMT:
      strcat(result, "\\NODE_STMT\n");
      break;

    case NODE_TERM:
      strcat(result, "\\NODE_TERM\n");
      break;

    case NODE_EXPR:
      strcat(result, "\\NODE_EXPR\n");
      break;

    case NODE_EXPRLIST:
      strcat(result, "\\NODE_EXPRLIST\n");
      break;

    case NODE_ID:
      strcat(result, "\\NODE_ID\n");
      break;

    case NODE_FACTOR:
      strcat(result, "\\NODE_FACTOR\n");
      break;

    case NODE_TAIL:
      strcat(result, "\\NODE_TAIL\n");
      break;

    case NODE_ADDOP:
      strcat(result, "\\NODE_ADDOP\n");
      break;

    case NODE_MULOP:
      strcat(result, "\\NODE_MULOP\n");
      break;

    case NODE_RELOP:
      strcat(result, "\\NODE_RELOP\n");
      break;

    case NODE_NUM:
      strcat(result, "\\NODE_NUM\n");
      break;

    case NOT:
      strcat(result, "\\NOT\n");
      break;

    case NODE_PROG:
      strcat(result, "\\NODE_PROG\n");
      break;


    case ARRAY:
      strcat(result, "\\ARRAY\n");
      break;

    case ASSIGNMENT:
      strcat(result, "\\ASSIGNMENT\n");
      break;

    case CASE:
      strcat(result, "\\CASE\n");
      break;

    case CHARACTER:
      strcat(result, "\\CHARACTER\n");
      break;

    case COLON:
      strcat(result, "\\COLON\n");
      break;

    case COMMA:
      strcat(result, "\\COMMA\n");
      break;

    case CONST:
      strcat(result, "\\CONST\n");
      break;

    case DIGSEQ:
      strcat(result, "\\DIGSEQ\n");
      break;

    case DO:
      strcat(result, "\\DO\n");
      break;

    case DOTDOT:
      strcat(result, "\\DOTDOT\n");
      break;

    case ELSE:
      strcat(result, "\\ELSE\n");
      break;

    case END:
      strcat(result, "\\END\n");
      break;

    case FUNCTION:
      strcat(result, "\\FUNCTION\n");
      break;

    case IDENTIFIER:
      strcat(result, "\\IDENTIFIER\n");
      break;

    case IF:
      strcat(result, "\\IF\n");
      break;

    case INTEGER:
      strcat(result, "\\INTEGER\n");
      break;

    case LBRAC:
      strcat(result, "\\LBRAC\n");
      break;

    case LPAREN:
      strcat(result, "\\LPRAM\n");
      break;

    case OF:
      strcat(result, "\\OF\n");
      break;

    case PBEGIN:
      strcat(result, "\\PBEGIN\n");
      break;

    case PROCEDURE:
      strcat(result, "\\PROCEDURE\n");
      break;

    case PROGRAM:
      strcat(result, "\\PROGRAM\n");
      break;

    case RBRAC:
      strcat(result, "\\RBRAC\n");
      break;

    case REAL:
      strcat(result, "\\REAL\n");
      break;

    case REALNUMBER:
      strcat(result, "\\REALNUMBER");
      break;

    case RPAREN:
      strcat(result, "\\RPAREN\n");
      break;

    case SEMICOLON:
      strcat(result, "\\SEMICOLON\n");
      break;

    case STRING:
      strcat(result, "\\STRING\n");
      break;

    case THEN:
      strcat(result, "\\THEN\n");
      break;

    case VAR:
      strcat(result, "\\VAR\n");
      break;

    case WHILE:
      strcat(result, "\\WHILE\n");
      break;

    default:
      strcat(result, "\\unknown:%d\n");
      break;
  }
  return result;
}

