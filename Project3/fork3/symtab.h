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

struct SymTableEntry
{
  char name[100];
  enum StdType type;
  int arraydepth;
  int idxstart;
  int idxend;
  int isFunction;
  int scope;
  int paramNo;
  char valueValid;
};

struct SymTable
{
  int size;
  struct SymTableEntry entries[100];
};

extern struct SymTable SymbolTable;

#include "node.h"

void semanticCheck(struct nodeType* node);
void printTable();

#endif
