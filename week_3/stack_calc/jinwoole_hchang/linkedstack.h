#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct ExprTokenType
{
	float					value;
	char					type;
	struct ExprTokenType*	next;
}				ExprToken;

typedef struct LinkedStackType
{
	int			currentTokenCount;
	ExprToken*	head;
}				LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, ExprToken element);
ExprToken* popLS(LinkedStack* pStack);
ExprToken* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
