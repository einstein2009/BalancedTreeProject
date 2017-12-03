#pragma once

#ifndef _A234TREE
#define _A234TREE
#include "stdafx.h"
#include "QuadNode.h"
#include "RedBlackNode.h"

template <class ItemType>
class A234Tree
{
private:
	QuadNode<ItemType>* rootPtr;
	RedBlackNode<ItemType>* rbt = new RedBlackNode();
	RedBlackNode<ItemType>** current = &rbt;

public:
	A234Tree();
	//void inOrder(QuadNode<ItemType>* subTreeNode);
	void findItem(QuadNode<ItemType>* subTreeNode, ItemType target);
	void display();
	void insertItem(ItemType newData);
	void remove();
	QuadNode<ItemType>* locateLeaf(QuadNode<ItemType>* subTreeNode, ItemType target);
	void convertToRBT(QuadNode<ItemType>* root);
	int getRootDataCount() const;
	ItemType getRootSmallItem() comst;
	ItemType getRootMidItem() const;
	ItemType getRootLargeItem() const;
};
#include "A234Tree.cpp"
#endif _A234TREE
