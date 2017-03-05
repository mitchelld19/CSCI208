// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

#include "Node.h"

using namespace std;

/******************************************************************
 Class LinkedList
 This class defines a data structure for a linked list of integers
*******************************************************************/
template<class ItemType>
class LinkedList
{
  private:


  public:
   LinkedList ();
   bool isEmpty();
   void insertFront(ItemType);
   void insertRear(ItemType);
   int count();
   void printList();
   int findPos(ItemType);
   ItemType retrieveAtPos(int);
   void clear();
   Node<ItemType>* headNodePtr;


   // EXCEPTIONS THROWN
	static const int ItemNotFound = 8001;
	static const int NodeAtPositionNotFound = 8002;
};




/*=====================================================================
/*     IMPLEMENTATION OF METHOD/FUNCTIONS
/*=====================================================================

/******************************************************************
 Class LinkedList
 Function:  Constructor
     Create am empty linked list
	 This is indicated by a null pointer in the start of list (headNodePtr)
 Return: a pointer to the constructed LinkedList object.
*******************************************************************/
template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
	headNodePtr = NULL;
}

 /******************************************************************
 Class LinkedList
 Function:  isEmpty
 Parameters: None
  Returns a bool that indicates if the linked list is or is not empty
*******************************************************************/
template<class ItemType>
bool LinkedList<ItemType>::isEmpty()
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
   if(headNodePtr == NULL)
	   return true;
   else
	   return false;
}

/******************************************************************
 Class LinkedList
 Function:  insertFront
     Inserts a new item at the front of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
template<class ItemType>
void LinkedList<ItemType>::insertFront(ItemType item)
{
	// The headNodePtr currently points to the first node in the list or NULL
	// Create the new node with the item given and point it to the same node (or NULL) as the head
	// Set the head node pointer equal to the new node, now the first one in the list
		Node<ItemType> * tempPtr;
		tempPtr = new Node<ItemType>(item, headNodePtr);
		headNodePtr = tempPtr;


   // Now the head node points to the new node and the new node points to the rest of the list.
}

/******************************************************************
 Class LinkedList
 Function:  insertRear
     Inserts a new item at the end of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
template<class ItemType>
void LinkedList<ItemType>::insertRear (ItemType item)
{
   Node<ItemType> * tempPtr;
   tempPtr = new Node<ItemType>(item, NULL);

   if(isEmpty())
		headNodePtr = tempPtr;
   else
   {
	   Node<ItemType> * currentPtr;
	   currentPtr = headNodePtr;

	   // When I leave this while loop I am pointing to the last Node
	   while (currentPtr->getNext() != NULL)
	   {
		   currentPtr = currentPtr->getNext();
	   }
	   currentPtr->setNext(tempPtr);
   }

}

 /******************************************************************
 Class LinkedList
 Function:  count
 Parameters: None
  Returns an integer count of the number of items in the list
*******************************************************************/
template<class ItemType>
int LinkedList<ItemType>::count()
{
	   int x;
	Node<ItemType> * tempPtr;
	tempPtr = headNodePtr;
	if (isEmpty())
		x = 0;
	else
	{
		x = 1;
		while (tempPtr->getNext() != NULL)
		{
			tempPtr = tempPtr->getNext();
			x++;
		}
	}
	return x;
}

/******************************************************************
 Class LinkedList
 Function:  printList
    Print the data member ("datum") of the current node
    Set the current-pointer to the "next" node in the list.

 Parameters: none.
 Result:  Nodes are printed.
 Return: nothing
*******************************************************************/
template<class ItemType>
void LinkedList<ItemType>::printList ()
{

	Node<ItemType> * tempPtr;
	tempPtr = headNodePtr;
	if(isEmpty())
		cout << "Nothing here" << endl;
	else{

		while (tempPtr->getNext() != NULL)
		{
			cout << tempPtr->getItem() << endl;
			tempPtr = tempPtr->getNext();
		}
		cout << tempPtr->getItem() << endl;
	}
}

