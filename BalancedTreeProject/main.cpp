
/***********************************************************
*                                                          *
*  Authors:       Rodel Aragon, Colby Abrahamoff,          *
*                 Christsandra Broderick, Chandler Snoddy  *
*                 Nicholas Ackors, Stephen Hall            *
*  Course:        CS322 Data Structure and Algorithms II   *
*  Assignment:    Module 6, Written Assignment             *
*  Program:       2-3-4 Tree and Red-Black Tree       	   *	           
*  Description:   Creates a 2-3-4 Tree with with random    *
*                 integers, then converts the tree to a    *
*                 red-black tree.                          *
*  Input:         Takes as input 100 random int values     *
*                 generated by the rand() function         *
*  Output:        Several lines displaying the values      *
*                 contained within the 2-3-4 tree and the  *
*                 red-black tree. Output is displayed to   *
*                 discern both trees as a 2-3-4 tree and   *
*                 a red-black tree.                        *
*  Created:       12/1/2017                                *
*                                                          *
***********************************************************/

#include "stdafx.h"

/////////////////////////////////////
//main.cpp written by Rodel Aragon
/////////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A234Tree.h"
#include "RedBlackTree.h"

using namespace std;

/* Function to check the array for the given data item
Precondition: The given array must contain items.
Postcondition: The index of iDataItem is returned and the data remains unchanged
Returns: The index of iDataItem if it is contained within the array, else -1 if it is not
Parameter: arriArray[] -- The array to check.
Parameter: iDataItem -- the data item to search the array for.
Parameter: iArrayLength -- The length of the given array. */
int getRemoveIndex(int arriArray[], int iDataItem, int iArrayLength);

