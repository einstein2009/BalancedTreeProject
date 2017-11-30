//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Section 19.4.

/** A class of nodes for a link-based red-black tree.
@file RedBlackNode.h */

// PARTIALLY COMPLETE

#pragma once

enum Color { RED, BLACK };

template<class ItemType>
class RedBlackNode : public BinaryNode<ItemType>
{
private:
	Color leftColor, rightColor;

public:
	RedBlackNode();
	RedBlackNode(const ItemType newItem);
	RedBlackNode(const ItemType newItem, RedBlackNode<ItemType>* redPtr, RedBlackNode<ItemType>* blackPtr, );
	
	// Get and set methods for leftColor and rightColor
	ItemType getLeftColor() const;
	ItemType getRightColor() const;

	void setLeftColor(ItemType newItem);
	void setRightColor(ItemType newItem);

	RedBlackNode<ItemType>* getRedPtr() const;
	RedBlackNode<ItemType>* getBlackPtr() const;

	void setRedPtr(RedBlackNode<ItemType>* red);
	void setBlackPtr(RedBlackNode<ItemType>* black);
	// . . .

}; // end RedBlackNode

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode()
{
} // end default constructor

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType newItem)
{

}

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType newItem, RedBlackNode<ItemType>* redPtr, RedBlackNode<ItemType>* blackPtr, )
{

}

template<class ItemType>
ItemType RedBlackNode<ItemType>::getLeftColor() const
{
	return leftColor();
}

template<class ItemType>
ItemType RedBlackNode<ItemType>::getRightColor() const
{
	return rightColor();
}

template<class ItemType>

void RedBlackNode<ItemType>::setLeftColor(ItemType newItem)
{
	leftColor = newItem;
}

template<class ItemType>
void RedBlackNode<ItemType>::setRightColor(ItemType newItem)
{
	rightColor = newItem;
}

template<class ItemType>
RedBlackNode<ItemType>* RedBlackNode<ItemType>::getRedPtr() const
{
	return redptr;
}

template<class ItemType>
RedBlackNode<ItemType>* RedBlackNode<ItemType>::getBlackPtr() const
{
	return blackptr;
}

template<class ItemType>
void RedBlackNode<ItemType>::setRedPtr(RedBlackNode<ItemType>* red)
{
	redptr = red;
}

template<class ItemType>
void RedBlackNode<ItemType>::setBlackPtr(RedBlackNode<ItemType>* black)
{
	blackptr = black;
}
