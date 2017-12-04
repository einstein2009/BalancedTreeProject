/***********************************************************
*  Group A                                                 *
*  Authors:       Rodel Aragon, Colby Abrahamoff,          *
*                 Christsandra Broderick, Chandler Snoddy  *
*                 Nicholas Ackors, Stephen Hall            *
***********************************************************/
#include "stdafx.h"
#pragma once


//The following might need to be added to the main code since it deals with rotating the nodes left and right.
template <class ItemType>
void RedBlackTree::rotateLeft(BinaryNode<ItemType> *root, BinaryNode<ItemType> *point)
{
	Node *point_right = point->right;
	point->right = point_right->left;

	if (point->right != NULL)
		point->right->parent = point;
	point_right->parent = point->parent;

	if (point->parent == NULL)
		root = point_right;
	else
		if (point == point->parent->left)
			point->parent->left = point_right;

		else
			point - parent->right = point_right;

	point_right->left = point;
	point->parent = point_right;
}

template <class ItemType>
void RedBlackTree::rotateRight(BinaryNode<ItemType> *root, BinaryNode<ItemType> *point)
{
	Node *point_left = point->left;

	point->left = point_left->right;

	if (point->left != NULL)
		point->left->parent = point;

	point_left->parent = point->parent;

	if (point->parent == NULL)
		root = point_left;

	else
		if (point == point->parent->left)
			point->parent->left = point_left;

		else
			point->parent->right = point_left;

	point_left->right = point;
	point->parent = point_left;
}

//This section involves detecting and fixing violations with the RedBlackTree. I think this also should be in the main.cpp file.

template <class ItemType>
void RedBlackTree::fixViolations(BinaryNode<ItemType> *root, BinaryNode<ItemType> *point)
{
	BinaryNode<ItemType> *parent_point = NULL;
	Node *grandParent_point = NULL;
	//For this function, 'point' is considered the child.
	//Parent_point is the parent of the child.
	//grandParent_point is the grandparent of the child.
	//sibling_point is the sibling of the parent of the child.

	while ((point != root) && (point->color != BLACK) && (point->parent->color == RED))
	{
		parent_point = point->parent;
		grandParent_point = point->parent->parent;

		//Scenario 1: the parent of 'point' is the left child of the grandparent of 'point'.
		if (parent_point == grandParent_point->left)
		{
			//Since it's the sibling of the parent, they'd be on the same height.
			Node * sibling_point = grandParent_point->right;

			//Scenario 1A: If the sibling of the parent of the child is also red: The parent and the sibling need to be recolored black, and the grandparent needs to be recolored red.
			if (sibling_point != NULL && sibling_point->color == RED)
			{
				sibling_point->color = BLACK;
				parent_point->color = BLACK;
				grandParent_point->color = RED;
				point = grandParent_point;

			}

			else
			{
				//Scenario 1B: The point is the right child of the parent. Left rotate.
				if (point == parent_point->right)
				{
					rotateLeft(root, parent_point);
					point = parent_point;
					parent_point = point->parent;
				}

				//Scenario 1C: The point is the left child of the parent. Right rotate.
				rotateRight(root, grandParent_point);
				swap(parent_point->color, grandParent_point->color); //Googling on how to switch values gave me the 'swap' function, but it doesn't seem to work.
				point = parent_point;
			}

		}
		//Scenario 2: The parent of 'point' if the fight child of the grandparent of 'point'.
		else
		{
			Node * sibling_point = grandParent_point->right;

			//Scenario 2A: If the sibling of the parent of the child is also red: The parent and the sibling need to be recolored black, and the grandparent needs to be recolored red.
			if (sibling_point != NULL && sibling_point->color == RED)
			{
				sibling_point->color = BLACK;
				parent_point->color = BLACK;
				grandParent_point->color = RED;
				point = grandParent_point;

			}

			else
			{
				//Scenario 2B: The point is the left child of the parent. Right rotate.
				if (point == parent_point->right)
				{
					rotateRight(root, parent_point);
					point = parent_point;
					parent_point = point->parent;
				}

				//Scenario 2C: The point is the right child of the parent. Left rotate.
				rotateLeft(root, grandParent_point);
				swap(parent_point->color, grandParent_point->color); //Googling on how to switch values gave me the 'swap' function, but it doesn't seem to work.
				point = parent_point;
			}

		}

	}

}