int main()
{
	A234Tree<int> *CpTreePtr = new A234Tree<int>(); //pointer to 2-3-4 tree
	int iRandValue; // used to insert random values into tree
	int arriFirstNumToRemove[37]; // stores 37 numbers to remove from 2-3-4 tree
	int arriSecondNumToRemove[32]; // stores 32 numbers to remove from red-black tree
	int iNumOfRootItems; // gets the number of data items contained in root
	int iRootSmallItem, iRootMidItem, iRootLargeItem, iRedBlackRoot;
	int iSmallIndex, iMidIndex, iLargeIndex, iRBRootIndex, iTempHolder;
	int iArrayLength = 37;

	cout << "Constructing a 2-3-4 tree with 100 int values ranging from 200-500..." << endl << endl;

	//stores 100 integers into 2-3-4 tree
	for (int iteration = 0; iteration < 100; iteration++)
	{
		//gives iRandValue a randomly generated integer in the range 200-500
		iRandValue = (rand() % 301) + 200;
		
		//adds iRandValue to the 2-3-4 tree
		CpTreePtr->insertItem(iRandValue);
		
		//stores the first 37 integers into array for use in remove function
		if (iteration < 37)
			arriFirstNumToRemove[iteration] = iRandValue;
		//stores 32 integers into array to remove in red-black tree
		if (iteration > 37 && iteration < 70)
			arriSecondNumToRemove[iteration - 38] = iRandValue;
	} // end for

	//displays tree of 100 integers
	cout << "The 2-3-4 Tree with 100 integers inserted into the tree." << endl;
	CpTreePtr->display();
	cout << endl;

	//get number of data items in root
	iNumOfRootItems = CpTreePtr->getRootDataCount();

	if (iNumOfRootItems == 1) // -------------------------------------------------------------------------
	{
		// if root contains only 1 item, get the smallItem
		iRootSmallItem = CpTreePtr->getRootSmallItem();

		//checks to see if iRootSmallItem is contained within array
		iSmallIndex = getRemoveIndex(arriFirstNumToRemove, iRootSmallItem, iArrayLength);

		 //if iRootSmallItem is not found in array, insert iRootSmallItem into index 0
		if (iSmallIndex == -1)
			arriFirstNumToRemove[0] = iRootSmallItem;
		else //iRootSmallItem is in the array
		{
			//Move iRootSmallItem to index 0
			iTempHolder = arriFirstNumToRemove[iSmallIndex];
			arriFirstNumToRemove[iSmallIndex] = arriFirstNumToRemove[0];
			arriFirstNumToRemove[0] = iTempHolder;
		} // end else

	}// end if
	else if (iNumOfRootItems == 2) //----------------------------------------------------------------------
	{
		// if root contains 2 items, get the small and large items
		iRootSmallItem = CpTreePtr->getRootSmallItem();
		iRootLargeItem = CpTreePtr->getRootLargeItem();

		//checks to see if iRootSmallItem is contained within array
		iSmallIndex = getRemoveIndex(arriFirstNumToRemove, iRootSmallItem, iArrayLength);
		
		//if iRootSmallItem is not found in array, insert iRootSmallItem into index 0
		if (iSmallIndex == -1)
			arriFirstNumToRemove[0] = iRootSmallItem;
		else //iRootSmallItem is in the array
		{
			//Move iRootSmallItem to index 0
			iTempHolder = arriFirstNumToRemove[iSmallIndex];
			arriFirstNumToRemove[iSmallIndex] = arriFirstNumToRemove[0];
			arriFirstNumToRemove[0] = iTempHolder;
		} // end else

		//checks to see if iRootLargeItem is contained within array
		iLargeIndex = getRemoveIndex(arriFirstNumToRemove, iRootLargeItem, iArrayLength);

		//if iRootLargeItem is not found in array, insert iRootLargeItem into index 1
		if (iLargeIndex == -1)
			arriFirstNumToRemove[1] = iRootLargeItem;
		else //iRootLargeItem is in the array
		{
			//move iRootLargeItem to index 1
			iTempHolder = arriFirstNumToRemove[iLargeIndex];
			arriFirstNumToRemove[iLargeIndex] = arriFirstNumToRemove[1];
			arriFirstNumToRemove[1] = iTempHolder;
		} // end else
	} // end else if
	else // root contains 3 items -----------------------------------------------------------------------
	{
		// if root contains 3 items, get all three
		iRootSmallItem = CpTreePtr->getRootSmallItem();
		iRootMidItem = CpTreePtr->getRootMidItem();
		iRootLargeItem = CpTreePtr->getRootLargeItem();


		//checks to see if iRootSmallItem is contained within array
		iSmallIndex = getRemoveIndex(arriFirstNumToRemove, iRootSmallItem, iArrayLength);

		//if iRootSmallItem is not found in array, insert iRootSmallItem into index 0
		if (iSmallIndex == -1)
			arriFirstNumToRemove[0] = iRootSmallItem;
		else //iRootSmallItem is in the array
		{
			//move iRootSmallItem to index 0
			iTempHolder = arriFirstNumToRemove[iSmallIndex];
			arriFirstNumToRemove[iSmallIndex] = arriFirstNumToRemove[0];
			arriFirstNumToRemove[0] = iTempHolder;
		} // end else

		//checks to see if iRootLargeItem is contained within array
		iLargeIndex = getRemoveIndex(arriFirstNumToRemove, iRootLargeItem, iArrayLength);

		//if iRootLargeItem is not found in array, insert iRootLargeItem into index 1
		if (iLargeIndex == -1)
			arriFirstNumToRemove[1] = iRootLargeItem;
		else //iRootLargeItem is in the array
		{
			//Move iRootLargeItem to index 1
			iTempHolder = arriFirstNumToRemove[iLargeIndex];
			arriFirstNumToRemove[iLargeIndex] = arriFirstNumToRemove[1];
			arriFirstNumToRemove[1] = iTempHolder;
		} // end else

		//checks to see if iRootMidItem is contained within array
		iMidIndex = getRemoveIndex(arriFirstNumToRemove, iRootMidItem, iArrayLength);

		//if iRootMidItem is not found in array, insert iRootMidItem into index 2
		if (iMidIndex == -1)
			arriFirstNumToRemove[2] = iRootMidItem;
		else //iRootMidItem is in the array
		{
			//Move iRootMidItem to index 2
			iTempHolder = arriFirstNumToRemove[iMidIndex];
			arriFirstNumToRemove[iMidIndex] = arriFirstNumToRemove[2];
			arriFirstNumToRemove[2] = iTempHolder;
		} // end else
	}// end else
	//--------------------------------------------------------------------------------------------

	//delete 37 int values from 2-3-4 tree
	cout << "Deleting 37 integers from 2-3-4 tree..." << endl << endl;
	for (int i = 0; i < 37; i++)
	{
		CpTreePtr->remove(arriFirstNumToRemove[i]);
	}

	//display list after deletions
	cout << "Displaying list after deletion of 37 integers..." << endl;
	CpTreePtr->display();
	cout << endl;

	cout << "Converting 2-3-4 tree to a Red-Black Tree..." << endl << endl;
	//convert 2-3-4 tree to red-black tree
	CpTreePtr->convertToRBTStart();
	
	//pointer to Red-Black Tree class
	RedBlackTree<int> *CpRedBlackTreePtr = new RedBlackTree<int>;

	//display list after conversion
	cout << "Displaying Red-Black Tree values..." << endl;
	CpRedBlackTreePtr->display();
	cout << endl;
	
	//get rootItem
	iRedBlackRoot = CpRedBlackTreePtr->getRoot();

	//change array length
	iArrayLength = 32;

	//check to see if iRedBlackRoot is within array
	iRBRootIndex = getRemoveIndex(arriSecondNumToRemove, iRedBlackRoot, iArrayLength);

	//if root is not within array, insert it into array
	if (iRBRootIndex == -1)
		arriSecondNumToRemove[0] = iRedBlackRoot;

	// delete 32 integers from red-black tree
	cout << "Deleting 32 integers from the red-black tree..." << endl << endl;
	for (int l = 0; l < 32; l++)
	{
		CpRedBlackTreePtr->remove(arriSecondNumToRemove[l]);
	}

	cout << "Displaying red-black tree after deletion of 32 integers..." << endl;
	CpRedBlackTreePtr->display();
	cout << endl;

	//clears buffer and terminates program on next input
	cout << "Terminating program... press any key to exit.";
	cin.clear();
	cin.ignore(100, '\n');
	cin.get();

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION
///////////////////////////////////////////////////////////////////////////////////////////
int getRemoveIndex(int arriArray[], int iDataItem, int iArrayLength)
{
	bool bItemFound = false;
	int iIndex = 0;

	// check to see if the root item is already contained in array containing
	// numbers to be removed
	while (!bItemFound && iIndex < iArrayLength)
	{
		if (arriArray[iIndex] == iDataItem)
		{
			//item is found
			bItemFound = true;

			return iIndex;
		}//end if

		iIndex++;
	}// end while

	//item not found
	return -1;
}
