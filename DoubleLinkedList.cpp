#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
         START = NULL;  
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *newNode = new Node();

        newNode->noMhs = nim;

        if (START == NULL|| nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            newNode->next = START;
        
            if (START != NULL)
                START->prev = newNode;
            
            newNode->prev = NULL;
            
            START = newNode;
            return;
        }

        Node *current = START;
        while (current->next != NULL && nim == current->next->noMhs < nim)
        {
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        current->next->prev = newNode;
        current->next = newNode;
    }
    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
           current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        
        }

        if (current == START)
        {
            START = current->next;
            if(START != NULL)
               START->prev = NULL;
        }
        else
        {
            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        delete current;
        cout << "record whit roll number " << rollNo << " delete" << endl;
    }
    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nlist is empty" << endl;
            return;
        }

        Node *currentNode = START;

        cout << "\nRecords in ascending order of rool number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }
        cout <<"\nRecord is descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". "<< currentNode->noMhs << " " << endl;

            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

         Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current ==NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record not found\n";
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {

        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Recording\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";

        }
         cout << "\nPress Enter to continue...";
         cin.get();
         cin.ignore();
         cout << endl;
         system("clear");
     } while (choice != '6');
}