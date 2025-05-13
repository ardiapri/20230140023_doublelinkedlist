#include <iostream>
using namespace std;

struct Node
{
    //deskripsi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    //deskripsi pointer next dan prev untuk menunjukan ke node berikutnya dan sebelumnya
    Node* next;
    Node* prev;
};

//deklarasi pointer start dan pemberian nilai
Node* START = NULL;
void addNode()
{
    //pemuatan node dan pemberian value untuk data noMhs dan name
    Node* newNode = new Node(); //step1 buat Node baru
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs; //assign value to the field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name; //asign value to the data field of th

    // insert the new node int the list
    // kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    { // insert the new node at the beginning. 2

        if (START == NULL || newNode->noMhs == START->noMhs)
        {
            //step2: insert the new node at the beginning
            // kondisi jika star tidak kosong dan noMhs node baru sama dengan noMhs
            cout << "\033[31mDuplicate roll numbers not allowed\033]0m" << endl;
            return;
        }
        
        //jika list kosong, maka node next nya adalah START
        newNode->next = START; // 3:make the new node point to the
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {
            START->prev = newNode; // 4. make the first node point to the new node
        }
        newNode->prev = NULL; // 5. make the new node point to NULL
        START = newNode;      // 6. make the new node the first node
    }
    else
    {
        // insert the new node in the middle or at the end
        // set nilai current = start dan nilai previous = null 
        Node* current = START; // 1.a start from the first node
        Node* previous = NULL; // 1.b previous node is NULL initially

        // lopping selama current != null noMhs dari current lebih kecil 
        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previous = current;
            current = current->next;
        }
        
        // set nilai next node baru = current dan prey node baru = previous
        newNode->next = current;
        newNode->prev = previous;

        // konidis jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode;
        }

        if (previous != NULL)
        {
            previous->next = newNode;
        }
        else
        {
            // if previous is still NULL, it means NewNode is now the first node 
            START = newNode;
        }
    }
}
// pembuatan function search untuk mencari data
bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}
// pembuatan prosedur delete untuk menghapus data 
void deleteNode()
{
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }
    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }
    
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
}

// method untuk mengecek apakah list kosong
bool listEmpty()
{
    return (START == NULL);
}
