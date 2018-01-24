.class public foo
.super java/lang/Object

.field public static ff [I
.field public static e [[[I
.field public static d [F
.field public static c F
.field public static a I
.field public static b I

.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static vinit()V
	.limit locals 100
	.limit stack 100
	bipush 20
	multianewarray [I 1
	putstatic foo/ff [I
	bipush 3
	bipush 10
	bipush 4
	multianewarray [[[I 3
	putstatic foo/e [[[I
	bipush 3
	multianewarray [F 1
	putstatic foo/d [F
	ldc 0.0
	putstatic foo/c F
	ldc 0
	putstatic foo/a I
	ldc 0
	putstatic foo/b I
	return
.end method

.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic foo/vinit()V
	ldc 4
	putstatic foo/a I
	ldc 2
	ldc -3
	imul
	getstatic foo/a I
	ldc 1
	isub
	idiv
	getstatic foo/a I
	ldc 4
	ldc 1
	isub
	imul
	iadd
	putstatic foo/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/a I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 3.140000
	putstatic foo/c F
	ldc 2.200000
	ldc -3.300000
	fmul
	getstatic foo/c F
	ldc 1.100000
	fsub
	fdiv
	getstatic foo/c F
	ldc 4.400000
	ldc 1.100000
	fsub
	fmul
	fadd
	putstatic foo/c F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/c F
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic foo/d [F
	ldc 3
	ldc 3
	isub
	ldc 3.300000
	fastore
	getstatic foo/d [F
	ldc 3
	ldc 3
	isub
	faload
	ldc 1.100000
	fadd
	getstatic foo/c F
	fadd
	putstatic foo/c F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/c F
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic foo/c F
	getstatic foo/d [F
	ldc 3
	ldc 3
	isub
	faload
	fadd
	putstatic foo/c F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/c F
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic foo/e [[[I
	ldc 4
	ldc 3
	isub
	aaload
	ldc 4
	ldc 1
	isub
	aaload
	ldc 5
	ldc 3
	isub
	ldc -21
	iastore
	getstatic foo/a I
	getstatic foo/e [[[I
	ldc 4
	ldc 3
	isub
	aaload
	ldc 4
	ldc 1
	isub
	aaload
	ldc 5
	ldc 3
	isub
	iaload
	iadd
	putstatic foo/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/a I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 5
	putstatic foo/a I
	getstatic foo/a I
	ldc 6
	iadd
	getstatic foo/a I
	iadd
	getstatic foo/a I
	iadd
	getstatic foo/a I
	iadd
	putstatic foo/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/a I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method

