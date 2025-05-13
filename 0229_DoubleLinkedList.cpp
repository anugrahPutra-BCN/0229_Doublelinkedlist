#include <iostream>
using namespace std;

// membuat  struktur umtuk object double LinkedList
struct Node
{
    // deklarasi noMhs dan name untuk menampung data 
    int noMhs;
    string name;
    // deklarasi pointer next dan prev untuk penunjukan data sebelum dan sesudah
    Node*next;
    Node *prev; 
};

// deklarasi pointer START dan pemberian nilai
Node *START = NULL;

// deklarasi prosedur addNode
void addNode()
{

    // pembuatan node dan pemberian value untuk data noMhs dan name
    Node *newNode = new Node(); // step 1 buat noode baru
    cout << "\nEnter the roll number of the student :";
    cin >> newNode->noMhs; // menetapkan nilai ke bidang data node baru
    cout << "\nEnter the name of the student :";
    cin >> newNode->name; // assign value to the data field of th

   