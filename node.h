#ifndef __NODE_H__
#define __NODE_H__

/*  
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: Construct abstract syntax tree
 *  This is the header .h file
 *  Writer_ID: 0416047
 */

#include "y.tab.h"
#include "symtab.h"

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

#define VALUE_INVALID   0
#define VALUE_I_VALID   1
#define VALUE_R_VALID   2

enum type
{
  NODE_INT,
  NODE_ARRAY,
  NODE_OP,
  NODE_SUBPROGRAM,
  NODE_IDLIST,
  NODE_DECLARATIONS,
  NODE_SYM_REF,
  NODE_UOP,
  NODE_TOKEN,
  NODE_STDTYPE,
  NODE_SUBPROGRAMS,
  NODE_SUBPROGRAMHEAD,
  NODE_OPTIONALVAR,	
  NODE_COMPOUND,
  NODE_STMTLIST,
  NODE_OPTIONALSTMT,
  NODE_ARGUMENTS,
  NODE_PARAMLIST,
  NODE_VARIABLE,
  NODE_CALLFUNC,
  NODE_PROCEDURESTMT,
  NODE_SIMPLEEXPR,
  NODE_STMT,
  NODE_TERM,
  NODE_EXPR,
  NODE_EXPRLIST,
  NODE_ID,
  NODE_FACTOR,
  NODE_TAIL,
  NODE_ADDOP,
  NODE_MULOP,
  NODE_RELOP,
  NODE_NUM,
  NODE_PROG
};

struct nodeType
{
  int nodeType;
  struct nodeType *parent;
  struct nodeType *child;
  struct nodeType *lsibling;
  struct nodeType *rsibling;
  int child_num;

  int line_no;
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
  enum StdType valueType;
  struct SymTableEntry *entry;

  /* Items for Function */
  int isFunction;
  int paramNo;
};

struct nodeType* newNode(int type, int line_no);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);
char* printNode(struct nodeType *node);

#endif
