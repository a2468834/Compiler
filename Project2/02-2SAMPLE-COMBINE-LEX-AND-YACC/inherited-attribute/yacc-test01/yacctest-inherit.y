%{
/*
 * grammar.y
 */

 #include <stdio.h>

 typedef struct VStype {
     int ans;
     int thus;
 } VStypetype;

     /* Called by yyparse on error.  */
     void
     yyerror (char const *s)
     {
        extern char *yytext;
        extern int lineCount;
        fprintf (stderr, "%s: at line %d symbol'%s'\n", s,lineCount,yytext);
     }

%}

%union {
     int an;
     struct VStype vsn;   
     /* VStypetype vsn; */
 }

%type<an>  E V NUM S

%type<vsn>  VS

%token LPAREN NUM RPAREN PROD PLUS EEOOFF eof

%start S

%%

S :  V 
     { $$ = $1;
       fprintf(stderr, "Final answer is %d.\n", $$);  };

E : PLUS V V 
     { $$ = $2 + $3;   } ;

E : PROD VS
     { $$ = $2.ans ;  } ;

V : NUM
     { $$ = $1;    } 
    | LPAREN E RPAREN
     { $$ = $2;  } ;

VS : V VS
     { $2.thus = $$.thus * $1; 
       $$.ans = $2.ans;
       fprintf(stderr, "333  answer is %d.\n", $$.thus);  } 
    | 
     { $$.ans = $$.thus;  /* 12345 is an arbitrary number. */
       fprintf(stderr, "444  answer is %d.\n", $$.thus);  } ;

%%

int main(int argc, char** argv) {
    int res;
    
    fprintf(stderr, "open file.\n");
    if(argc>1 && freopen(argv[1],"r",stdin)==NULL){
        exit(1);
    }
    
    fprintf(stderr, "call yyparse\n");
    res = yyparse();
    fprintf(stderr, "after call yyparse, res = %d.\n", res);
    
    if (res==0)
        fprintf(stderr, "SUCCESS\n");
    else
        fprintf(stderr, "ERROR\n");
}

 #include "lex.yy.c"
