.class public foo
.super java/lang/Object

.field public static ff [I
.field public static d [[F
.field public static e [[F
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
	multianewarray [[F 2
	putstatic foo/d [[F
	bipush 3
	bipush 10
	multianewarray [[F 2
	putstatic foo/e [[F
	ldc 0.0
	putstatic foo/c F
	ldc 0
	putstatic foo/a I
	ldc 0
	putstatic foo/b I
	return
.end method

.method public static ss([[FI)I
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
	return
.end method

