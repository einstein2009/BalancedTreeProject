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
void RedBlackTree<ItemType>:: fixAfterDelete(ItemType item)
{
}

