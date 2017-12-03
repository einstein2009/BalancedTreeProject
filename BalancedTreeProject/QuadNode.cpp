//Assignment 6 Group A
//Steve Hall
//

#include "stdafx.h"
#include "QuadNode.h"


template<class ItemType>
QuadNode<ItemType>::QuadNode()
{
	dataCount = 1;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType newItem)
{
	this->smallItem = newItem;
	dataCount = 1;
}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType newItem, QuadNode<ItemType>* leftPtr, QuadNode<ItemType>* rightPtr, QuadNode<ItemType>* lMidPtr, QuadNode<ItemType>* rMidPtr)
{
	this->smallItem = newItem;
	dataCount = 1;
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
	if (smallItem == newItem())
		dataCount++;
	smallItem = newItem;
}

template<class ItemType>
void QuadNode<ItemType>::setMidItem(ItemType newItem)
{
	if (middleItem == newItem())
		dataCount++;
	middleItem = newItem;
}

template<class ItemType>
void QuadNode<ItemType>::setLargeItem(ItemType newItem)
{
	if (largeItem == newItem())
		dataCount++;
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
bool QuadNode<ItemType>::isLeaf()
{
	return getLeftChildPtr() == nullptr && getLeftMidChildPtr() == nullptr && getRightMidChildPtr() == nullptr && getRightChildPtr() == nullptr;
}

template<class ItemType>
int QuadNode<ItemType>::getDataCount()
{
	return dataCount;
}