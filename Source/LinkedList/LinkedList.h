#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//  DECLARATION
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class LinkedListNode
{
public:
    LinkedListNode(T value);
    //LinkedList<T> GetList();
    LinkedListNode<T> * GetNext();
    void SetNext(LinkedListNode<T> * node);
    //LinkedListNode<T> GetPrevious();
    //T SetValue(T value);
    T GetValue();

private:
    T m_Data; //templatized data stored in node
    LinkedListNode<T> * m_pNextNode; //pointer to the next node in list
};

////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    ////LinkedList(IEnumerable<T> collection);
    ////LinkedList(SerializationInfo info, StreamingContext context);

    int Count();
    LinkedListNode<T> * First();
    LinkedListNode<T> * Last();

    //
    // Summary:
    //     Adds a new node containing the specified value after the specified existing node
    //     in the LinkedList
    // Parameters:
    //     node:
    //         The LinkedListNode after which to insert a new LinkedListNode containing value.
    //     value:
    //         The value to add to the LinkedList
    // Returns:
    //     The new LinkedListNode containing value.
    LinkedListNode<T> * AddAfter(LinkedListNode<T> * node, T value);

    //
    // Summary:
    //     Adds the specified new node after the specified existing node in the LinkedList
    // Parameters:
    //   node:
    //     The LinkedListNode after which to insert newNode.
    //   newNode:
    //     The new LinkedListNode to add to the LinkedList
    bool AddAfter(LinkedListNode<T> * node, LinkedListNode<T> * newNode);

    //LinkedListNode<T> AddBefore(LinkedListNode<T> node, T value);
    //void AddBefore(LinkedListNode<T> node, LinkedListNode<T> newNode);
    //LinkedListNode<T> AddFirst(T value);
    //void AddFirst(LinkedListNode<T> node);

    //
    // Summary:
    //     Adds a new node containing the specified value at the end of the LinkedList`
    // Parameters:
    //   value:
    //     The value to add at the end of the LinkedList
    // Returns:
    //     The new LinkedListNode containing value.
    LinkedListNode<T> * AddLast(T value);
    //
    // Summary:
    //     Adds the specified new node at the end of the LinkedList
    // Parameters:
    //   node:
    //     The new LinkedListNode to add at the end of the LinkedList
    void AddLast(LinkedListNode<T> * node);
    //
    // Summary:
    //     Removes all nodes from the LinkedList
    void Clear();
    //bool Contains(T value);
    //void CopyTo(T[] array, int index);

    //
    // Summary:
    //     Finds the first node that contains the specified value.
    // Parameters:
    //   value:
    //     The value to locate in the LinkedList
    // Returns:
    //     The first LinkedListNode that contains the specified value, if found; otherwise, null.
    LinkedListNode<T> * Find(T value);

    //
    // Summary:
    //     Finds the last node that contains the specified value.
    // Parameters:
    //   value:
    //     The value to locate in the LinkedList
    // Returns:
    //     The last LinkedListNode that contains the specified value, if found; otherwise, null.
    LinkedListNode<T> * FindLast(T value);

    //Enumerator GetEnumerator();
    //virtual void GetObjectData(SerializationInfo info, StreamingContext context);
    //virtual void OnDeserialization(object sender);

    //
    // Summary:
    //     Removes the first occurrence of the specified value from the LinkedList
    // Parameters:
    //   value:
    //     The value to remove from the LinkedList
    // Returns:
    //     true if the element containing value is successfully removed; otherwise, false.
    //     This method also returns false if value was not found in the original LinkedList
    bool Remove(T value);

    //
    // Summary:
    //     Removes the specified node from the LinkedList
    // Parameters:
    //   node:
    //     The LinkedListNode to remove from the LinkedList
    void Remove(LinkedListNode<T> node);
    //void RemoveFirst();

    //
    // Summary:
    //     Removes the node at the end of the LinkedList
    void RemoveLast();

    void Print(); //prints the contents of the linked list
private:
    LinkedListNode<T> *m_pStart;   //stores the pointer of first object in the linked list
    LinkedListNode<T> *m_pEnd;    //stored the pointer of the last object in the linked list
    bool findNodeInList(LinkedListNode<T> * node);
    int m_NumberOfNodes;
    bool isEmpty();                 //utility functions used to see if the list contains no elements
    void beginInsert(T);           //inserts new node before the first node in the list
    void endInsert(T);            //inserts new node after the last node in the list
};

////////////////////////////////////////////////////////////////////////////////////////
//  IMPLEMENTATION
////////////////////////////////////////////////////////////////////////////////////////

template <class T>
LinkedListNode<T>::LinkedListNode(T value)
{
    m_Data = value; //stores data in node
    m_pNextNode = 0; //initializes point to next node to null
}

template <class T>
T LinkedListNode<T>::GetValue() //returns data stored in node
{
    return m_Data;
}

template <class T>
LinkedListNode<T> * LinkedListNode<T>::GetNext() //returns data stored in node
{
    return m_pNextNode;
}

template <class T>
void LinkedListNode<T>::SetNext(LinkedListNode<T> * node) //returns data stored in node
{
    m_pNextNode = node;
}

////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
LinkedList<T>::LinkedList()
{
    //creates list with start and end as NULL
    m_pStart = NULL;
    m_pEnd = NULL;
    m_NumberOfNodes = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    if (!isEmpty()) // List is not empty
    {
        LinkedListNode<T> *currentPtr = m_pStart;
        LinkedListNode<T> *tempPtr;

        while (currentPtr != 0) // delete remaining nodes
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->GetNext();
            delete tempPtr;
        }
    }
}

