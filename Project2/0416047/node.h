#ifndef __NODE_H__
#define __NODE_H__

struct nodeType;
enum ntype {
    /*VALUE_INVALID,             
    NODE_INT,                   
    NODE_TERM,              
    NODE_PROGRAM,                     
    NODE_STMT,
    NODE_EXPR,           
    OP_ADD, 
    OP_SUB, 
    OP_MUL, 
    OP_DIV*/
    
    AND,
    ARRAY,
    CASE,
    CONST,
    DIV,
    DO,
    DOWNTO,
    ELSE,
    END,
    EXTERNAL,
    FOR,
    FORWARD,
    FUNCTION,
    GOTO,
    IF,
    IN,
    LABEL,
    MOD,
    NIL,
    NOT,
    OF,
    OR,
    OTHERWISE,
    PACKED,
    PBEGIN,
    PFILE,
    PROCEDURE,
    PROGRAM,
    RECORD,
    REPEAT,
    SET,
    THEN,
    TO,
    TYPE,
    UNTIL,
    VAR,
    WHILE,
    WITH,
    IDENTIFIER,
    ASSIGNMENT,
    CHARACTER,
    CHAR_STRING,
    COLON,
    COMMA,
    DIGSEQ,
    DOT,
    DOTDOT,
    EQUAL,
    GE,
    GT,
    LBRAC,
    LE,
    LPAREN,
    LT,
    MINUS,
    NOTEQUAL,
    PLUS,
    RBRAC,
    REALNUMBER,
    RPAREN,
    SEMICOLON,
    SLASH,
    STAR,
    STARSTAR,
    UPARROW,
    INTEGER,
    REAL,
    STRING
};

// #include "symtab.h"
struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int arraydepth;
    struct nodeType *ref;

    /* Values for general use */
    int iValue;
    double rValue;
    char valueValid;
    char *string;
    
    /* Indicates which OP */
    char op;

};

struct nodeType* newNode(int type);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif

