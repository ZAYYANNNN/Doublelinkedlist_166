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
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
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
Node* previous = NULL;	//STEP 1.B
while (current->next != NULL && current->next->noMhs < nim)	//Step 1.c
{
	previous = current;	//step 1.d
	current = current->next;	//step 1.e
}

if (current->next != NULL && nim == current->next->noMhs) {
	cout << "\nDuplicate roll numbers not allowed" << endl;
	return;
}

newNode->next = current->next;	//step 4
newNode->prev = current;	//step5
if (current->next != NULL)
	current->next->prev = newNode;	//Step 6
current->next = newNode;

}

bool Doublelinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = START;	//STEP 1.a
	*current = START;	//STEP 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {	//STEP 1.c
		*previous = *current;	//STEP 1.d
		*current = (*current)->next;	//STEP 1.e
	}
	return (current != NULL);
}

bool Doublelinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;	//STEP 2
	if (previous != NULL)
		previous->next = current->next;	//STEP 3
	else
		START = current->next;
	
	delete current;	//STEP 4
	return true;
}

bool Doublelinkedlist::listEmpty() {
	return (START = NULL);
}

void Doublelinkedlist::traverse() {
	if (listEmpty())
		cout << "\nList empty" << endl;
	else {
		cout << "\nRecords in asceding order of roll number are : " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}

}

void Doublelinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;
	}
	else {
		cout << "\nRecords in descending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void Doublelinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nlist is empty" << endl;
	}
	cout << "\nEnter the roll number of the student whose record is to be deleted : ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (Doublelinkedlist::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << "deleted " << endl;
}

void Doublelinkedlist::searchdata() {
	if (listEmpty() == true) {
		cout << "\nlist is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record to you want search : ";
	int num;
	cin >> num;

	if (Doublelinkedlist::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number : " << curr->noMhs << endl;
		cout << "\nName : " << curr->name << endl;

	}
}

int main() {
	Doublelinkedlist obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. view All records in the ascending order of roll numbers" << endl;
			cout << "4. view all records in the descending order of roll numbers" << endl;
			cout << "5. search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6) : ";
			char ch;
			cin >> ch;

			switch (ch) {
			case 1:
				obj.addNode();
				break;
			case 2:
				obj.hapus();
				break;
			case 3:
				obj.traverse();
				break;
			case 4:
				obj.revtraverse();
				break;
			case 5:
				obj.searchdata();
				break;
			case 6:
				return 0;
			deafult:
				cout << "\nInvalid option" << endl;
				break;

			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}

