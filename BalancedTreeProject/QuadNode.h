//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Section 19.3.

// PARTIALLY COMPLETE

/** A class of nodes for a link-based 2-3-4 tree.
@file QuadNode.h */

#pragma once

#ifndef _QUAD_NODE
#define _QUAD_NODE

template<class ItemType>
class QuadNode
{
private:
	ItemType smallItem, middleItem, largeItem; // Data portion
	QuadNode<ItemType>* leftChildPtr;          // Left-child pointer
	QuadNode<ItemType>* leftMidChildPtr;       // Middle-left-child pointer
	QuadNode<ItemType>* rightMidChildPtr;      // Middle-right-child pointer
	QuadNode<ItemType>* rightChildPtr;         // Right-child pointer
	QuadNode<ItemType>* parentPtr;
	int dataCount;
											   
// Constructors, accessor methods, and mutator methods are here.
public:
	QuadNode();
	QuadNode(const ItemType newItem);
	QuadNode(const ItemType newItem, QuadNode<ItemType>* leftPtr,
		QuadNode<ItemType>* lMidPtr, QuadNode<ItemType>* rMidPtr,
		QuadNode<ItemType>* rightPtr);

	ItemType getSmallItem() const;
	ItemType getMidItem() const;
	ItemType getLargeItem() const;
	
	void setSmallItem(ItemType newItem);
	void setMidItem(ItemType newItem);
	void setLargeItem(ItemType newItem);

	void setLeftChildPtr(QuadNode<ItemType>* left);
	void setRightChildPtr(QuadNode<ItemType>* right);
	void setLeftMidChildPtr(QuadNode<ItemType>* leftMid);
	void setRightMidChildPtr(QuadNode<ItemType>* rightMid);
	void setParentPtr(QuadNode<ItemType>* parent);

	QuadNode<ItemType>* getLeftChildPtr() const;
	QuadNode<ItemType>* getRightChildPtr() const;
	QuadNode<ItemType>* getLeftMidChildPtr() const;
	QuadNode<ItemType>* getRightMidChildPtr() const;
	QuadNode<ItemType>* getParentPtr() const;

	bool isLeaf();
	bool isRoot();
	int getDataCount();
	void setDataCount(int count);

}; // end QuadNode
#endif _QUAD_NODE