#include <iostream>
#include "DoubleNode.hpp"
template<class ItemType> 
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
    headPtr_ = nullptr;
    itemCount_ = 0;
}


template<class ItemType> DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &aList)
{
    itemCount_ = aList.getSize();
    DoubleNode<ItemType>* origChainPtr = aList.getHeadPtr();
    for (int i = 1; i < itemCount_+ 1; i++)
    {
        insert(origChainPtr->getItem(),i);
        origChainPtr=origChainPtr->getNext();
    }
    
}
template<class ItemType> DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

template<class ItemType> int DoublyLinkedList<ItemType>::getSize() const
{
    return itemCount_;
}


template<class ItemType> 
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
    if ((pos >= 1) && (pos <= itemCount_)){

        DoubleNode<ItemType>* curPtr = headPtr_;
        for (int skip = 1; skip < pos; skip++){
            curPtr = curPtr->getNext();
        }
        return curPtr; 
    }
    return nullptr;
    
}


template<class ItemType> DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const
{
   return headPtr_;
}

template<class ItemType> bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{

    bool ableToInsert = (position >= 1) && (position <= itemCount_ + 1);
    if (ableToInsert) {
        DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(item);
        if (position == 1) 
        {
            newNodePtr->setNext(headPtr_);
            headPtr_ = newNodePtr; 
        }
        else
        {
            DoubleNode<ItemType>* prevPtr = getAtPos(position-1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr); 
            newNodePtr->setPrevious(prevPtr);
            
        } // end if
    }

    itemCount_++; // Increase count of entries } // end if
    return ableToInsert;

    
    }



template<class ItemType> bool DoublyLinkedList<ItemType>::remove(const int &position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount_); 
    if (ableToRemove){
        DoubleNode<ItemType>* curPtr = nullptr; 
        if (position == 1)
        {
            curPtr = headPtr_; // Save pointer to node 
            headPtr_ = headPtr_->getNext();
        }
        else if (position > 1 && position != itemCount_)
        
        {
            DoubleNode<ItemType>* prevPtr = getAtPos(position-1);
            //DoubleNode<ItemType>* nextPtr = getAtPos(position+1);

            // Point to node to delete
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
            //nextPtr->setPrevious(prevPtr);

            // Disconnect indicated node from chain by connecting the // prior node with the one after prevPtr->setNext(curPtr->getNext());
        }
        
        
        

        curPtr->setNext(nullptr);
        delete curPtr; 
        curPtr = nullptr;
        itemCount_ --;//= itemCount_ - 1; 
    }
    return ableToRemove;
    
}
    
    


template<class ItemType> bool DoublyLinkedList<ItemType>::isEmpty() const
{
    if(itemCount_ == 0)
    {
        return true;
    }
}

template<class ItemType> void DoublyLinkedList<ItemType>::clear()
{
   while (itemCount_ != 0){
       remove(1);
       itemCount_--;
   } 
   headPtr_ = nullptr;
}


template<class ItemType> void DoublyLinkedList<ItemType>::display() const
{  
    DoubleNode<ItemType> *CurPtr = headPtr_;    
    while (CurPtr->getNext() != nullptr)
    {
            std::cout << CurPtr->getItem() << " ";
            CurPtr = CurPtr->getNext();
    }
    std::cout << CurPtr->getItem() << std::endl;
    


}

    


template<class ItemType> void DoublyLinkedList<ItemType>::displayBackwards() const
{
    
    DoubleNode<ItemType>*n = headPtr_;
    while (n->getNext() != nullptr)
    {
        n = n->getNext();
    }
    
    while (n != headPtr_)
    {
        std::cout << n->getItem() << " ";
        n = n->getPrevious();
    }
    
    std::cout << n->getItem() << std::endl;
     
}

template<class ItemType> void DoublyLinkedList<ItemType>::invert()
{
    DoubleNode<ItemType> *temp = nullptr;
    DoubleNode<ItemType> *current = headPtr_;
     
    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != nullptr)
    {
        temp = current->getPrevious();
        current->setPrevious(current->getNext());
        current->setNext(temp);            
        current = current->getPrevious();
    }
     
    /* Before changing the head, check for the cases like empty
        list and list with only one node */
    if(temp != nullptr )
        headPtr_ = temp->getPrevious();
}
