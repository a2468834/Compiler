.class public foo
.super java/lang/Object

.field public static a I

.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	getstatic java/lang/System/out Ljava/io/PrintStream;
	bipush 7
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
