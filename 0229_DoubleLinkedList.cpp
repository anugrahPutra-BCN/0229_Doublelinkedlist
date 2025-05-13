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

        // set nilai next node baru = current dan prev node baru = previous
        newNode->next = current; // step 4: make tjhe nect field of the new node
        newNode->prev = previous; // step 5: make the previous field of the new

        // kondisi jika current tiidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode; // step 6: make the previous field of the 
        }

        // kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous->next = newNode; //step 7: make the next field of the previous
        }
        // kondisi jiika if previous sama dengan null
        else
        {
            // if previous is still NUULL, iit means newNode is now the first node
            START = newNode;
        }
    }
}

// pembuatan function search untuk mencari data 
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return(*current != NULL);
}

// pembuatan prosedur delete untuk menghapus data
void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nenter the roll number of the student whose record is to be delete: ";
    cin >> rollNo; // step 3: get the roll number number to be deleted

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START; // step 1: start from the first node
    previous = NULL;

    // Locate the node to be deleted
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

    // node to be deleted in the first node
    if (current = START)
    {
        START = START->next; // step 2: update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {// node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        { // if there's a succestor, update its prv pointerr
            current->next->prev = previous;
        }
    }

    // release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
}

// method untuk mengecek apakah List kosong
bool listEmpty()
{
    return (START == NULL);
}

// prosedur traverse untuk menampilkan data secara urut
void revtraverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are:" << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

// prosedur untuk mencari data dan menampilkan data yang dicari jiika ada
void searchData()
{
    if (listEmpty() == true)
    {
        cout << "\nList is empty" << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout <<  "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->name << endl;
    }
}


