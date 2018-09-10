#include <iostream>
#include <ctime>
#include "LinkedList.h"

using namespace std;

#if 0
bool  TestFunction()
{
    int choice = 0;

    //create function array of 10 random numbers between 0 and 100
    const int size = 10;
    int arr[size];
    srand(time(0)); //time is used as the random seed
    for (int i = 0; i <= size - 1; i++)
    {
        arr[i] = rand() % 101; //assigns random number in array
    }

    List<int> intList; //creates order linked list
    for (int i = 0; i <= size - 1; i++)
    {
        intList.insertNewNode(arr[i]); //inserts value from array to the linked list in the proper positions
    }

    Tree<int> intTree; //create binary tree
    for (int i = 0; i <= size - 1; i++)
    {
        intTree.insertNewNode(arr[i]); //inserts value from array to the binry tree in the same order entered
    }

    while (choice != 7)
    {
        //displays initial array of values
        cout << "Initial Array of Values" << endl;
        cout << "-----------------------" << endl;
        for (int i = 0; i <= size - 1; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl << endl;

        //menu of options to perform 
        cout << "Linked Lists and Trees" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Print Linked List" << endl;
        cout << "2. Search For Entry In Linked List" << endl;
        cout << "3. Print Pre-Ordered Traverseal of Tree" << endl;
        cout << "4. Print In-Order Traversal of Tree" << endl;
        cout << "5. Print Post-Order Traversal of Tree" << endl;
        cout << "6. Search For Entry In Tree" << endl;
        cout << "7. EXIT" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        system("cls");

        int key; //search key used for both the search of linked list and binary tree

        ListNode<int>* posList; //node pointer used to store a pointer to node returned from the linked list search function

        TreeNode<int>* posTree; //node pointer used to store a pointer to node returned from the binary tree search function

        switch (choice)
        {
        case 1:
            cout << "Output of a Sorted Linked List" << endl;
            cout << "------------------------------" << endl;
            intList.print(); //prints contents of linked list
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Searching In a Linked List" << endl;
            cout << "--------------------------" << endl;
            //prompt for search key
            cout << "Enter a a search key: ";
            cin >> key;
            posList = intList.search(key); //stores pointer to list node object
            cout << "The value of pointer is " << posList << endl;
            if (posList != NULL) //if not null then the value was found
                cout << "The value stored at this posistion is " << posList->getData() << endl;
            else
                cout << "The pointer to this position is NULL so there can be no value stored" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Pre-Ordered Traverseal of Tree" << endl;
            cout << "------------------------------" << endl;
            intTree.preOrderPrint(); //print pre ordered traversal of binary tree
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "In-Ordered Traverseal of Tree" << endl;
            cout << "------------------------------" << endl;
            intTree.inOrderPrint(); //print in ordered traversal of binary tree
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Post-Ordered Traverseal of Tree" << endl;
            cout << "------------------------------" << endl;
            intTree.postOrderPrint(); //print post ordered traversal of binary tree
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Searching In a Tree" << endl;
            cout << "-------------------" << endl;
            //prompt for search key
            cout << "Enter a a search key: ";
            cin >> key;
            posTree = intTree.search(key); //stores pointer to tree node object
            cout << "The value of pointer is " << posTree << endl;
            if (posTree != NULL) //if not null then the value was found
                cout << "The value stored at this posistion is " << posTree->getData() << endl;
            else
                cout << "The pointer to this position is NULL so there can be no value stored" << endl;
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Thanks for using my test program for Linked Lists and Trees" << endl;
            system("pause");
            system("cls");

        }
    }
    return false;
}
#endif 

void TestAddLast_Value()
{
    int choice = 0;

    const int size = 10;
    int arr[size];
    srand(time(0));
    for (int i = 0; i <= size - 1; i++)
    {
        arr[i] = rand() % 101;
    }

    LinkedList<int> pNewList;
    for (int i = 0; i <= size - 1; i++)
    {
        pNewList.AddLast(arr[i]);
    }

    pNewList.Print();

    system("pause");
}

void TestAddLast_Node()
{
    int arr[] = { 52, 80, 94, 26, 23, 89, 32, 50, 22, 23 };

    LinkedList<int> pNewList;
    for (int i = 0; i < 10; i++)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(arr[i]);
        pNewList.AddLast(newNode);
        printf("\nCount = %d\n", pNewList.Count());

    }

    pNewList.Print();
    printf("\nCount = %d\n", pNewList.Count());
    system("pause");

}

void TestFind_Node()
{
    int arr[] = { 52, 80, 94, 26, 23, 89, 32, 50, 22, 23 };

    LinkedListNode<int> * nodeFound = NULL;
    LinkedList<int> pNewList;
    for (int i = 0; i < 10; i++)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(arr[i]);
        pNewList.AddLast(newNode);
    }

    nodeFound = pNewList.Find(50);
    printf("\nNode found = %x\n", nodeFound);
    printf("\nNode value = %d\n", nodeFound->GetValue());
    system("pause");
}

