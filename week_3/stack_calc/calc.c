#include "stackcalc.h"
#include <stdio.h>
#include <stdlib.h>

int	isOperand(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')')
		return (1);
	else
		return (0);
}

void	calcExpr(char *exp)
{

}

int pushLSExprToken(LinkedStack* pStack, ExprToken data)
{
	if (pushLS(pStack, data))
		return (TRUE);
	else
		return (FALSE);
}

/*
void	convertInfixToPostfix(LinkedStack *stack, int tokenCount)
{
	
}
*/

int inStackPrecedence(Precedence oper)
{
	Precedence	Oper = oper;
	switch(Oper)
	{
		case lparen:
			return (0);
		case rparen:
			return (2);
		case times:
			return (4);
		case divide:
			return (4);
		case plus:
			return (2);
		case minus:
			return (2);
		case operand:
			return (6);
	}
}

int outStackPrecedence(Precedence oper)
{
	Precedence	Oper = oper;
	switch(Oper)
	{
		case lparen:
			return (1);
		case rparen:
			return (0);
		case times:
			return (3);
		case divide:
			return (4);
		case plus:
			return (5);
		case minus:
			return (5);
		case operand:
			return (6);
	}
}

void	printToken(ExprToken element)
{
	printf("===========\n");
	printf("val : %.1f\n", element.value);
	printf("===========\n");
}

int	main(void)
{
	LinkedStack	*stack;
	ExprToken	tmp;

	stack = createLinkedStack();
	tmp.value = 32;
	tmp.oper = operand;
	pushLSExprToken(stack, tmp);
	tmp.value = 20;
	tmp.oper = operand;
	pushLSExprToken(stack, tmp);
	tmp.value = '+';
	tmp.oper = plus;
	pushLSExprToken(stack, tmp);
	calcStack(stack);
}
