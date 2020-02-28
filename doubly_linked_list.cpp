#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;
};

class DoublyLinkedList {
    public:
        Node *head;
        Node *current;

        DoublyLinkedList() {
            this->head = NULL;    
            this->current = NULL;
        }

        bool isEmpty() {
            return this->head == NULL;
        }

        void insertEnd(int value) {
            Node *node = new Node();
            node->data = value;
            node->next = NULL;

            if (!this->isEmpty()) {
                node->prev = this->current;
                this->current->next = node;
            }

            if (this->isEmpty()) {
                this->head = node;
            }

            this->current = node;
        }

        void deleteEnd() {
            if (this->isEmpty()) return;

            Node *temp = this->current;

            this->current->prev->next = NULL;
            this->current = this->current->prev;

            delete temp;
        }


        void traversal() {
            if (this->isEmpty()) return;

            Node *it = this->head;
            cout<<"Elements in list : ";
			while(!! it) {
				cout<<it->data<<' ';
				it = it->next;
			}
			cout<<endl;
        }

        void reverse() {
            if (this->isEmpty()) return;

            Node *curr = this->head;
            Node *prev = NULL;
            Node *next = NULL;

            while(!! curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            this->head = prev;
        }


};


void displayMenu() {
	cout<<"------------------------------"<<endl;
	cout<<"Choice | Operation"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"   1   | Insert"<<endl;
	cout<<"   2   | Delete"<<endl;
	cout<<"   3   | Reverse"<<endl;
	cout<<"   4   | Print List"<<endl;
	cout<<"   0   | Exit"<<endl<<endl;
}

void handleChoice(DoublyLinkedList *list, int choice) {
	int val;
	switch (choice) {
		case 1:
			cout<<"Enter value to be inserted ";
			cin>>val;
			
			list->insertEnd(val);
			break;

		case 2:
			list->deleteEnd();
			break;
		
		case 3:
			list->reverse();
			break;

		case 4:
			list->traversal();
			break;
		
		default:
			exit(0);
	}
}

int main() {
    DoublyLinkedList *d = new DoublyLinkedList();
    
    int choice;
	
	while (true) {
		displayMenu();
		cin>>choice;
		handleChoice(d, choice);
	}

    return 0;
}