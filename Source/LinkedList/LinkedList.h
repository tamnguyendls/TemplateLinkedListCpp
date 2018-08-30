#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedListNode
{
public:
    LinkedListNode(T value);
    //LinkedList<T> GetList();
    //LinkedListNode<T> GetNext();
    //LinkedListNode<T> GetPrevious();
    //T SetValue(T value);
    T GetValue();

private:
    T m_Data; //templatized data stored in node
    LinkedListNode * m_pNextNode; //pointer to the next node in list
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    ////LinkedList(IEnumerable<T> collection);
    ////LinkedList(SerializationInfo info, StreamingContext context);

    //int Count{ get; }
    //LinkedListNode<T> GetFirst();
    //LinkedListNode<T> GetLast();

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
    LinkedListNode<T> AddAfter(LinkedListNode<T> node, T value);

    //
    // Summary:
    //     Adds the specified new node after the specified existing node in the LinkedList
    // Parameters:
    //   node:
    //     The LinkedListNode after which to insert newNode.
    //   newNode:
    //     The new LinkedListNode to add to the LinkedList
    void AddAfter(LinkedListNode<T> node, LinkedListNode<T> newNode);

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
    LinkedListNode<T> AddLast(T value);
    //
    // Summary:
    //     Adds the specified new node at the end of the LinkedList
    // Parameters:
    //   node:
    //     The new LinkedListNode to add at the end of the LinkedList
    void AddLast(LinkedListNode<T> node);
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
    LinkedListNode<T> Find(T value);

    //
    // Summary:
    //     Finds the last node that contains the specified value.
    // Parameters:
    //   value:
    //     The value to locate in the LinkedList
    // Returns:
    //     The last LinkedListNode that contains the specified value, if found; otherwise, null.
    LinkedListNode<T> FindLast(T value);

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

private:
    LinkedListNode<T> *m_pBefore;   //stores the pointer of first object in the linked list
    LinkedListNode<T> *m_pAfter;    //stored the pointer of the last object in the linked list
    bool isEmpty();                 //utility functions used to see if the list contains no elements
    void insertBefore(T);           //inserts new node before the first node in the list
    void insertAfter(T);            //inserts new node after the last node in the list
};

#endif // LINKED_LIST_H