void TestAddNewNodeAfterExistingNode()
{
    int arr[] = { 52, 80, 94, 26, 23, 89, 32, 50, 22, 23 };

    LinkedListNode<int> * existingNode = NULL;
    LinkedListNode<int> * nodeAdded = NULL;
    LinkedList<int> pNewList;
    for (int i = 0; i < 10; i++)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(arr[i]);
        pNewList.AddLast(newNode);
    }

    // Before adding
    pNewList.Print();
    printf("Count = %d\n", pNewList.Count());

    // Adding
    existingNode = pNewList.Find(22);
    nodeAdded = pNewList.AddAfter(existingNode, 100);

    printf("\nNode found = %x\n", nodeAdded);
    printf("Node value = %d\n", nodeAdded->GetValue());

    // After adding
    pNewList.Print();
    printf("Count = %d\n", pNewList.Count());
    
    //
    LinkedListNode<int> *node = new LinkedListNode<int>(200);
    if (pNewList.AddAfter(pNewList.Find(94), node) == true)
    {
        printf("\nAdd node to list successfully\n");
        pNewList.Print();
        printf("Count = %d\n", pNewList.Count());
    }

    system("pause");
}

void TestAddNewNodeWithString()
{
    char * sTestTring1 = "this is a test";
    LinkedListNode<char*> *newNode1 = new LinkedListNode<char*>(sTestTring1);
    LinkedList<char*> pNewList;

    pNewList.AddLast(newNode1);

    char * sTestTring2 = "For linked list";
    LinkedListNode<char*> *newNode2 = new LinkedListNode<char*>(sTestTring2);
    pNewList.AddLast(newNode2);

    pNewList.Print();

    system("pause");
}

void TestAddFirst_Value()
{
    printf("\nTestAddFirst_Value\n");

    int arr[] = { 52, 80, 94, 26, 23, 89, 32, 50, 22, 23 };
    int size = sizeof(arr) / sizeof(int);
    LinkedList<int> pNewList;

    for (int i = 0; i <= size - 1; i++)
    {
        pNewList.AddFirst(arr[i]);
    }

    pNewList.Print();

    char * firstString[] = { "the", "fox", "jumped", "over", "the", "dog" };
    LinkedList<char*> pStringList;
    
    for (int i = 0; i <= 6 - 1; i++)
    {
        pStringList.AddFirst(firstString[i]);
    }
    pStringList.Print();

    //system("pause");
}

void TestAddFirst_Node()
{
    printf("\nTestAddFirst_Node\n");

    int arr[] = { 1, 4, 9, 18, 33, 72, 45, 19, 56, 83 };

    LinkedList<int> pNewList;
    for (int i = 0; i < 10; i++)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(arr[i]);
        pNewList.AddFirst(newNode);
    }

    pNewList.Print();
    printf("Count = %d\n", pNewList.Count());

    char * firstString[] = { "the", "cat", "caught", "the", "big", "fish" };
    LinkedList<char*> pStringList;
    for (int i = 0; i <= 6 - 1; i++)
    {
        LinkedListNode<char*> *newNode = new LinkedListNode<char*>(firstString[i]);
        pStringList.AddFirst(newNode);
    }

    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
    system("pause");
}

void TestRemoveFirst()
{
    printf("\nTestRemoveFirst\n");
    char * firstString[] = { "the", "cat", "caught", "the", "big", "fish" };
    LinkedList<char*> pStringList;

    for (int i = 0; i < 6; i++)
    {
        LinkedListNode<char*> *newNode = new LinkedListNode<char*>(firstString[i]);
        pStringList.AddLast(newNode);
    }

    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
    
    pStringList.RemoveFirst();
    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
    
    system("pause");
}

void TestRemove_T_Value()
{
    printf("\nTestRemove_T_Value\n");
    char * firstString[] = { "the", "cat", "caught", "the", "big", "fish" };
    LinkedList<char*> pStringList;

    for (int i = 0; i < 6; i++)
    {
        LinkedListNode<char*> *newNode = new LinkedListNode<char*>(firstString[i]);
        pStringList.AddLast(newNode);
    }

    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());

    pStringList.Remove("fish");
    pStringList.Remove("the");
    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());

    //system("pause");
}

void TestRemoveFistRemoveLast()
{
    printf("\nTestRemoveFistRemoveLast\n");
    char * firstString[] = { "the", "cat", "caught", "the", "big", "fish" };
    LinkedList<char*> pStringList;

    for (int i = 0; i < 6; i++)
    {
        LinkedListNode<char*> *newNode = new LinkedListNode<char*>(firstString[i]);
        pStringList.AddLast(newNode);
    }

    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
    pStringList.RemoveFirst();
    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
    pStringList.RemoveLast();
    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
}

void TestClearList()
{
    printf("\nTestClearList\n");
    char * firstString[] = { "the", "cat", "caught", "the", "big", "fish" };
    LinkedList<char*> pStringList;

    for (int i = 0; i < 6; i++)
    {
        LinkedListNode<char*> *newNode = new LinkedListNode<char*>(firstString[i]);
        pStringList.AddLast(newNode);
    }

    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());

    pStringList.Clear();
    pStringList.Print();
    printf("Count = %d\n", pStringList.Count());
    system("pause");
}

void UnitTestMyLinkedList()
{
    //TestAddLast_Value();
    //TestAddLast_Node();
    //TestFind_Node();
    //TestAddNewNodeAfterExistingNode();
    //TestAddNewNodeWithString();
    //TestAddFirst_Value();
    //TestAddFirst_Node();
    //TestRemoveFirst();
    TestRemove_T_Value();
    TestRemoveFistRemoveLast();
    TestClearList();
}


int main()
{
    //TestFunction();

    UnitTestMyLinkedList();
}