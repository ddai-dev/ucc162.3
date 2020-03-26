#ifndef	DECL_H
#define	DECL_H
#include "lex.h"
#include "expr.h"
// 因此所有的声明都是以 int 开始的，之后再跟上声明符 Declarator
// 在声明符 Declarator 中，我们可以进一步指定要声 明的标志符为指针类型、数组类型或者函数类型
AstNodePtr Declaration(void);
void VisitDeclarationNode(AstNodePtr pNode);
#endif
