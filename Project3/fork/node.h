#ifndef __NODE_H__
#define __NODE_H__

struct nodeType;

#define VALUE_INVALID   0
#define VALUE_I_VALID   1
#define VALUE_R_VALID   2

#define NODE_prog 1
#define NODE_identifier_list 2
#define NODE_declarations 3
#define NODE_subprogram_declarations 4
#define NODE_compound_statement 5
#define NODE_type 6
#define NODE_standard_type 7
#define NODE_num 8
#define NODE_subprogram_declaration 9
#define NODE_subprogram_head 10
#define NODE_arguments 11
#define NODE_parameter_list 12
#define NODE_optional_var 13
#define NODE_optional_statements 14
#define NODE_statement_list 15
#define NODE_statement 16
#define NODE_variable 17
#define NODE_expression 18
#define NODE_procedure_statement 19
#define NODE_tail 20
#define NODE_expression_list 21
#define NODE_simple_expression 22
#define NODE_addop 23
#define NODE_mulop 24
#define NODE_relop 25
#define NODE_term 26
#define NODE_factor 27

#define NODE_VAR_OR_PROC    99
#define NODE_ERROR          100
#define NODE_EMPTY          101

#define OP_ADD  1
#define OP_SUB  2
#define OP_MUL  3
#define OP_DIV  4
#define OP_GT   5
#define OP_LT   6
#define OP_EQ   7
#define OP_GE   8
#define OP_LE   9
#define OP_NE   10
#define OP_NOT  11

#include "symtab.h"
struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    int iValue;
    double rValue;
    char valueValid;

    char *string;

    char op;

    enum StdType valueType;
    struct SymTableEntry *entry;
};

struct nodeType* newNode(int type);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif

