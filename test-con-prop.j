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

.method public static ss([F[FII)I
	.limit locals 100
	.limit stack 100
	ireturn
.end method

.method public static xx([[F)I
	.limit locals 100
	.limit stack 100
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic foo/vinit()V
	getstatic foo/e [[[I
	ldc 3
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
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/a I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc 3.300000
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method

