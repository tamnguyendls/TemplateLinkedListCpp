#include "LinkedList.h"

////////////////////////////////////////////////////////////////////////////////////////

template <class T>
LinkedListNode<T>::LinkedListNode(T tDataIn)
{
    m_Data = tDataIn; //stores data in node
    m_pNextNode = 0; //initializes point to next node to null
}

template <class T>
T LinkedListNode<T>::GetValue() //returns data stored in node
{
    return m_Data;
}

////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
LinkedList<T>::LinkedList()
{
    m_pBefore = NULL;
    m_pAfter = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    if (!isEmpty()) // List is not empty
    {
        LinkedListNode<T> *currentPtr = m_pBefore;
        LinkedListNode<T> *tempPtr;

        while (currentPtr != 0) // delete remaining nodes
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->m_pNextNode;
            delete tempPtr;
        }
    }
}

template <class T>
LinkedListNode<T> LinkedList<T>::AddAfter(LinkedListNode<T> node, T value)
{
    //TODO:
}

template <class T>
void LinkedList<T>::AddAfter(LinkedListNode<T> node, LinkedListNode<T> newNode)
{
    //TODO:
}

template <class T>
LinkedListNode<T> LinkedList<T>::AddLast(T value)
{

}

template <class T>
void LinkedList<T>::AddLast(LinkedListNode<T> node)
{

}

template <class T>
void LinkedList<T>::Clear()
{

}

template <class T>
LinkedListNode<T> LinkedList<T>::Find(T value)
{

}

template <class T>
LinkedListNode<T> LinkedList<T>::FindLast(T value)
{

}

template <class T>
bool LinkedList<T>::Remove(T value)
{

}

template <class T>
void LinkedList<T>::Remove(LinkedListNode<T> node)
{

}

template <class T>
void LinkedList<T>::RemoveLast()
{

}

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (m_pBefore == NULL && m_pAfter == NULL) //if the start pointer and end pointer are NULL then the list is empty
        return 1;
    else
        return 0;
}



