#include "stack_calc.h"
#include "string.h"
#include "stdio.h"
#include "ctype.h"

void calcExpr(char* str)
{
	int i;
	LinkedStack *stack;

	i = 0;
	stack = createLinkedStack();
	while (str[i])
	{
		if (isdigit(str[i]))
			pushLS(stack, (ExprToken){str[i] - 48, 0, 0});
		else
			pushLS(stack, (ExprToken){simple_cal(popLS(stack)->value, str[i], popLS(stack)->value), 0, 0});
		i++;
	}
	printf("%.1f\n", peekLS(stack)->value);
}

int pushLSExprToken(LinkedStack* pStack, ExprToken data)
{
	if (data.value && !data.type) //푸쉬할지 안할지 우선순위보고 결정하는 조건문 완성
		pushLS(pStack, data);
	else if (data.type && !data.value)
	{
		pushLS(pStack, data);
	}
	return (0);
}

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount)
{
	//뒤집혀있는 스택 가져와서 되돌리면서 괄호없애고 calc
}

int inStackPrecedence(char oper)
{
    if (oper == ')')
		return (5);
	else if (oper == '*' || oper == '/')
		return (2);
	else if (oper == '+' || oper == '-')
		return (1);
	else if (oper == '(')
		return (3);
	else if ('0' <= oper && oper <= '9')
    	return (4);
	return (-1);
}

int outStackPrecedence(char oper)
{
    if (oper == '+' || oper == '-')
		return (1);
	else if (oper == '*' || oper == '/')
		return (2);
	else if (oper == '(' || oper == ')')
		return (4);
	else if ('0' <= oper && oper <= '9')
		return (3);
	return (-1);
}

void printToken(ExprToken element)
{
	printf("================\n");
	printf("ExprToken의 value : %.1f\n", element.value);
	printf("================\n");
}

float		simple_cal(float x, char oper, float y)
{
	if (oper == '+')
		return (x + y);
	else if (oper == '-')
		return (x - y);
	else if (oper == '*')
		return (x * y);
	else if (oper == '/')
		return (x / y);
	return (0);
}

int main()
{
    //if (argc < 2)
    //    return (0);
	//ExprToken*	stack1;
	//ExprToken*	stack2;
	//ExprToken	data;
	//int			i;
	
	//i = 1;
	//stack1 = calloc(1, sizeof(ExprToken));
	//stack2 = calloc(1, sizeof(ExprToken));
	//while (argv[i])
	//{
	//	data = convert_node(argv[i]);
	//	pushLSExprToken(stack1, data);
	//	i++;
	//}

	calcExpr("254+3**");
}