#include "bintree.h"
#include <stdlib.h>
#include <string.h>

BinTree	*makeBinTree(BinTreeNode rootNode)
{
	BinTree		*tree;
	BinTreeNode	*root;

	tree = calloc(1, sizeof(BinTree));
	root = calloc(1, sizeof(BinTreeNode));
	*root = rootNode;
	tree->pRootNode = root;
	return (tree);
}

BinTreeNode	*getRootNodeBT(BinTree *pBinTree)
{
	return (pBinTree->pRootNode);
}

BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*elem;

	elem = calloc(1, sizeof(BinTreeNode));
	*elem = element;
	elem->pLeftChild = 0;
	elem->pRightChild = 0;
	pParentNode->pLeftChild = elem;
	return (elem);
}

BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*elem;

	elem = calloc(1, sizeof(BinTreeNode));
	*elem = element;
	elem->pLeftChild = 0;
	elem->pRightChild = 0;
	pParentNode->pRightChild = elem;
	return (elem);
}

BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
	return (pNode->pLeftChild);
}

BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode)
{
	return (pNode->pRightChild);
}

void	deleteBinTreeNode(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	bzero(pNode, sizeof(BinTreeNode));
	free(pNode);
}

void	deleteBinTree(BinTree *pBinTree)
{
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
	pBinTree = 0;
}
