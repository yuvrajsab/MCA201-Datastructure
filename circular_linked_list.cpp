#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class CircularLinkedList {
    public:
        Node *head;
        Node *cursor;

        CircularLinkedList() {
            this->head = NULL;    
            this->cursor = NULL;
        }

        bool isEmpty() {
            return this->head == NULL;
        }

        void add(int value) {
            Node *node = new Node();
            node->data = value;
            node->next = this->head;

            if (!this->isEmpty()) {
                this->cursor->next = node;
            }

            if (this->isEmpty()) {
                this->head = node;
                node->next = this->head;
            }

            this->cursor = node;
        }

        Node *front() {
            if (this->isEmpty()) return NULL;
            return this->cursor;
        }

        Node *back() {
            if (this->isEmpty() || !this->cursor->next) return NULL;
            
            return this->cursor->next;
        }

        void remove() {
            if (this->isEmpty()) return;

            Node *temp = this->back();

            if (this->front()->next == this->front()) { // only one element
                this->cursor = NULL;
                this->head = NULL;
                return delete temp;
            }

            this->front()->next = temp->next;
            this->head = temp->next;

            delete temp;
        }

        void advance() {
            if (this->isEmpty()) return;
            this->cursor = this->cursor->next;
        }

        void traversal() {
            cout<<"Elements in list : ";
            if (this->isEmpty()) return;

            Node *it = this->head;

            do {
				cout<<it->data<<' ';
                it = it->next;
            }
			while(it != this->head);

			cout<<endl;
        }
};

void displayMenu() {
	cout<<"------------------------------"<<endl;
	cout<<"Choice | Operation"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"   1   | Add"<<endl;
	cout<<"   2   | Remove"<<endl;
	cout<<"   3   | Front"<<endl;
	cout<<"   4   | Back"<<endl;
	cout<<"   5   | Advance"<<endl;
	cout<<"   6   | Print List"<<endl;
	cout<<"   0   | Exit"<<endl<<endl;
}

void handleChoice(CircularLinkedList *list, int choice) {
	int val;
	switch (choice) {
		case 1:
			cout<<"Enter value to be inserted ";
			cin>>val;
			
			list->add(val);
			break;

		case 2:
			list->remove();
			break;
		
		case 3:
			cout<<"Front value is ";
			cout<<list->front()->data<<endl;
			break;

		case 4:
			cout<<"Back value is ";
			cout<<list->back()->data<<endl;
			break;
		
		case 5:
			list->advance();
            cout<<"Now cursor is pointing to "<<list->front()->data<<endl;
			break;

		case 6:
			list->traversal();
            break;
	
		default:
			exit(0);
	}
}

int main() {
    CircularLinkedList *c = new CircularLinkedList();
    
    int choice;

    while (true) {
        displayMenu();
        cin>>choice;
        handleChoice(c, choice);
    }
    

    return 0;
}