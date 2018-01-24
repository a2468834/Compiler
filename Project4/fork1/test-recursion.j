.class public foo
.super java/lang/Object

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
	ldc 0.0
	putstatic foo/c F
	ldc 0
	putstatic foo/a I
	ldc 0
	putstatic foo/b I
	return
.end method

.method public static fact(I)I
	.limit locals 100
	.limit stack 100
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic foo/vinit()V
	return
.end method

