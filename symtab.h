#ifndef __SYMTAB_H___
#define __SYMTAB_H___

/*  
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: Construct symbol table and do semantic checking
 *  This is the header .h file
 *  Writer_ID: 0416047
 */

enum StdType
{
  TypeInt,
  TypeReal,
  TypeString,
  TypeFunc,
  TypeProc
};

struct index_info
{
  int depth;
  int start;
  int end;
  struct index *deeper;
}

struct SymTableEntry
{
  char name[200];
  enum StdType type;
  int arraydepth;
  int idxstart;
  int idxend;
  // maximum depth of array 100
  struct index_info index[100];
  int isFunction;
  char owned_by[200];// a function name which owns this variable
  int scope;
  int paramNum;
  int line_no;
};

struct SymTable
{
  // the actual number of entry which have meaningful content
  int size;
  // maximum number of entry in symbol table is 500
  struct SymTableEntry entries[500];
};

#include "node.h"

extern struct SymTable SymbolTable;

struct SymTableEntry* findSymbol(char *s, int itsscope);
struct SymTableEntry* findSymbol_noscope(char *s);
void setParamNum(char *s, int paramNum);

struct SymTableEntry* addVariable(
  char *s,
  enum StdType type,
  int arraydepth,
  int idxstart,
  int idxend,
  int isFunction,
  int itsscope,
  int line_no);

struct nodeType* nthChild(int n, struct nodeType *node);
void semanticCheck(struct nodeType* node);
void printTable();

#endif