template <class T>
int LinkedList<T>::Count()
{
    return m_NumberOfNodes;
}

template <class T>
LinkedListNode<T> * LinkedList<T>::First()
{
    return m_pStart;
}

template <class T>
LinkedListNode<T> * LinkedList<T>::Last()
{
    return m_pEnd;
}

template <class T>
LinkedListNode<T> * LinkedList<T>::AddAfter(LinkedListNode<T> * node, T value)
{
    LinkedListNode<T> * p_NewNode = NULL;
    LinkedListNode<T> * p_ExistingNode = node;

    if (p_ExistingNode == NULL)
    {
        return NULL;
    }
    
    if (findNodeInList(p_ExistingNode) == true)
    {
        p_NewNode = new LinkedListNode<T>(value);
        p_NewNode->SetNext(p_ExistingNode->GetNext());
        p_ExistingNode->SetNext(p_NewNode);
        m_NumberOfNodes++;
    }

    return p_NewNode;
}

template <class T>
bool LinkedList<T>::AddAfter(LinkedListNode<T> * node, LinkedListNode<T> * newNode)
{
    LinkedListNode<T> * p_ExistingNode = node;

    if ((p_ExistingNode == NULL) || (newNode == NULL))
    {
        return false;
    }
    
    if (findNodeInList(p_ExistingNode) == true)
    {
        newNode->SetNext(p_ExistingNode->GetNext());
        p_ExistingNode->SetNext(newNode);
        m_NumberOfNodes++;
        return true;
    }
}

template <class T>
LinkedListNode<T> * LinkedList<T>::AddLast(T value)
{
    LinkedListNode<T> * p_NewNode = NULL;

    if (isEmpty()) //if the list is empty create first element of the list (same as first case in insert at begin)
    {
        p_NewNode = new LinkedListNode<T>(value);
        m_pStart = p_NewNode;
        m_pEnd = p_NewNode;
        m_NumberOfNodes++;
    }
    else //if node(s) exist in the list then insert new node at the end of the list
    {
        p_NewNode = new LinkedListNode<T>(value);
        m_pEnd->SetNext(p_NewNode); //the current last node's next pointer points to the new node
        m_pEnd = p_NewNode; //the new node is now the last node in the list
        m_NumberOfNodes++;
    }

    return p_NewNode;
}

template <class T>
void LinkedList<T>::AddLast(LinkedListNode<T> * node)
{
    if (isEmpty()) //if the list is empty create first element of the list (same as first case in insert at begin)
    {
        m_pStart = node;
        m_pEnd = node;
        m_NumberOfNodes++;
    }
    else //if node(s) exist in the list then insert new node at the end of the list
    {
        m_pEnd->SetNext(node); //the current last node's next pointer points to the new node
        m_pEnd = node; //the new node is now the last node in the list
        m_NumberOfNodes++;
    }
}

template <class T>
void LinkedList<T>::Clear()
{

}

template <class T>
LinkedListNode<T> * LinkedList<T>::Find(T value)
{
    LinkedListNode<T>* nodePtr = NULL;
    bool found = false;

    nodePtr = m_pStart;

    while ((!found) && (nodePtr != NULL)) //runs through list until data is found within a node or end of list is reached
    {
        if (nodePtr->GetValue() == value) //if the node's data equals the key then the node has been found
            found = true;
        else
            nodePtr = nodePtr->GetNext(); //moves to next node in list
    }
    return nodePtr; //returns pointer to the node that contains data equal to key (NULL if not found)
}

template <class T>
LinkedListNode<T> * LinkedList<T>::FindLast(T value)
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
void LinkedList<T>::Print()
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        LinkedListNode<T> * currentPtr = m_pStart;

        cout << "The contents of the list is: ";
        while (currentPtr != NULL) //prints until the end of the list is reached
        {
            cout << currentPtr->GetValue() << ' ';
            currentPtr = currentPtr->GetNext(); //moves to next node in list
        }
        cout << endl;
    }
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (m_pStart == NULL && m_pEnd == NULL) //if the start pointer and end pointer are NULL then the list is empty
        return 1;
    else
        return 0;
}

template <class T>
void LinkedList<T>::beginInsert(T inData)
{
    if (isEmpty())
    {
        LinkedListNode<T> * p_NewNode = new LinkedListNode<T>(inData);
        m_pStart = p_NewNode;
        m_pEnd = p_NewNode;
    }
    else
    {
        LinkedListNode<T> * p_NewNode = new LinkedListNode<T>(inData);
    }
}

template <class T>
bool LinkedList<T>::findNodeInList(LinkedListNode<T> * node)
{
    LinkedListNode<T>* nodePtr = m_pStart;
    bool bFound = false;

    while ((!bFound) && (nodePtr != NULL)) //runs through list until data is found within a node or end of list is reached
    {
        if (nodePtr == node) //if the node's data equals the key then the node has been found
            bFound = true;
        else
            nodePtr = nodePtr->GetNext(); //moves to next node in list
    }

    return bFound; //returns pointer to the node that contains data equal to key (NULL if not found)
}
////////////////////////////////////////////////////////////////////////////////////////


#endif // LINKED_LIST_H