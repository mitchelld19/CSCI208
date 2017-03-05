//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Updates by Marguerite Doman 2014

/** @file StackInterface.h */

#ifndef _STACK_H
#define _STACK_H

#include "Node.h"


template<class ItemType>
class Stack 
{

private:
	Node<ItemType> * topOfStackPtr ;
public:

   /*****************************************************
	METHOD:  Constructor
	****************************************************/
       Stack();

   /*****************************************************
	METHOD:  isEMPTY
		Sees whether this stack is empty.
    RETURNS: True if the stack is empty, or false if not. 
	****************************************************/
    bool isEmpty() ;
   
   /*****************************************************
	METHOD:  PUSH
		Adds a new entry to the top of this stack.
		If the operation was successful, 
	               newEntry is at the top of the stack.
				   
	PARAMETER: newEntry The object to be added as a new entry.
	RETURNS: True if the addition is successful or false if not.
   ****************************************************/
    bool push( ItemType newEntry) ;
   
   
   /*****************************************************
	METHOD:  POP
		Removes the top of this stack.
		If the operation was successful, 
	          the top of the stack has been removed.
	
	PARAMETER: None
	RETURNS: The item removed from the stack
	ERROR RETURNED:  If the stack is empty an error is returned
	        student: define the error you will return here
	****************************************************/
    ItemType pop() ;

};  // end Stack.h

template<class ItemType>
    Stack<ItemType>::Stack(){
		topOfStackPtr = NULL;
	}
	
	template<class ItemType>
    bool Stack<ItemType>::isEmpty(){
		if(topOfStackPtr == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	template<class ItemType>
    bool Stack<ItemType>::push(ItemType newEntry){
		Node<ItemType>* newNodePtr;
		newNodePtr = new Node<ItemType>(newEntry, topOfStackPtr);
		topOfStackPtr = newNodePtr;
		return true;
	}
	
	template<class ItemType>
    ItemType Stack<ItemType>::pop(){
		if(isEmpty()){
			throw 99;
		}
		
		//Remove top Node from stack
		Node<ItemType>* poppedNodePtr;
		poppedNodePtr = topOfStackPtr;
		topOfStackPtr = poppedNodePtr->getNext();
		
		//Save the item from that node to return to caller
		ItemType itemToReturn;
		itemToReturn = poppedNodePtr->getItem();
		
		//delete that Node
		delete poppedNodePtr;
		poppedNodePtr = NULL;
		
		//Return the item to caller
		return itemToReturn;
	}

#endif
