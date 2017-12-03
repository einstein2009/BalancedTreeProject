//Group A Assignment 6
//Steve Hall
//

#include "stdafx.h"
#include "A234Tree.h"

#pragma once

template <class ItemType>
A234Tree<ItemType>::A234Tree(): rootPtr(nullptr), rbt(nullptr),	current(nullptr)
{
}

template<class ItemType>
void A234Tree<ItemType>::findItem(QuadNode<ItemType>* subTreeNode, ItemType target)
{
	//if target is in the root node
	if (subTreeNode->getSmallItem() == target)
		return subTreeNode->getSmallItem();

	if (subTreeNode->getMidItem() == target)
		return subTreeNode->getMidItem();

	if (subTreeNode->getLargeItem() == target)
		return subTreeNode->getLargeItem();

	//Else search the appropriate subTree
	//If node has 4 items
	if (subTreeNode->getDataCount() == 3)
	{
		if (target < subTreeNode->getSmallItem())
			return findItem(subTreeNode->getLeftChildPtr(), target);

		if (target > subTreeNode->getSmallItem() && target < subTreeNode->getMidItem())
			return findItem(subTreeNode->getLeftMidChildPtr(), target)
	
		if (target > subTreeNode->getMidItem() && target < subTreeNode->getLargeItem())
			return findItem(subTreeNode->getRightMidChildPtr(), target);

		if (target > subTreeNode->getLargeItem())
			return findItem(subTreeNode->getRightChildPtr(), target);
	}

	//Else if node has 3 items
	if (subTreeNode->getDataCount() == 2)
	{
		if (target < subTreeNode->getSmallItem())
			return findItem(subTreeNode->getLeftChildPtr(), target);

		if (target > subTreeNode->getLargeItem())
			return findItem(subTreeNode->getRightChildPtr(), target);

		if (target > subTreeNode->getSmallItem() && target < subTreeNode->getLargeItem())
			return findItem(subTreeNode->getLeftMidChildPtr(), target);
	}

	//If the node has two children
	if (subTreeNode->getDataCount() == 1)
	{
		if (target < subTreeNode->getSmallVal())
			return findItem(subTreeNode->getLeftPtr(), target);

		else
			return findItem(subTreeNode->getRightPtr(), target);
	}
}

template<class ItemType>
void A234Tree<ItemType>::display()
{
}

template<class ItemType> //Nick
bool A234Tree<ItemType>::insertItem(ItemType newData)
{
	//While traveling down the tree to ADD an item, 4 things can happen.
	//1. Node is empty
	//2. Node has 1 item, always small node
	//3. Node has 2 items, always small and largest node
	//4. Node is full (3 items) small, mid, and large
	//Shifts need to be made to keep the structure of tree.

}

template<class ItemType>
void A234Tree<ItemType>::remove()
{
}

template<class ItemType> //Nick
QuadNode<ItemType>* A234Tree<ItemType>::locateLeaf(QuadNode<ItemType>* subTreeNode, ItemType target)
{
	//-------------------------------------
	//1. Node is a Leaf
	//-------------------------------------

	if (subTreeNode->isLeaf())
		return subTreeNode;

	//-------------------------------------
	//2. Node has 1 item, always small item
	//-------------------------------------

	if (subTreeNode->dataCount == 1)
	{
		//If Node contains no children
		if (subTreeNode->getLeftChildPtr() == nullptr && 
			subTreeNode->getLeftMidChildPtr() == nullptr &&
			subTreeNode->getRightMidChildPtr() == nullptr &&
			subTreeNode->getRightChildPtr() == nullptr)
			return subTreeNode;
		else if (true)
		{

		}
	}

	return nullptr;
}

template<class ItemType> // Steve 
void A234Tree<ItemType>::convertToRBT(QuadNode<ItemType>* root)
{
	// where should i move the Red Black Tree pointer ???
	if (root == nullptr || root->isLeaf()) {
		return
	}
	if (root->dataCount == 1) {
		*current->setItem(root->getSmallItem());
		*current->setColor(Color::BLACK);
		if (root->getLeftChildPtr->getMidItem() != ItemType()) {
			*current->setLeftChildPtr(new RedBlackNode(root->getLeftChildPtr()->getMidItem()));
		}
		else {
			*current->setLeftChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem()));
		}
		if (root->getRightChildPtr->getMidItem() != ItemType()) {
			*current->setRightChildPtr(new RedBlackNode(root->getRightChildPtr()->getMidItem()));
		}
		else {
			current->setRightChildPtr(new RedBlackNode(root->getRightChildPtr()->getSmallItem()));
		}
	}
	else if (root->getDataCount() == 2) {
		*current->setItem(root->getSmallItem());
		*current->setColor(Color::BLACK);
		*current->setLeftChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem()));
		*current->setRightChildPtr(new RedBlackNode(root->getMidItem());
		*current->getRightCroot->getLeftChildPtr()ChildPtr()->setLeftchildPtr(new RedBlackNode(root->getLeftMidChildPtr()->getSmallItem());
		*current->getRightChildPtr()->setRightchildPtr(new RedBlackNode(root->getRightMidChildPtr()->getSmallItem());
	}
	else {
		*current->setItem(root->getMidItem());
		*current->setColor(Color::BLACK);
		*current->setLeftChildPtr(new RedBlackNode(root->getSmallItem));
		*current->getLeftChildPtr()->setLeftChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem());
		*current->getLeftChildPtr()->setRightChildPtr(new RedBlackNode(root->getLeftMidChildPtr()->getSmallItem());
		*current->setRightChildPtr(new RedBlackNode(root->getLargeItem));
		*current->getRightChildPtr()->setLeftChildPtr(new RedBlackNode(root->getRightMidChildPtr()->getSmallItem());
		*current->getRightChildPtr()->setRightChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem());
	}
	convertToRBT(root->getLeftChildPtr());
	convertToRBT(root->getLeftMidChildPtr());
	convertToRBT(root->getRightMidChildPtr());
	convertToRBT(root->getRightChildPtr());
}
