PROGRAM aa(input, output, error);
VAR a, b: INTEGER;
VAR c: REAL;
VAR d, e: array [ 3 .. 5 ] of array [ 1 .. 10 ] of REAL;
VAR ff: array [ 1 .. 20 ] of INTEGER;

FUNCTION ss (bb: array [ 1 .. 10 ] of array [ 1 .. 10 ] of REAL): INTEGER;
VAR aa: REAL;
BEGIN
	a := a+1;
	ss := a+b; // No error since a, b are global variable
END;

FUNCTION xx (zz: array [ 1 .. 10 ] of array [ 1 .. 10 ] of REAL): INTEGER;
VAR aa: INTEGER;
BEGIN
	xx := a+b // No error since a, b are global variable
END;

BEGIN
	a := 3;
	b := 4;
	b := ss;
END.


