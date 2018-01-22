#include "codegen.h"

void CodeGen(struct nodeType *ASTROOT)
{
  struct nodeType *declarations_node = nthChild(3, ASTROOT);
  struct nodeType *subprogram_declarations_node = nthChild(4, ASTROOT);

  InitFile();

  GenGlobalVar(declarations_node);

  GenStdInit();
  GenGlobalInit(declarations_node);

  GenMethod(subprogram_declarations_node);

  GenMainMethod();

}

char* GetArrayDimAndType(struct nodeType *array_node)
{
  char *result = (char*)malloc(100*sizeof(char));
  
  if(array_node->nodeType != ARRAY)
  {
    strcat(result, "ERROR");
    return result;
  }

  // if array_node's nodeType is ARRAY, it means that it's at least a 1D array
  else
  {
    strcat(result, "[");
    
    struct nodeType *index_start = nthChild(1, array_node);
    struct nodeType *index_end = nthChild(2, array_node);
    struct nodeType *deeper_array_node = nthChild(3, array_node);

    while(deeper_array_node->child_num != 0)
    {
      strcat(result, "[");

      array_node = deeper_array_node;

      index_start = nthChild(1, array_node);
      index_end = nthChild(2, array_node);
      deeper_array_node = nthChild(3, array_node);
    }

    if(deeper_array_node->nodeType == INTEGER)strcat(result, "I");
    else strcat(result, "F");

    return result;
  }
}

void InitFile()
{
	fprintf(output_file, ".class public foo\n");
	fprintf(output_file, ".super java/lang/Object\n\n");
}

void GenGlobalVar(struct nodeType *parent)
{
  struct nodeType *identifier_list_node;
  struct nodeType *identifier_type_node;
  struct nodeType *next_parent;

  do{
    identifier_list_node = nthChild(1, parent);
    identifier_type_node = nthChild(2, parent);
    next_parent = nthChild(3, parent);

    if(identifier_type_node->nodeType == INTEGER)
    {
      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        struct nodeType *id_list_child = nthChild(i+1, identifier_list_node);
        fprintf(output_file, ".field public static %s I\n", id_list_child->string);
      }
    }

    else if(identifier_type_node->nodeType == REAL)
    {
      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        struct nodeType *id_list_child = nthChild(i+1, identifier_list_node);
        fprintf(output_file, ".field public static %s F\n", id_list_child->string);
      }
    }

    else if(identifier_type_node->nodeType == ARRAY)
    {
      char *array_tag = (char*)malloc(100*sizeof(char));
      array_tag = GetArrayDimAndType(identifier_type_node);

      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        struct nodeType *id_list_child = nthChild(i+1, identifier_list_node);
        fprintf(output_file, ".field public static %s %s\n", id_list_child->string, array_tag);
      }
    }

    // do the same procedure in the deeper declarations node
    parent = next_parent;
  }while(next_parent->child_num == 3);

  fprintf(output_file, "\n");
}

void GenStdInit()
{
  fprintf(output_file, ".method public <init>()V\n");
  fprintf(output_file, "\taload_0\n");
  fprintf(output_file, "\tinvokenonvirtual java/lang/Object/<init>()V\n");
  fprintf(output_file, "\treturn\n");
  fprintf(output_file, ".end method\n\n");
}

void GenGlobalInit(struct nodeType *parent)
{
  fprintf(output_file, ".method public static vinit()V\n");
  fprintf(output_file, "\t.limit locals 100\n");
  fprintf(output_file, "\t.limit stack 100\n");

  struct nodeType *identifier_list_node;
  struct nodeType *identifier_type_node;
  struct nodeType *next_parent;

  do{
    identifier_list_node = nthChild(1, parent);
    identifier_type_node = nthChild(2, parent);
    next_parent = nthChild(3, parent);

    if(identifier_type_node->nodeType == INTEGER)
    {
      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        struct nodeType *id_list_child = nthChild(i+1, identifier_list_node);
        fprintf(output_file, "\tldc 0\n");
        fprintf(output_file, "\tputstatic foo/%s I\n", id_list_child->string);
      }
    }

    else if(identifier_type_node->nodeType == REAL)
    {
      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        struct nodeType *id_list_child = nthChild(i+1, identifier_list_node);
        fprintf(output_file, "\tldc 0.0\n");
        fprintf(output_file, "\tputstatic foo/%s F\n", id_list_child->string);
      }
    }

    else if(identifier_type_node->nodeType == ARRAY)
    {
      char *array_tag = (char*)malloc(100*sizeof(char));
      array_tag = GetArrayDimAndType(identifier_type_node);

      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        // declare 'array_node' just because in order to prevent 
        // 'identifier_type_node' from getting dirty
        struct nodeType *array_node = identifier_type_node;

        for(int j=0; j<identifier_type_node->arraydepth; j++)
        {
          struct nodeType *index_start = nthChild(1, array_node);
          struct nodeType *index_end = nthChild(2, array_node);
          struct nodeType *deeper_array_node = nthChild(3, array_node);

          int index_range = index_end->iValue - index_start->iValue + 1;

          fprintf(output_file, "\tbipush %d\n", index_range);
          array_node = deeper_array_node;
        }

        struct nodeType *id_list_child = nthChild(i+1, identifier_list_node);
        fprintf(output_file, "\tmultianewarray %s %d\n", array_tag, identifier_type_node->arraydepth);
        fprintf(output_file, "\tputstatic foo/%s %s\n", id_list_child->string, array_tag);
      }
    }

    // do the same procedure in the deeper declarations node
    parent = next_parent;
  }while(next_parent->child_num == 3);

  fprintf(output_file, "\treturn\n");
  fprintf(output_file, ".end method\n\n");
}

