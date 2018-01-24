Digit [0-9]
E [Ee]
eol \n
blank [\t]
Letter [A-Za-z]
ILLEGAL [\!#\$\%\?@\\\^`\{\}\[\]~]

%{
  int lineCount = 1;
%}

%%

[0-9][0-9]* { 
    /*  fprintf(stderr, "num...%d.%s.\n", lineCount,yytext);  */
    yylval.an = atoi(yytext);
    return(NUM);
  }
  
\+ {
    /*  fprintf(stderr, "plus...%d.\n", lineCount);  */
    return(PLUS);
  }


\* {
    /*  fprintf(stderr, "prod...%d\n", lineCount);  */
    return(PROD);
  }

\( {
    /*  fprintf(stderr, "lparen...%d\n", lineCount);  */
    return(LPAREN);
  }

\) {
    /*  fprintf(stderr, "rparen...%d\n", lineCount);  */
    return(RPAREN);
  }




[A-Za-z][A-Za-z]* {
    fprintf(stderr, "id...%d.%s.\n", lineCount,yytext);
    /* return(ID); */
  }
  
:= {
    fprintf(stderr, "assign...%d.%s.\n", lineCount,yytext);
    /* return(ASSIGN); */
  }

; { 
    fprintf(stderr, "semi...%d\n", lineCount);
    /* return(SEMICOLON); */
  }

\n { 
    /*  fprintf(stderr, "eol...%d\n", lineCount);  */
    lineCount ++; 
  }

{blank} { 
    fprintf(stderr, "blank...%d\n", lineCount);
    /*   lineCount ++; */
  }

{ILLEGAL}([^\40\t]*)? {
  fprintf(stderr,"Lexical analyzer error at line:%d, %s\n",lineCount,yytext);
  }

%%


/*
int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("abc.def", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    fprintf(stderr, "The %d-th token: %d, %s on line %d.\n", i, tok, yytext, lineCount);
  }
  return(0);
} 
*/ 

yywrap() {
  fprintf(stderr, "end of lexing.\n"); 
  fclose(yyin);
  return(1);
}

