//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Section 19.4.

/** A class of nodes for a link-based red-black tree.
@file RedBlackNode.h */

// PARTIALLY COMPLETE
#include "BinaryNode.h"

enum Color { RED, BLACK };

template<class ItemType>
class RedBlackNode : public BinaryNode<ItemType>
{
private:
	Color leftColor, rightColor, color;

public:
	RedBlackNode();
	RedBlackNode(const ItemType newItem);
	RedBlackNode(const ItemType newItem, RedBlackNode<ItemType>* leftPtr, RedBlackNode<ItemType>* rightPtr);

	// Get and set methods for leftColor and rightColor
	Color getLeftColor() const;
	Color getRightColor() const;
	Color getColor() const;

	void setLeftColor(Color col);
	void setRightColor(Color col);
	void setColor(Color col);
	// . . .

}; // end RedBlackNode

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType newItem) : BinaryNode(newItem)
{
	color = Color::RED;
	leftColor = Color::BLACK;
	rightColor = Color::BLACK;
}

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType newItem, RedBlackNode<ItemType>* leftPtr, RedBlackNode<ItemType>* rightPtr) : BinaryNode(newItem)
{
	color = Color::RED;
	leftColor = leftPtr->getColor();
	rightColor = rightPtr->getColor();
	setLeftChildPtr(leftPtr);
	setRightChildPtr(rightPtr);
}


template<class ItemType>
Color RedBlackNode<ItemType>::getLeftColor() const
{
	return leftColor;
}

template<class ItemType>
Color RedBlackNode<ItemType>::getRightColor() const
{
	return rightColor;
}

template<class ItemType>
Color RedBlackNode<ItemType>::getColor() const
{
	return color;
}

template<class ItemType>
void RedBlackNode<ItemType>::setLeftColor(Color col)
{
	leftColor = col;
}

template<class ItemType>
void RedBlackNode<ItemType>::setRightColor(Color col)
{
	rightColor = col;
}

template<class ItemType>
void RedBlackNode<ItemType>::setColor(Color col)
{
	color = col;
}
