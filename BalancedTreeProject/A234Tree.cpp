//Group A Assignment 6
//Steve Hall
//

#include "stdafx.h"
#include "A234Tree.h"

#pragma once

template <class ItemType>
A234Tree<ItemType>::A234Tree()
{
}
template<class ItemType>
void A234Tree<ItemType>::insertInOrder(QuadNode<ItemType>* subTreeNode)
{
	bool isSuccessful = false;
	if 
}

//template<class ItemType>
//void A234Tree<ItemType>::findItem(QuadNode<ItemType>* subTreeNode, ItemType target)
//{
//	//if target is in the root node
//	if (subTreeNode->getSmallItem() == target)
//	{
//		return subTreeNode->getSmallItem();
//	}
//	if (subTreeNode->getMidItem() == target)
//	{
//		return subTreeNode->getMidItem();
//	}
//	if (subTreeNode->getLargeItem() == target)
//	{
//		return subTreeNode->getLargeItem();
//	}
//
//	//Else search the appropriate subTree
//	//If node has 4 items
//	if (subTreeNode->getDataCount() == 3)
//	{
//	
//		if (target < subTreeNode->getSmallItem())
//		{
//			return findItem(subTreeNode->getLeftChildPtr(), target);
//		}
//
//		if (target > subTreeNode->getSmallItem() && target < subTreeNode->getMidItem())
//		{
//			return findItem(subTreeNode->getLeftMidChildPtr(), target);
//		}
//	
//		if (target > subTreeNode->getMidItem() && target < subTreeNode->getLargeItem())
//		{
//			return findItem(subTreeNode->getRightMidChildPtr(), target);
//		}
//
//		if (target > subTreeNode->getLargeItem())
//		{
//			return findItem(subTreeNode->getRightChildPtr(), target);
//		}
//	}
//
//	//Else if node has 3 items
//	if (subTreeNode->getDataCount() == 2)
//	{
//		if (target < subTreeNode->getSmallItem())
//		{
//			return findItem(subTreeNode->getLeftChildPtr(), target);
//		}
//
//		if (target > subTreeNode->getLargeItem())
//		{
//			return findItem(subTreeNode->getRightChildPtr(), target);
//		}
//		if (target > subTreeNode->getSmallItem() && target < subTreeNode->getLargeItem())
//		{
//			return findItem(subTreeNode->getLeftMidChildPtr(), target);
//		}
//	}
//
//	//If the node has two children
//	if (subTreeNode->getDataCount() == 1)
//	{
//		if (target < subTreeNode->getSmallVal())
//		{
//			return findItem(subTreeNode->getLeftPtr(), target);
//		}
//		else
//		{
//			return findItem(subTreeNode->getRightPtr(), target);
//		}
//	}
//}

template<class ItemType>
void A234Tree<ItemType>::display()
{
}

template<class ItemType>
bool A234Tree<ItemType>::insertItem(ItemType newData)
{
	QuadNode<ItemType>* newNodePtr = new QuadNode<ItemType>(newData);

}

template<class ItemType>
void A234Tree<ItemType>::remove()
{
}

template<class ItemType>
QuadNode<ItemType>* A234Tree<ItemType>::locateLeaf(QuadNode<ItemType>* subTreeNode, ItemType target)
{
	return nullptr;
}

template<class ItemType>
QuadNode<ItemType>* A234Tree<ItemType>::splitNode(QuadNode<ItemType>* subTreeNode)
{
	QuadNode<ItemType>* newNodePtr = new QuadNode<ItemType>(subTreeNode);
	newNodePtr->setSmallItem(subTreeNode->getSmallItem());
	newNodePtr->setMidItem(subTreeNode->getMidItem());
	subTreeNode->setLargeItem(subTreeNode->getLargeItem());
	

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
		*current->getRightCroot->getLeftChildPtr()hildPtr()->setLeftchildPtr(new RedBlackNode(root->getLeftMidChildPtr()->getSmallItem());
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
