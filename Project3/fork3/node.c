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
#include "node.h"

struct nodeType* newNode(int type)
{
  struct nodeType *node = (struct nodeType*)malloc(sizeof(struct nodeType));
  node->nodeType = type;
  node->valueValid = VALUE_INVALID;
  node->string = NULL;
  node->parent = NULL;
  node->child = NULL;
  node->lsibling = node;
  node->rsibling = node;

  return node;
}

void addChild(struct nodeType *node, struct nodeType *child)
{
  child->parent = node;

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
        printf("%s/compound_statemnet\n", blank);
        ident += 8;
        break;

      case NODE_STMTLIST:
        printf("%s/statemnet_list\n", blank);
        ident += 8;
        break;

      case NODE_OPTIONALSTMT:
        printf("%s/optional_statements\n", blank);
        ident += 8;
        break;

      case NODE_VARIABLE:
        printf("%s/variable: %s\n", blank, node->string);
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

