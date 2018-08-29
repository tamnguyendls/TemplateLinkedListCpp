#include <iostream>
#include <ctime>

#include "List.h"
#include "ListNode.h"
#include "Tree.h"
#include "TreeNode.h"

using namespace std;

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

int main()
{
    TestFunction();
}