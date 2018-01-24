#ifndef __CODEGENE_H__
#define __CODEGENE_H__

extern int line_no; /* declared in scaner.l */
extern FILE *output_file;/* declared in parser.y */


void InitialFile();
void GenGlobalVar(struct nodeType *global_var, struct nodeType *type);

#endif
