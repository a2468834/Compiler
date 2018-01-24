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
	a := 4;
	a := 2*-3/(a-1)+a*(4-1);//10
	writeln(a);
	
	c := 3.14;
	c := 2.2*-3.3/(c-1.1)+c*(4.4-1.1);//6.803178
	writeln(c);
	
	d[3] := 3.3;
	c := d[3];//3.3
	writeln(c);

	c := c+d[3];//6.6
	writeln(c);
	
	e[3][4][5] := 2*-3/(2-1)+-5*(4-1);//-21
	a := a+e[3][4][5];//-11
	writeln(a);

	a := 5;
	a := a+6+a+a+a;//26
	writeln(a);
END.


