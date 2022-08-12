#ifndef _STACK_CALC_
#define _STACK_CALC_

# include <stdlib.h>
# include "float.h"
# include "linkedstack.h"


int		pushLS(LinkedStack* pStack, ExprToken element);
void	calcExpr(char* str);
float	simple_cal(float x, char oper, float y);
int		pushLSExprToken(LinkedStack* pStack, ExprToken data);
void	convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
int		inStackPrecedence(char oper);
int		outStackPrecedence(char oper);
void	printToken(ExprToken element);
ExprToken	*popLS(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif