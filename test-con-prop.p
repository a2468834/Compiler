PROGRAM aa(input, output, error);
VAR a, b: INTEGER;
VAR c: REAL;
VAR d: array [ 3 .. 5 ] of REAL;
VAR e: array [ 3 .. 5 ] of array [ 1 .. 10 ] of array [ 3 .. 6 ] of INTEGER;
VAR ff: array [ 1 .. 20 ] of INTEGER;

FUNCTION ss (bb, hh: array [ 1 .. 10 ] of REAL; jj, pp:INTEGER): INTEGER;
VAR aa: REAL;
VAR kk: REAL;
BEGIN
	a := a+1;
	ss := a+b; // No error since a, b are global variable
END;

FUNCTION xx (zz: array [ 1 .. 10 ] of array [ 1 .. 10 ] of REAL): INTEGER;
VAR aa: REAL;
var kk: INTEGER;
BEGIN
	xx := a+b // No error since a, b are global variable
END;

BEGIN
	a := 1;
	a := 2*-3/(a-1)+a*(4-1);
	//c := 3.1415;
	a := a+a+1;
	//e[3][4][5] := 2*-3/(2-1)+-5*(4-1);
	//a := 4;

	//a := 5;

	//a := 6;

	a := 2+1;
	//b := 8;
	//a := 7;
	writeln(a);

	writeln(c);
	//b := 4;
	
	//d[3] := 9.99;
END.


