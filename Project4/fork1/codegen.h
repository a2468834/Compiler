#ifndef __CODEGENE_H__
#define __CODEGENE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "symtab.h"

extern int line_no; /* declared in scaner.l */
extern FILE *output_file;/* declared in parser.y */

char* GetArrayDimAndType(struct nodeType *array_node);
// evaluate integer expression which is represented by binary expression tree
int EvaIntExpr(struct nodeType *node);
double EvaRealExpr(struct nodeType *node);
// simple expression is a expression that contains no variable just only numbers
bool CheckSimpleExpr(struct nodeType *node);

void CodeGen(struct nodeType *ASTROOT);

// initialize the output file which is java bytecode
void InitFile();
void GenGlobalVar(struct nodeType *parent);
// generate standard initializer
void GenStdInit();
// generate global variables' initializer
void GenGlobalInit(struct nodeType *parent);

void GenMethod(struct nodeType *parent);
void GenMethodStart(struct nodeType *parent);
void GenMethodEnd(struct nodeType *parent);

void GenMainMethod(struct nodeType *main_method);
void GenMainMethodStart();
void GenMainMethodEnd();

void GenLoadArray(struct nodeType *array);

void GenWriteLine(struct nodeType *writeln);

#endif
