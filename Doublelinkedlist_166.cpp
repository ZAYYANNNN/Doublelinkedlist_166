#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class Doublelinkedlist {
private:
	Node* START;
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchdata();
};

Doublelinkedlist::Doublelinkedlist() {
	START = NULL;
}

void Doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;
	Node* newNode = new Node();	//STEP 1
	newNode->noMhs = nim;	//step 2
	newNode->name = nm;		//step 2

	/*insert a node in the beginnin of a doubly - linkedlist*/
	if (START = NULL || nim <= START->noMhs) {
		if (START == NULL && nim <= START->noMhs)
			cout << "\nDuplicate number not allowed" << endl;
		return;
	}
	newNode->next = START; //STEP 3
	if (START != NULL)
		START->prev = newNode;	//STEP 4
	newNode->prev = NULL;	//STEP 5
	START = newNode;	//STEP 6
	return;
}

/*Insert a node between two nodes in the list*/
Node* current = START;	//STEP 1.a