template<class ItemType>
void RedBlackTree<ItemType>::Display(RedBlackNode* root)
	if (root == Null)
	{
		cout << "Tree is empty" << endl;
	}

	if (isLeaf(root))
	{
		if (root->getColor() == BLACK)
		{
			cout << "(BLACK) " << root->getItem() << endl;
		}
		else{
			cout << "(RED) " << root->getItem() << endl;
		}

		cout << "." << endl;
	}
	else
	{
		RedBlackNode* p = root;

		while (!isLeaf(root))
		{
			p = root;
			if (p->getColor() == BLACK)
			{
			cout << "(BLACK) " << p->getItem() << endl;
			}
			else
			{
			cout << "(RED) " << p->getItem() << endl;
			}

		cout << "." << endl;

		}//end while
		
		display(p->getLeftChildPtr);
		display(p->getRightChildPtr);

	}

template<class ItemType>
void RedBlackTree<ItemType>:: Delete(ItemType item)
{
  if (root == Null)
	{
		cout << "tree is empty" << endl;
		return;
	}

	RedBlackNode* n0 = new RedBlackNode();
	//set it equal to the root
	//n0 = root;

	//two more nodes
	RedBlackNode* n1 = new RedBlackNode();
	RedBlackNode* n2 = new RedBlackNode();

	bool found = false;

	while (n0 != nullptr && !found)
	{
		if (n0->getItem() == item)
		{
			found = true;
		}
		if (!found)
		{
			if (n0->getItem() < item)
			{
				n0 = n0->getRightChildPtr();
			}
			else
			{
				n0 = n0->getLeftChildPtr();
			}
		}
	}//end while

	if (!found)
	{
		return;
	}
	else
	{
		if (n0->getLeftChildPtr() == nullptr || n0->getRightChildPtr() == nullptr)
		{
			n1 = n0;
		}
		else
		{
			n1 = n0->getRightChildPtr();
		}
		if (n1->getLeftChildPtr() != nullptr)
		{
			n2 = n1->getLeftChildPtr();
		}
		else
		{
			if (n1->getRightChildPtr() != nullptr)
			{
				n2 = n1->getRightChildPtr();
			}
			else
			{
				n2 = nullptr;
			}
		}

		if (n2 != nullptr)
		{
			n2->setParent(n1->getParent());
		}
		if (n1->getParent() == NULL)
		{
			root = n2;
		}
		else
		{
			if (n1 == (n1->getParent())->getLeftChildPtr())
			{
				(n1->getParent())->setLeftChildPtr(n2);
			}
			else
			{
				(n1->getParent())->setRightChildPtr(n2);
			}
		}
		if (n1 != n0)
		{
			n0->setColor(n1->getColor());
			n0->setItem(n1->getItem());
		}
		if (n1->getColor == BLACK)
		{
			fixAfterDelete(n2);
		}
	}//end else found item
}

template<class ItemType>
void RedBlackTree<ItemType>::fixAfterDelete(ItemType item)
{
	RedBlackNode* newNode;
	while (p != root && p->getColor() == BLACK)
	{
		if ((p->getParent())->leftChildPtr() == p)
		{
			newNode = (p->getParent())->rightChildPtr();
			if (newNode->getColor() == RED)
			{
				newNode->setColor(BLACK);
				(p->getParent())->setColor(RED);
				rotateLeft(root, p->getParent());
			}
			if (newNode->getRightColor() == BLACK && newNode->getLeftColor() == BLACK)
			{
				newNode->setColor(RED);
				p = p->getParent();
			}
			else
			{
				if (newNode->getRightcolor() == BLACK)
				{
					newNode->setLeftColor(BLACK);
					newNode->setColor(RED);
					rotateRight(root, newNode);
					newNode = (p->getParent())->getRightChildPtr();
				}
				newNode->setColor((p->getParent())->getColor());
				(p->getParent())->setColor(BLACK);
				newNode->setRightColor(BLACK);
				rotateLeft(root, p->getParent());
				p = root;
			}
		}

		p->setColor(BLACK);
		root->setColor(BLACK);
	}

}
