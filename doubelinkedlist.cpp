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
        