#ifndef _STACK_CALC_
#define _STACK_CALC_

#include "linkedstack.h"

void	calcExpr(LinkedStack *stack);
int		pushLSExprToken(LinkedStack* pStack, ExprToken data);
void	convertInfixToPostfix(LinkedStack *stack);
int		inStackPrecedence(Precedence oper);
int		outStackPrecedence(Precedence oper);
void	printToken(ExprToken element);

#endif
