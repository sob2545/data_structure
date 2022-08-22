#include "bintree.h"
#include <stdio.h>

void	preorder(BinTreeNode *root)
{
	if (!root)
		return ;
	printf("%c\n", root->data);
	preorder(root->pLeftChild);
	preorder(root->pRightChild);
}

void	inorder(BinTreeNode *root)
{
	if (!root)
		return ;
	inorder(root->pLeftChild);
	printf("%c\n", root->data);
	inorder(root->pRightChild);
}

void	postorder(BinTreeNode *root)
{
	if (!root)
		return ;
	postorder(root->pLeftChild);
	postorder(root->pRightChild);
	printf("%c\n", root->data);
}

int main(void)
{
	BinTree		*pBinTree;
	BinTreeNode	node;
	BinTreeNode	*pLeft;
	BinTreeNode	*pRight;
    //루트
	node.data = 'A';
	pBinTree = makeBinTree(node);
    //왼쪽
	node.data = 'B';
	pLeft = insertLeftChildNodeBT(pBinTree->pRootNode, node);
	node.data = 'E';
	pRight = insertRightChildNodeBT(pLeft, node);
	node.data = 'D';
	pLeft = insertLeftChildNodeBT(pLeft, node);
	node.data = 'H';
	insertLeftChildNodeBT(pLeft, node);
	node.data = 'I';
	insertRightChildNodeBT(pLeft, node);
	node.data = 'J';
	insertLeftChildNodeBT(pRight, node);
    //오른쪽
	node.data = 'C';
	pRight = insertRightChildNodeBT(pBinTree->pRootNode, node);
	node.data = 'F';
	pLeft = insertLeftChildNodeBT(pRight, node);
	node.data = 'G';
	pRight = insertRightChildNodeBT(pRight, node);
	node.data = 'K';
	insertRightChildNodeBT(pLeft, node);
	node.data = 'L';
	insertLeftChildNodeBT(pRight, node);
	node.data = 'M';
	insertRightChildNodeBT(pRight, node);
	printf("전위: \n");
	preorder(pBinTree->pRootNode);
	printf("중위: \n");
	inorder(pBinTree->pRootNode);
	printf("후위: \n");
	postorder(pBinTree->pRootNode);
	deleteBinTree(pBinTree);
    return (0);
}
