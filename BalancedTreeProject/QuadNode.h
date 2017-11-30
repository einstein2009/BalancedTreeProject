//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Section 19.3.

// PARTIALLY COMPLETE

/** A class of nodes for a link-based 2-3-4 tree.
@file QuadNode.h */

#pragma once

template<class ItemType>
class QuadNode
{
private:
	ItemType smallItem, middleItem, largeItem; // Data portion
	QuadNode<ItemType>* leftChildPtr;          // Left-child pointer
	QuadNode<ItemType>* leftMidChildPtr;       // Middle-left-child pointer
	QuadNode<ItemType>* rightMidChildPtr;      // Middle-right-child pointer
	QuadNode<ItemType>* rightChildPtr;         // Right-child pointer
											   
// Constructors, accessor methods, and mutator methods are here.
public:
	QuadNode();
	QuadNode(const ItemType newItem);
	QuadNode(const ItemType newItem, QuadNode<ItemType>* leftPtr, QuadNode<ItemType>* rightPtr, QuadNode<ItemType>* lMidPtr, QuadNode<ItemType>* rMidPtr);

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

	QuadNode<ItemType>* getLeftChildPtr() const;
	QuadNode<ItemType>* getRightChildPtr() const;
	QuadNode<ItemType>* getLeftMidChildPtr() const;
	QuadNode<ItemType>* getRightMidChildPtr() const;
										  

}; // end QuadNode


