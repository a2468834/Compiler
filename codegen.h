#ifndef __CODEGENE_H__
#define __CODEGENE_H__

extern int line_no; /* declared in scaner.l */
extern FILE *output_file;/* declared in parser.y */

struct method_info
{
	char type;
	bool is_array;
	int array_dim;
	struct *method_info;
};

void CodeGen(struct nodeType *ASTROOT);

// initialize the output file which is java bytecode
void InitFile();
void GenGlobalVar(struct nodeType *parent);
// generate standard initializer
void GenStdInit();
// generate global variables' initializer
void GenGlobalInit(struct nodeType *parent);

void GenMethod(struct nodeType *parent);
char* GenMethodStart(struct nodeType *parent);
void GenMethodEnd(struct nodeType *parent);

char* GetArrayDimAndType(struct nodeType *array_node);

void GenMainMethod();
void GenMainMethodStart();
void GenMainMethodEnd();

#endif