void GenMethod(struct nodeType* parent)
{
  for(int i=0; i<parent->child_num; i++)
  {
    struct nodeType *FUNCTION_node = nthChild(i+1, parent);
    char *method_info = (char*)malloc(250*sizeof(char));

    method_info = GenMethodStart(FUNCTION_node);
    //printf("%s\n", method_info);
    //GenExpr();
    GenMethodEnd(FUNCTION_node);
  }
}

char* GenMethodStart(struct nodeType *parent)
{
  struct nodeType *method_name_node = nthChild(1, parent);
  struct nodeType *arguments_node = nthChild(2, parent);
  struct nodeType *return_type_node = nthChild(3, parent);

  char *method_name = (char*)malloc( strlen(method_name_node->string)+1 );
  // each method has at most 200 parameters
  char *parameter_type_list = (char*)malloc(200*sizeof(char));
  char return_type[1] = {0};

  strcpy(method_name, method_name_node->string);

  if(return_type_node->nodeType == INTEGER)return_type[0] = 'I';
  else if(return_type_node->nodeType == REAL)return_type[0] = 'F';
  // actually, a method's type of return value should be either "I" or "F"
  else return_type[0] = 'V';

  // let's start to get the list of all parameters' type
  if(arguments_node->child_num != 0)
  {
    // if arguments_node has a child, it means that it has at least a 
    // identifier_list and a identifier_type
    struct nodeType *parameter_list_node = arguments_node->child;

    struct nodeType *identifier_list_node = nthChild(1, parameter_list_node);
    struct nodeType *identifier_type_node = nthChild(2, parameter_list_node);

    for(int i=0; i<identifier_list_node->child_num; i++)
    {
      if(identifier_type_node->nodeType == INTEGER)strcat(parameter_type_list, "I");
      else if(identifier_type_node->nodeType == REAL)strcat(parameter_type_list, "F");
      else if(identifier_type_node->nodeType == ARRAY)
      {
        char *array_tag = (char*)malloc(100*sizeof(char));
        array_tag = GetArrayDimAndType(identifier_type_node);
        strcat(parameter_type_list, array_tag);
      }
      else strcat(parameter_type_list, "F");
    }

    while(parameter_list_node->child_num == 3)
    {
      // do the same procedure in the deeper parameter_list node
      parameter_list_node = nthChild(3, parameter_list_node);

      identifier_list_node = nthChild(1, parameter_list_node);
      identifier_type_node = nthChild(2, parameter_list_node);

      for(int i=0; i<identifier_list_node->child_num; i++)
      {
        if(identifier_type_node->nodeType == INTEGER)strcat(parameter_type_list, "I");
        else if(identifier_type_node->nodeType == REAL)strcat(parameter_type_list, "F");
        else if(identifier_type_node->nodeType == ARRAY)
        {
          char *array_tag = (char*)malloc(100*sizeof(char));
          array_tag = GetArrayDimAndType(identifier_type_node);
          strcat(parameter_type_list, array_tag);
        }
        else strcat(parameter_type_list, "F");
      }
    }
  }
  else
  {
    strcat(parameter_type_list, "\0");
  }

  fprintf(output_file, ".method public static %s(%s)%s\n", method_name, parameter_type_list, return_type);
  fprintf(output_file, "\t.limit locals 100\n");
  fprintf(output_file, "\t.limit stack 100\n");

  char *method_info = (char*)malloc( (strlen(parameter_type_list)+strlen(return_type)+3)*sizeof(char) );
  strcat(method_info, parameter_type_list);
  strcat(method_info, "/");
  strcat(method_info, return_type);
  return method_info;
}

void GenMethodEnd(struct nodeType *parent)
{
  struct nodeType *return_type_node = nthChild(3, parent);

  switch(return_type_node->nodeType)
  {
    case INTEGER:
      fprintf(output_file, "\tireturn\n");
      fprintf(output_file, ".end method\n\n");
      break;
    case REAL:
      fprintf(output_file, "\tfreturn\n");
      fprintf(output_file, ".end method\n\n");
      break;
    default:
      fprintf(output_file, "\treturn\n");
      fprintf(output_file, ".end method\n\n");
      break;
  }
}

void GenMainMethod()
{
  GenMainMethodStart();
  //GenExpr
  GenMainMethodEnd();
}

void GenMainMethodStart()
{
  fprintf(output_file, ".method public static main([Ljava/lang/String;)V\n");
  fprintf(output_file, "\t.limit locals 100\n");
  fprintf(output_file, "\t.limit stack 100\n");
  fprintf(output_file, "\tinvokestatic foo/vinit()V\n");
}

void GenMainMethodEnd()
{
  fprintf(output_file, "\treturn\n");
  fprintf(output_file, ".end method\n\n");
}