/******************************************************************
 Class LinkedList
 Function:  findPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it returns the position of that node in the list.

	 If the node is not found, signal an  exception: itemNotFound

 Parameters: Position in list.

 Return: item at that position
*******************************************************************/
template<class ItemType>
int LinkedList<ItemType>::findPos(ItemType item)
{
	int x = 0;
	Node<ItemType> * tempPtr;
	tempPtr = headNodePtr;
	if (isEmpty())
		cout << "Empty" << endl;
	else{
		while ((tempPtr->getNext() != NULL) && (tempPtr->getItem() != item))
		{
			tempPtr = tempPtr->getNext();
			x++;
		}
	}
	return x;
}

/******************************************************************
 Class LinkedList
 Function:  retrieveAtPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it removes the node from the list
	 and returns the value.

	 If the node is not found, signal an  exception: NodeAtPositionNotFound

 Parameters: Position in list.

 Result:  Node with item is removed from the list.
 Return: item at that position
*******************************************************************/
template<class ItemType>
ItemType LinkedList<ItemType>::retrieveAtPos (int pos)
{
	/*Node<ItemType> * deleteNodePtr;
	Node<ItemType> * prevNodePtr;
	Node<ItemType> * nextNodePtr;
	Node<ItemType> * tempPtr;
	ItemType returnItem;
	if (item == headNodePtr->getItem())
	{
		deleteNodePtr = headNodePtr;
		headNodePtr = headNodePtr->getNext();
		delete deleteNodePtr;
	}
	else
	{
		prevNodePtr = headNodePtr;
		while ((prevNodePtr->getNext() != NULL) && (prevNodePtr->getNext()->getItem() != item))
		{
			prevNodePtr = prevNodePtr->getNext();
		}
		if(prevNodePtr->getNext() != NULL)
		{
			deleteNodePtr = prevNodePtr->getNext();
			nextNodePtr = deleteNodePtr->getNext();
			prevNodePtr->setNext(nextNodePtr);
			tempPtr = deleteNodePtr;
			returnItem = tempPtr->getItem();
			
			delete deleteNodePtr;
			return returnItem;
		}
		else
		{
			cout << "Item not found" << endl;
		}
	}*/

Node<ItemType>* curr = headNodePtr;
   Node<ItemType>* after;
   ItemType temp;
   int counter =0;
        if(pos==0)
        {
                if(headNodePtr==NULL)
                        throw ItemNotFound;
                if(headNodePtr->getNext()==NULL)
                {
                        temp=headNodePtr->getItem();
                        delete headNodePtr;
                        return temp;
                }
        	else
        	{
                	after=headNodePtr;
                	headNodePtr=headNodePtr->getNext();
                	temp=after->getItem();
                	delete after;
                	return temp;
        	}
        }
        else
        {
                curr=headNodePtr;
                while((counter!= pos-1)&&(curr->getNext()!=NULL))
                {
                        curr=curr->getNext();
                        counter++;
                }
                if(curr->getNext()==NULL)
                        throw ItemNotFound;
                else
                {
                        after=curr->getNext();
                        temp=curr->getNext()->getItem();
                        curr->setNext(after->getNext());
                        delete after;
                        return temp;
                }
        }

	
}



 /******************************************************************
 Class LinkedList
 Function:  clear
 Parameters: None
  Removes and deletes all the entries of the list
  Returns void
*******************************************************************/
template<class ItemType>
void LinkedList<ItemType>::clear()
{
	Node<ItemType> * currentPtr;
    currentPtr = headNodePtr;

	Node<int> * nextPtr;
	while (currentPtr != NULL)
	{
		nextPtr = currentPtr->getNext();
		delete currentPtr;
		currentPtr = nextPtr;
	}
	headNodePtr = NULL;
}

#endif
