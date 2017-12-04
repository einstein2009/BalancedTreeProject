/***********************************************************
*  Group A                                                 *
*  Authors:       Rodel Aragon, Colby Abrahamoff,          *
*                 Christsandra Broderick, Chandler Snoddy  *
*                 Nicholas Ackors, Stephen Hall            *
***********************************************************/

//Steve Hall
//

#include "stdafx.h"
#include "A234Tree.h"

#pragma once

template <class ItemType>
A234Tree<ItemType>::A234Tree(): rbt(nullptr), current(nullptr)
{
	rootPtr = new QuadNode<ItemType>();
}

template<class ItemType>
void A234Tree<ItemType>::inOrderTraversal(QuadNode<ItemType>* subTreeNode, int width)
{
		if (subTreeNode == nullptr)
			return;
		InorderTraversal(subTreeNode->getLeftChildPtr(), width + 1);
		for (int i = 0; i < width; i++)
			cout << ".";
		cout << subTreeNode->getItem() << endl;

		inOrderTraversal(subTreeNode->getRightChildPtr(), width + 1);
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
	cout << endl;

	InorderTraversal(root, 0);

	cout << endl;
}

template<class ItemType> //Nick
void A234Tree<ItemType>::insertItem(ItemType newData)
{
	//This ensures that the new leafNode is always a leaf
	QuadNode<ItemType>* leafNode = locateLeaf(rootPtr, newData);
	
	//New tree
	if (leafNode->getDataCount() == 0)
	{
		leafNode->setSmallItem(newData);
		leafNode->setDataCount(1);
	}

	//Only one item in the leafNode
	if (leafNode->getDataCount() == 1)
	{
		//The newData is smaller than the item
		if (newData < leafNode->getSmallItem())
		{
			leafNode->setLargeItem(leafNode->getSmallItem());
			leafNode->setSmallItem(newData);
		}
		//The newData is larger than the item
		else if (newData > leafNode->getSmallItem())
			leafNode->setLargeItem(newData);

		leafNode->setDataCount(2);
	}

	//Two items in the leafNode
	if (leafNode->getDataCount() == 2)
	{
		//The newData is smaller than the smallest item
		if (newData < leafNode->getSmallItem())
		{
			leafNode->setLargeItem(leafNode->getSmallItem());
			leafNode->setSmallItem(newData);
		}
		//The newData is larger than the largest item
		else if (newData > leafNode->getLargeItem())
		{
			leafNode->setMidItem(leafNode->getLargeItem());
			leafNode->setLargeItem(newData);
		}
		//The newData is in the middle
		else
			subTreeNode->setMidItem(newData);

		leafNode->setDataCount(3);
	}
}

//Removes data item from 2-3-4 tree. Returns true if successful or false if no
//such item exists. - Christy Broderick
template<class ItemType>
void A234Tree<ItemType>::remove()
{
	//locating dataItem
	if (dataItem->isLeaf())
	{
		if (dataItem->isLeaf.next);
		while (dataItem->leafNode())

			//removing at a leaf
			dataItem->removeLeafNode(int index) noexcept;
		if (leafNode->getDataCount() == 0)
			fixTree(leafNode)
			return true
	}
	else
		return false

		//completes removal when the node is empty by deleting the root, redistributing
		//values, or merging nodes.
		fixTree(n: A234TreeNode)

		if (n->isRoot())
		{
			root remove();

		else
		{
			if (leafNode->getDataCount() == 2)
			{
				return findItem(subTreeNode->getLeftChildPtr(), target);
				return findItem(subTreeNode->getLeftMidChildPtr(), target);
				return findItem(subTreeNode->getRightChildPtr(), target);
				return findItem(subTreeNode->getRightChildPtr(), target);
			}
		}
		}
}

