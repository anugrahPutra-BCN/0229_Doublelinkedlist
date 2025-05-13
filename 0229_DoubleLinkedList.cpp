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

    // Insert the new code in the List 
    //kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning
        // kondisi jika star tidak kosong dan noMhs node baru sama noMhs
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowes\033[0m" << endl;
            return;
        }
        // jika List kosong, maka node next nya adalah START
        newNode->next = START; // step 3: make the new node point to the first node
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {
             START->prev = newNode; // step 4: make the first node point to the
        }
        // memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5: make tthe new node point to NULL
        START = newNode; // step 6: make the new node the first node
    }
    // kondisi jika semua kondiisi if tidak terpenuhi
    else
    {

        //insert the new node in the middle or at the end
        // set nilai current = START dan nilai previous = NULL
        Node *current = START; // dtep 1.a: start from the first node
        Node *previous = NULL; // step 1.b: previous node is null initially
        
        // looping selama current != null dan noMhs dari current lebih kecil 
        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previous = current; // step 1.d: mode the previous to the current
            current = current->next; // step 1.e: move the current to the new node
        }

