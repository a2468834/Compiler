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
#include <stdbool.h>
#include "y.tab.h"
#include "symtab.h"

// use for op
#define OP_ADD   1
#define OP_SUB   2
#define OP_MUL   3
#define OP_DIV   4
#define OP_GT    5
#define OP_LT    6
#define OP_EQ    7
#define OP_GE    8
#define OP_LE    9
#define OP_NE    10
#define OP_NOT   11
#define OP_MINUS 12

// use for valueValid
#define VALUE_INVALID  0
#define VALUE_I_VALID  1
#define VALUE_R_VALID  2

enum type
{
  /*
  NODE_OP, => NODE_operator
  NODE_SUBPROGRAM, => NODE_subprogram_declarations
  NODE_IDLIST, => NODE_identifier_list
  NODE_DECLARATIONS, => NODE_declarations
  NODE_SUBPROGRAMS, => NODE_subprogram_declarations
  NODE_OPTIONALVAR, => NODE_optional_var
  NODE_STMTLIST, => NODE_statement_list
  NODE_ARGUMENTS, => NODE_arguments
  NODE_PARAMLIST, => NODE_parameter_list
  NODE_STMT, => NODE_statement
  NODE_EXPRLIST, => NODE_expression_list
  NODE_TAIL, => NODE_tail
  NODE_PROG, => NODE_prog

  NODE_UOP, => deleted

  NODE_SYM_REF, => never used
  NODE_TOKEN, => never used
  NODE_STDTYPE, => never used
  NODE_INT, => never used
  NODE_ARRAY, => never used  
  NODE_SUBPROGRAMHEAD, => never used
  NODE_COMPOUND, => never used
  NODE_OPTIONALSTMT, => never used
  NODE_SIMPLEEXPR, => never used
  NODE_TERM, => never used
  NODE_EXPR, => never used
  NODE_ID, => never used
  NODE_FACTOR, => never used
  NODE_ADDOP, => never used
  NODE_MULOP, => never used
  NODE_RELOP, => never used
  NODE_NUM, => never used
  
  NODE_VARIABLE, => temporarily un-changed
  NODE_CALLFUNC, => temporarily un-changed
  NODE_PROCEDURESTMT, => temporarily un-changed
  */
  NODE_prog,
  NODE_id,
  NODE_identifier_list,
  NODE_declarations,
  NODE_type,
  NODE_standard_type,
  NODE_subprogram_declarations,
  NODE_subprogram_declaration,
  NODE_subprogram_head,
  NODE_compound_statement,
  NODE_procedure_statement,
  NODE_parameter_list,
  NODE_optional_var,
  NODE_optional_statements,
  NODE_statement_list,
  NODE_statement,
  NODE_term,
  NODE_expression,
  NODE_simple_expression,
  NODE_expression_list,
  NODE_variable,
  NODE_tail,
  NODE_arguments,
  NODE_factor,
  NODE_addop,
  NODE_mulop,
  NODE_relop,
  NODE_num,
  NODE_operator,
  NODE_unary_operator,

  NODE_VARIABLE,
  NODE_CALLFUNC,
  NODE_PROCEDURESTMT
};

struct nodeType
{
  // attribute for general use
  int nodeType;
  struct nodeType *parent;
  struct nodeType *child;
  struct nodeType *next;
  struct nodeType *prev;
  char *string; // name
  int line_no;

  // attribute for NODE_TOKEN
  int tokenType;

  // attribute for Array 
  int idxStart;
  int idxEnd;
  int arrayDepth;
  struct nodeType *ref; // link with the deeper array

  // values for general use
  int iValue; // integer value
  double rValue; // real number value
  int valueValid;

  // Indicates which OP
  int op; // operator type
  enum StdType valueType;
  struct SymTableEntry *entry;

  // Items for Function
  bool isFunction;
  //int paramNo;
};

// method
struct nodeType* newNode(int type, int line_no);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif
