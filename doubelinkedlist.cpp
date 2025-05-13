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

    