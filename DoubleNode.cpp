#include <iostream>

template<class ItemType> 
DoubleNode<ItemType>::DoubleNode()
{
    next_ = nullptr;
    prev_ = nullptr;
}


template<class ItemType> 
DoubleNode<ItemType>::DoubleNode(const ItemType &anItem, DoubleNode<ItemType> *nextNodePtr, DoubleNode<ItemType> *previousNodePtr)
{
    item_ = anItem;
    next_ = nextNodePtr;
    prev_ = previousNodePtr;
}


template<class ItemType> 
void DoubleNode<ItemType>::setItem(const ItemType &anItem)
{
    item_ = anItem;
}

template<class ItemType> 
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr)
{
    prev_ = previousNodePtr;
}

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr)
{
    next_ = nextNodePtr;
}

template<class ItemType> 
ItemType DoubleNode<ItemType>::getItem() const
{
    return item_;
}

template<class ItemType> 
DoubleNode<ItemType> *DoubleNode<ItemType>::getNext() const
{
    return next_;
}

template<class ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getPrevious() const
{
    return prev_;
}