template<class ItemType> //Nick
QuadNode<ItemType>* A234Tree<ItemType>::
locateLeaf(QuadNode<ItemType>* subTreeNode, ItemType target)
{
	//-------------------------------------
	//FIRST CHECK MUST BE IF THE NODE IS FULL WHILE TRAVERSING THE TREE,
	//IF IT'S FULL, IT MUST BE SPLIT SO WE DON'T HAVE TO TRAVEL BACK UP THE TREE.
	//-------------------------------------
	//Node is full small, mid, and large items, 
	//left, leftMid, rightMid, and right children
	//-------------------------------------

	if (subTreeNode->getDataCount() == 3)
	{
		//Must check if subTreeNode is root
		if (subTreeNode->isRoot())
		{
			//If so must create new root
			QuadNode<ItemType>* newRoot = new QuadNode<ItemType>(subTreeNode->getMidItem());
			//And a new right child node, as the root will be the left node
			QuadNode<ItemType>* rightChildNode = new QuadNode<ItemType>(subTreeNode->getLargeItem());

			//New "Binary" root
			newRoot->setDataCount(1);
			newRoot->setLeftChildPtr(subTreeNode);
			newRoot->setRightChildPtr(rightChildNode);

			//Fill out rightChildNode, and update parents
			rightChildNode->setDataCount(1);

			rightChildNode->setRightChildPtr(subTreeNode->getRightChildPtr());

			if (subTreeNode->getRightChildPtr() != nullptr)
				(subTreeNode->getRightChildPtr())->setParentPtr(rightChildNode);

			rightChildNode->setLeftChildPtr(subTreeNode->getRightMidChildPtr());

			if (subTreeNode->getRightMidChildPtr() != nullptr)
				(subTreeNode->getRightMidChildPtr())->setParentPtr(rightChildNode);

			rightChildNode->setParentPtr(newRoot);

			//Must update subTreeNode
			subTreeNode->setDataCount(1);
			subTreeNode->setRightChildPtr(subTreeNode->getLeftMidChildPtr());
			subTreeNode->setParentPtr(newRoot);
			subTreeNode->setLeftMidChildPtr(nullptr);
			subTreeNode->setRightMidChildPtr(nullptr);
			subTreeNode->setMidItem(NULL);
			subTreeNode->setLargeItem(NULL);

			this->rootPtr = newRoot;

			//Show must go on after split.
			if (target < newRoot->getSmallItem())
				return locateLeaf(subTreeNode, target);
			else
				return locateLeaf(rightChildNode, target);
		}
		//subTreeNode isn't a root, need a parent node to track the chain
		else
		{
			QuadNode<ItemType>* parentNode = subTreeNode->getParentPtr();

			//If parent has 2 items, then subTreeNode is 1 of 3 children
			if (parentNode->getDataCount() == 2)
			{
				//subTreeNode is small child
				if (subTreeNode->getLargeItem() < parentNode->getSmallItem())
				{
					parentNode->setMidItem(parentNode->getSmallItem());
					parentNode->setSmallItem(subTreeNode->getMidItem());
					parentNode->setRightMidChildPtr(parentNode->getLeftMidChildPtr());
					parentNode->setDataCount(3);

					QuadNode<ItemType>* leftMidChildNode =
						new QuadNode<ItemType>(subTreeNode->getLargeItem());
					parentNode->setLeftMidChildPtr(leftMidChildNode);

					leftMidChildNode->setParentPtr(parentNode);
					leftMidChildNode->setDataCount(1);

					//Must update subTreePtr
					subTreeNode->setDataCount(1);
					subTreeNode->setLeftMidPtr(nullptr);
					subTreeNode->setRightMidPtr(nullptr);
					subTreeNode->setMidVal(NULL);
					subTreeNode->setLargeVal(NULL);

					if (target < parentNode->getSmallItem())
						return locateLeaf(parentNode->getLeftChildPtr(), target);

					else if (target < parentNode->getMidItem())
						return locateLeaf(leftMidChildNode, target);

					else if (target < parentNode->getLargeItem())
						return locateLeaf(parentNode->getRightMidChildPtr(), target);

					else
						return locateLeaf(parentNode->getRightChildPtr(), target);
				}

				//subTreeNode is large child
				if (subTreeNode->getSmallItem() > parentNode->getLargeItem())
				{
					parentNode->setMidItem(parentNode->getLargeItem());
					parentNode->setLargeItem(subTreeNode->getMidItem());
					parentNode->setDataCount(3);

					QuadNode<ItemType>* rightMidChildNode =
						new QuadNode<ItemType>(subTreeNode->getLargeItem());
					parentNode->setRightMidChildPtr(rightMidChildNode);

					rightMidChildNode->setParentPtr(parentNode);
					rightMidChildNode->setDataCount(1);

					//Must update subTreePtr
					subTreeNode->setDataCount(1);
					subTreeNode->setLeftMidPtr(nullptr);
					subTreeNode->setRightMidPtr(nullptr);
					subTreeNode->setMidVal(NULL);
					subTreeNode->setLargeVal(NULL);

					if (target < parentNode->getSmallItem())
						return locateLeaf(parentNode->getLeftChildPtr(), target);

					else if (target < parentNode->getMidItem())
						return locateLeaf(leftMidChildNode, target);

					else if (target < parentNode->getLargeItem())
						return locateLeaf(parentNode->getRightMidChildPtr(), target);

					else
						return locateLeaf(parentNode->getRightChildPtr(), target);
				}

				//else subTreeNode is middle child
				else
				{
					parentNode->setMidItem(subTreeNode->getMidItem());
					parentNode->setDataCount(3);

					QuadNode<ItemType>* rightMidChildNode =
						new QuadNode<ItemType>(subTreeNode->getLargeItem());
					parentNode->setRightMidChildPtr(rightMidChildNode);

					rightMidChildNode->setParentPtr(parentNode);
					rightMidChildNode->setDataCount(1);

					//Must update subTreePtr
					subTreeNode->setDataCount(1);
					subTreeNode->setLeftMidPtr(nullptr);
					subTreeNode->setRightMidPtr(nullptr);
					subTreeNode->setMidVal(NULL);
					subTreeNode->setLargeVal(NULL);

					if (target < parentNode->getSmallItem())
						return locateLeaf(parentNode->getLeftChildPtr(), target);

					else if (target < parentNode->getMidItem())
						return locateLeaf(leftMidChildNode, target);

					else if (target < parentNode->getLargeItem())
						return locateLeaf(parentNode->getRightMidChildPtr(), target);

					else
						return locateLeaf(parentNode->getRightChildPtr(), target);
				}
			}

			//If parent has 1 item, then subTreeNode is 1 of 2 children
			if (parentNode->getDataCount() == 1)
			{
				//subTreeNode is small child
				if (subTreeNode->getLargeItem() < parentNode->getSmallItem())
				{
					parentNode->setLargeItem(parentNode->getSmallItem());
					parentNode->setSmallItem(subTreeNode->getMidItem());
					parentNode->setDataCount(2);

					QuadNode<ItemType>* leftMidChildNode =
						new QuadNode<ItemType>(subTreeNode->getLargeItem());
					parentNode->setLeftMidChildPtr(leftMidChildNode);

					leftMidChildNode->setParentPtr(parentNode);
					leftMidChildNode->setDataCount(1);

					//Must update subTreePtr
					subTreeNode->setDataCount(1);
					subTreeNode->setLeftMidPtr(nullptr);
					subTreeNode->setRightMidPtr(nullptr);
					subTreeNode->setMidVal(NULL);
					subTreeNode->setLargeVal(NULL);

					if (target < parentNode->getSmallItem())
						return locateLeaf(subTreeNode->getLeftChildPtr(), target);

					else if (target > parentNode->getLargeItem())
						return locateLeaf(parentNode->getRightChildPtr(), target);

					else
						return locateLeaf(parentNode->getLeftMidChildPtr(), target);
				}

				//subTreeNode is large child
				if (subTreeNode->getSmallItem() > parentNode->getLargeItem())
				{
					parentNode->setLargeItem(subTreeNode->getMidItem());
					parentNode->setLeftMidChildPtr(subTreeNode);
					parentNode->setDataCount(2);

					QuadNode<ItemType>* rightChildNode =
						new QuadNode<ItemType>(subTreeNode->getLargeItem());
					parentNode->setRightChildPtr(rightChildNode);

					rightChildNode->setParentPtr(parentNode);
					rightChildNode->setDataCount(1);

					//Must update subTreePtr
					subTreeNode->setDataCount(1);
					subTreeNode->setLeftMidPtr(nullptr);
					subTreeNode->setRightMidPtr(nullptr);
					subTreeNode->setMidVal(NULL);
					subTreeNode->setLargeVal(NULL);

					if (target < parentNode->getSmallItem())
						return locateLeaf(subTreeNode->getLeftChildPtr(), target);

					else if (target > parentNode->getLargeItem())
						return locateLeaf(parentNode->getRightChildPtr(), target);

					else
						return locateLeaf(parentNode->getLeftMidChildPtr(), target);
				}
			}
		}

		//-------------------------------------
		//Node is a Leaf
		//-------------------------------------

		if (subTreeNode->isLeaf())
			return subTreeNode;

		//-------------------------------------
		//Node has 1 item, always small node, left and right children
		//-------------------------------------

		if (subTreeNode->getDataCount() == 1)
		{
			//Smaller than small, send to the left
			if (target < subTreeNode->getSmallItem())
				return locateLeaf(subTreeNode->getLeftChildPtr(), target);
			//Larger than small, send to the right
			if (target > subTreeNode->getSmallItem())
				return locateLeaf(subTreeNode->getRightChildPtr(), target);
		}

		//-------------------------------------
		//Node has 2 items, always small and largest items,
		//left, leftMid, and right children
		//-------------------------------------

		if (subTreeNode->getDataCount() == 2)
		{
			//Smaller than small, send to the left
			if (target < subTreeNode->getSmallItem())
				return locateLeaf(subTreeNode->getLeftChildPtr(), target);
			//Larger than the small, but smaller than large
			if (target > subTreeNode->getSmallItem() && target < subTreeNode->getLargeItem())
				return locateLeaf(subTreeNode->getLeftMidChildPtr(), target);
			//Larger than large, send to the right
			if (target > subTreeNode->getLargeItem())
				return locateLeaf(subTreeNode->getRightChildPtr(), target)
		}
	}
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
			*current->setRightChildPtr(new RedBlackNode(root->getRightChildPtr()->getSmallItem()));
		}
	}
	else if (root->getDataCount() == 2) {
		*current->setItem(root->getSmallItem());
		*current->setColor(Color::BLACK);
		*current->setLeftChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem()));
		*current->setRightChildPtr(new RedBlackNode(root->getMidItem()));
		*current->getRightChildPtr->getLeftChildPtr()ChildPtr()->setLeftchildPtr(new RedBlackNode(root->getLeftMidChildPtr()->getSmallItem()));
		*current->getRightChildPtr()->setRightchildPtr(new RedBlackNode(root->getRightMidChildPtr()->getSmallItem()));
	}
	else {
		*current->setItem(root->getMidItem());
		*current->setColor(Color::BLACK);
		*current->setLeftChildPtr(new RedBlackNode(root->getSmallItem));
		*current->getLeftChildPtr()->setLeftChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem()));
		*current->getLeftChildPtr()->setRightChildPtr(new RedBlackNode(root->getLeftMidChildPtr()->getSmallItem()));
		*current->setRightChildPtr(new RedBlackNode(root->getLargeItem));
		*current->getRightChildPtr()->setLeftChildPtr(new RedBlackNode(root->getRightMidChildPtr()->getSmallItem()));
		*current->getRightChildPtr()->setRightChildPtr(new RedBlackNode(root->getLeftChildPtr()->getSmallItem()));
	}
	convertToRBT(root->getLeftChildPtr());
	convertToRBT(root->getLeftMidChildPtr());
	convertToRBT(root->getRightMidChildPtr());
	convertToRBT(root->getRightChildPtr());
}

//Rodel Aragon
template<class ItemType>
void A234Tree<ItemType>::convertToRBTStart()
{
	convertToRBT(rootPtr);
}

//Rodel Aragon
template<class ItemType>
int A234Tree<ItemType>::getRootDataCount() const
{
	return rootPtr->getDataCount();
}

//Rodel Aragon
template<class ItemType>
ItemType A234Tree<ItemType>::getRootSmallItem() const
{
	return rootPtr->getSmallItem();
}

//Rodel Aragon
template<class ItemType>
ItemType A234Tree<ItemType>::getRootMidItem() const
{
	return rootPtr->getMidItem();
}

//Rodel Aragon
template<class ItemType>
ItemType A234Tree<ItemType>::getRootLargeItem() const
{
	return rootPtr->getLargeItem();
}

//moving RBT pointer - Christy Broderick
template<typename Key> typename Value inline converToRBT<Key, Value> & convertToRBT<Key, Value>::
operator = (convertToRBT && 1hs) noexcept
{
tree_size = 1hs.tree_size;
1hs.tree_size = 0;
root = std::move(1hs.root);
root->parent = nullptr;
}
