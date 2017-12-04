/***********************************************************
*  Group A                                                 *
*  Authors:       Rodel Aragon, Colby Abrahamoff,          *
*                 Christsandra Broderick, Chandler Snoddy  *
*                 Nicholas Ackors, Stephen Hall            *
***********************************************************/
//Assignment 6 Group A
//Steve Hall
//

#include "stdafx.h"
#include "QuadNode.h"


template<class ItemType>
QuadNode<ItemType>::QuadNode(): smallItem(NULL), middleItem(NULL), largeItem(NULL),
leftChildPtr(nullptr), leftMidChildPtr(nullptr), rightMidChildPtr(nullptr), rightChildPtr(nullptr),
parentPtr(nullptr), dataCount(0)
{
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType newItem): smallItem(newItem), middleItem(NULL), largeItem(NULL),
leftChildPtr(nullptr), leftMidChildPtr(nullptr), rightMidChildPtr(nullptr), rightChildPtr(nullptr),
parentPtr(nullptr), dataCount(1)
{
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType newItem, QuadNode<ItemType>* leftPtr, 
	QuadNode<ItemType>* lMidPtr, QuadNode<ItemType>* rMidPtr, QuadNode<ItemType>* rightPtr):
	smallItem(newItem), middleItem(NULL), largeItem(NULL),
	leftChildPtr(leftPtr), leftMidChildPtr(lMidPtr), rightMidChildPtr(rMidPtr), rightChildPtr(rightPtr),
	parentPtr(nullptr), dataCount(1)
{
}

template<class ItemType>
ItemType QuadNode<ItemType>::getSmallItem() const
{
	return smallItem();
}

template<class ItemType>
ItemType QuadNode<ItemType>::getMidItem() const
{
	return middleItem();
}

template<class ItemType>
ItemType QuadNode<ItemType>::getLargeItem() const
{
	return largeItem();
}

template<class ItemType>
void QuadNode<ItemType>::setSmallItem(ItemType newItem)
{
	smallItem = newItem;
}

template<class ItemType>
void QuadNode<ItemType>::setMidItem(ItemType newItem)
{
	middleItem = newItem;
}

template<class ItemType>
void QuadNode<ItemType>::setLargeItem(ItemType newItem)
{
	largeItem = newItem;
}

template<class ItemType>
void QuadNode<ItemType>::setLeftChildPtr(QuadNode<ItemType>* left)
{
	leftChildPtr = left;
}

template<class ItemType>
void QuadNode<ItemType>::setRightChildPtr(QuadNode<ItemType>* right)
{
	rightChildPtr = right;
}

template<class ItemType>
void QuadNode<ItemType>::setLeftMidChildPtr(QuadNode<ItemType>* leftMid)
{
	leftMidChildPtr = leftMid;
}

template<class ItemType>
void QuadNode<ItemType>::setRightMidChildPtr(QuadNode<ItemType>* rightMid)
{
	rightMidChildPtr = rightMid;
}

template<class ItemType>
void QuadNode<ItemType>::setParentPtr(QuadNode<ItemType>* parent)
{
	parentPtr = parent;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getLeftMidChildPtr() const
{
	return leftMidChildPtr;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getRightMidChildPtr() const
{
	return rightMidChildPtr;
}
template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getParentPtr() const
{
	return parentPtr;
}
template<class ItemType>
bool QuadNode<ItemType>::isLeaf()
{
	return getLeftChildPtr() == nullptr && 
		getLeftMidChildPtr() == nullptr && 
		getRightMidChildPtr() == nullptr && 
		getRightChildPtr() == nullptr;
}

template<class ItemType>
bool QuadNode<ItemType>::isRoot()
{
	return parentPtr == nullptr;
}

template<class ItemType>
int QuadNode<ItemType>::getDataCount()
{
	return dataCount;
}

template<class ItemType>
void QuadNode<ItemType>::setDataCount(int count)
{
	dataCount = count;
}
