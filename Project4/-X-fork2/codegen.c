#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symtab.h"
#include "codegen.h"

void InitialFile()
{
	fprintf(output_file, ".class public foo\n");
	fprintf(output_file, ".super java/lang/Object\n");
}

void GenGlobalVar(struct nodeType *global_var, struct nodeType *type)
{
	if(type->nodeType == INTEGER)
  {
		fprintf(output_file, ".field public static %s %s\n", global_var->string, "I");
	}
	else if(type->nodeType == REAL)
  {
		fprintf(output_file, ".field public static %s %s\n", global_var->string, "F");
	}
}