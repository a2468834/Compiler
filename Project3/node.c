#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

struct nodeType* newNode(int type) {
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

void addChild(struct nodeType *node, struct nodeType *child) {
    child->parent = node;

    if(node->child == NULL) {
        node->child = child;
    }
    else {
        child->lsibling = node->child->lsibling;
        child->rsibling = node->child;
        node->child->lsibling->rsibling = child;
        node->child->lsibling = child;
    }
}

void deleteNode(struct nodeType *node) {
    if(node->string != NULL)
        free(node->string);
    free(node);
}

void printTree(struct nodeType *node, int ident) {
    static char blank[1024];
    for(int i=0; i<ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    switch(node->nodeType)
    {
        case NODE_prog:
            printf("%s/ROOT\n", blank);
            ident += 8;
            break;
        case NODE_identifier_list:
            printf("%s/IDENTIFIER_LIST\n", blank);
            ident += 8;
            break;
        case NODE_declarations:
            printf("%s/DECLARATIONS\n", blank);
            ident += 8;
            break;
        case NODE_type:
            printf("%s/TYPE\n", blank);
            ident += 8;
            break;
        case NODE_standard_type:
            printf("%s/STANDARD_TYPE\n", blank);
            ident += 8;
            break;
        case NODE_subprogram_declaration:
            printf("%s/SUBPROGRAM_DECLARATION\n", blank);
            ident += 8;
            break;
        case NODE_subprogram_declarations:
            printf("%s/SUBPROGRAM_DECLARATIONS\n", blank);
            ident += 8;
            break;
        case NODE_subprogram_head:
            printf("%s/SUBPROGRAM_HEAD\n", blank);
            ident += 8;
            break;
        case NODE_arguments:
            printf("%s/ARGUMENTS\n", blank);
            ident += 8;
            break;
        case NODE_parameter_list:
            printf("%s/PARAMETER_LIST\n", blank);
            ident += 8;
            break;
        case NODE_optional_var:
            printf("%s/OPTIONAL_VAR\n", blank);
            ident += 8;
            break;
        case NODE_compound_statement:
            printf("%s/COMPOUND_STATEMENT\n", blank);
            ident += 8;
            break;
        case NODE_optional_statements:
            printf("%s/OPTIONAL_STATEMENTS\n", blank);
            ident += 8;
            break;
        case NODE_statement_list:
            printf("%s/STATEMENT_LIST\n", blank);
            ident += 8;
            break;
        case NODE_statement:
            printf("%s/STATEMENT\n", blank);
            ident += 8;
            break;
        case NODE_variable:
            printf("%s/VARIABLE\n", blank);
            ident += 8;
            break;
        case NODE_tail:
            printf("%s/TAIL\n", blank);
            ident += 8;
            break;
        case NODE_procedure_statement:
            printf("%s/PROCEDURE_STATEMENT\n", blank);
            ident += 8;
            break;
        case NODE_expression_list:
            printf("%s/EXPRESSION_LIST\n", blank);
            ident += 8;
            break;
        case NODE_expression:
            printf("%s/EXPR\n", blank);
            ident += 8;
            break;
        case NODE_simple_expression:
            printf("%s/SIMPLE_EXPRESSION\n", blank);
            ident += 8;
            break;
        case NODE_term:
            printf("%s/TERM\n", blank);
            ident += 8;
            break;
        case NODE_factor:
            printf("%s/FACTOR\n", blank);
            ident += 8;
            break;
        case NODE_num:
            printf("%s/NUM\n", blank);
            ident += 8;
            break;
        case NODE_addop:
            printf("%s/ADD_OPERATOR\n", blank);
            ident += 8;
            break;
        case NODE_mulop:
            printf("%s/MUL_OPERATOR\n", blank);
            ident += 8;
            break;
        case NODE_relop:
            printf("%s/REL_OPERATOR\n", blank);
            ident += 8;
            break;
        
        /*case NODE_INT:
            printf("%s%d\n", blank, node->iValue);
            ident += 8;
            break;*/
        /**/
        case LAMBDA:
            printf("%s/LAMBDA\n", blank);
            break;
        /**/
        case PLUS:
            printf("%s/PLUS\n", blank);
            break;
        case MINUS:
            printf("%s/MINUS\n", blank);
            break;
        case STAR:
            printf("%s/STAR\n", blank);
            break;
        case SLASH:
            printf("%s/SLASH\n", blank);
            break;
        case AND:
            printf("%s/AND\n", blank);
            break;
        case ARRAY:
            printf("%s/ARRAY\n", blank);
            break;
        case CASE:
            printf("%s/CASE\n", blank);
            break;
        case CONST:
            printf("%s/CONST\n", blank);
            break;
        case DIV:
            printf("%s/DIV\n", blank);
            break;
        case DO:
            printf("%s/DO\n", blank);
            break;
        case DOWNTO:
            printf("%s/DOWNTO\n", blank);
            break;
        case ELSE:
            printf("%s/ELSE\n", blank);
            break;
        case END:
            printf("%s/END\n", blank);
            break;
        case EXTERNAL:
            printf("%s/EXTERNAL\n", blank);
            break;
        case FOR:
            printf("%s/FOR\n", blank);
            break;
        case FORWARD:
            printf("%s/FORWARD\n", blank);
            break;
        case FUNCTION:
            printf("%s/FUNCTION\n", blank);
            break;
        case GOTO:
            printf("%s/GOTO\n", blank);
            break;
        case IF:
            printf("%s/IF\n", blank);
            break;
        case IN:
            printf("%s/IN\n", blank);
            break;
        case LABEL:
            printf("%s/LABEL\n", blank);
            break;
        case MOD:
            printf("%s/MOD\n", blank);
            break;
        case NIL:
            printf("%s/NIL\n", blank);
            break;
        case NOT:
            printf("%s/NOT\n", blank);
            break;
        case OF:
            printf("%s/OF\n", blank);
            break;
        case OR:
            printf("%s/OR\n", blank);
            break;
        case OTHERWISE:
            printf("%s/OTHERWISE\n", blank);
            break;
        case PACKED:
            printf("%s/PACKED\n", blank);
            break;
        case PBEGIN:
            printf("%s/PBEGIN\n", blank);
            break;
        case PFILE:
            printf("%s/PFILE\n", blank);
            break;
        case PROCEDURE:
            printf("%s/PROCEDURE\n", blank);
            break;
        case PROGRAM:
            printf("%s/PROGRAM\n", blank);
            break;
        case RECORD:
            printf("%s/RECORD\n", blank);
            break;
        case REPEAT:
            printf("%s/REPEAT\n", blank);
            break;
        case SET:
            printf("%s/SET\n", blank);
            break;
        case THEN:
            printf("%s/THEN\n", blank);
            break;
        case TO:
            printf("%s/TO\n", blank);
            break;
        case TYPE:
            printf("%s/TYPE\n", blank);
            break;
        case UNTIL:
            printf("%s/UNTIL\n", blank);
            break;
        case VAR:
            printf("%s/VAR\n", blank);
            break;
        case WHILE:
            printf("%s/WHILE\n", blank);
            break;
        case WITH:
            printf("%s/WITH\n", blank);
            break;
        case IDENTIFIER:
            printf("%s/IDENTIFIER\n", blank);
            break;
        case ASSIGNMENT:
            printf("%s/ASSIGNMENT\n", blank);
            break;
        case CHARACTER:
            printf("%s/CHARACTER\n", blank);
            break;
        case CHAR_STRING:
            printf("%s/CHAR_STRING\n", blank);
            break;
        case COLON:
            printf("%s/COLON\n", blank);
            break;
        case COMMA:
            printf("%s/COMMA\n", blank);
            break;
        case DIGSEQ:
            printf("%s/DIGSEQ\n", blank);
            break;
        case DOT:
            printf("%s/DOT\n", blank);
            break;
        case DOTDOT:
            printf("%s/DOTDOT\n", blank);
            break;
        case EQUAL:
            printf("%s/EQUAL\n", blank);
            break;
        case GE:
            printf("%s/GE\n", blank);
            break;
        case GT:
            printf("%s/GT\n", blank);
            break;
        case LBRAC:
            printf("%s/LBRAC\n", blank);
            break;
        case LE:
            printf("%s/LE\n", blank);
            break;
        case LPAREN:
            printf("%s/LPAREN\n", blank);
            break;
        case LT:
            printf("%s/LT\n", blank);
            break;
        case MINUS:
            printf("%s/MINUS\n", blank);
            break;
        case NOTEQUAL:
            printf("%s/NOTEQUAL\n", blank);
            break;
        case PLUS:
            printf("%s/PLUS\n", blank);
            break;
        case RBRAC:
            printf("%s/RBRAC\n", blank);
            break;
        case REALNUMBER:
            printf("%s/REALNUMBER\n", blank);
            break;
        case RPAREN:
            printf("%s/RPAREN\n", blank);
            break;
        case SEMICOLON:
            printf("%s/SEMICOLON\n", blank);
            break;
        case SLASH:
            printf("%s/SLASH\n", blank);
            break;
        case STAR:
            printf("%s/STAR\n", blank);
            break;
        case STARSTAR:
            printf("%s/STARSTAR\n", blank);
            break;
        case UPARROW:
            printf("%s/UPARROW\n", blank);
            break;
        case INTEGER:
            printf("%s/INTEGER\n", blank);
            break;
        case REAL:
            printf("%s/REAL\n", blank);
            break;
        case STRING:
            printf("%s/STRING\n", blank);
            break;
            
            
        default:
            printf("%sdefault:%d\n", blank, node->nodeType);
          break;
    }

    struct nodeType *child = node->child;
    if(child != NULL) {
        do {
            printTree(child, ident);
            child = child->rsibling;
        } while(child != node->child);
    }
}

