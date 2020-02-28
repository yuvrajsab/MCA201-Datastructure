#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class SingleLinkedList {
    public:
        Node *head;
        Node *current;

        SingleLinkedList() {
            this->head = NULL;    
            this->current = NULL;
        }

        bool isEmpty() {
            return this->head == NULL;
        }

        void insertFront(int value) {
            if (this->isEmpty()) return this->insertEnd(value);

            Node *node = new Node();
            node->data = value;
            node->next = this->head;
            
            this->head = node;
        }

        void insertEnd(int value) {
            Node *node = new Node();
            node->data = value;
            node->next = NULL;

            if (!this->isEmpty()) {
                this->current->next = node;
            }

            if (this->isEmpty()) {
                this->head = node;
            }

            this->current = node;
        }

        void insertMiddle(int pos, int value) {
            if (this->isEmpty()) return;

            if (pos == 0) return this->insertFront(value);

            Node *it = this->getNode(pos - 1);// get previous node of pos
            
            if (!it) return;

            if (it == this->current) return this->insertEnd(value);
         
            Node *node = new Node();
            node->data = value;
            node->next = it->next;

            it->next = node;
        }

        Node *getNode(int pos) {
            if (this->isEmpty()) return NULL;

            Node *it = this->head;
            for (int i = 0; i < pos; i++) {
                it = it->next;
                if (!it) return NULL;
            }

            return it; // return NULL if pos > size
        }

        void deleteEnd() {
            if (this->isEmpty()) return;

            Node *it = this->head;
            while(it->next != this->current) {
				it = it->next;
			}

            Node *temp = this->current;
            this->current = it;
            this->current->next = NULL;

            delete temp;
        }

        void deleteFront() {
            if (this->isEmpty()) return;

            Node *temp = this->head;
            this->head = this->head->next;

            delete temp;
        }

        void deleteMiddle(int pos) {
            if (this->isEmpty()) return;

            if (pos == 0) return this->deleteFront();
            Node *it = this->getNode(pos - 1);

            if (!it) return;

            if (it == this->current) return;

            Node *temp = it->next;
            it->next = it->next->next;
            
            delete temp;
        }

        void swap(int pos) {
            Node *prev = this->getNode(pos - 1);
            Node *curr = prev->next;

            Node *temp = prev->next;
            prev->next = curr->next;

            Node *t = curr->next->next;
            curr->next->next = temp;
            temp->next = t;
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

        int search(int value) {
            if (this->isEmpty()) return -1;

            int pos = 0;
            Node *it = this->head;
            while(!! it) {
                if (it->data == value) return pos;
                it = it->next;
                pos++;
            }

            return -1;
        }
};

void displayMenu() {
	cout<<"------------------------------"<<endl;
	cout<<"Choice | Operation"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"   1   | Insert At Front"<<endl;
	cout<<"   2   | Insert At Middle"<<endl;
	cout<<"   3   | Insert At Last"<<endl;
	cout<<"   4   | Delete At Front"<<endl;
	cout<<"   5   | Delete At Middle"<<endl;
	cout<<"   6   | Delete At Last"<<endl;
	cout<<"   7   | Reverse"<<endl;
	cout<<"   8   | Search"<<endl;
	cout<<"   9   | Print List"<<endl;
	cout<<"   0   | Exit"<<endl<<endl;
}

void handleChoice(SingleLinkedList *list, int choice) {
	int val, pos;
	switch (choice) {
		case 1:
			cout<<"Enter value to be inserted ";
			cin>>val;
			
			list->insertFront(val);
			break;

		case 2:
            cout<<"Enter position on which value is to be inserted (start from 0) ";
			cin>>pos;
			
            cout<<"Enter value to be inserted ";
			cin>>val;
			
			list->insertMiddle(pos, val);
			break;
		
		case 3:
			cout<<"Enter value to be inserted ";
			cin>>val;
		
			list->insertEnd(val);
			break;

		case 4:
            list->deleteFront();
			break;
		
		case 5:
			cout<<"Enter position from which value is to be deleted (start from 0) "<<endl;
            cin>>pos;

			list->deleteMiddle(pos);
            break;

		case 6:
			list->deleteEnd();
			break;

        case 7:
			list->reverse();
			break;

        case 8:
            cout<<"Enter value to be searched ";
			cin>>val;

            (list->search(val) > -1) ? cout<<"Its in list"<<endl : cout<<"Its not in list"<<endl;
            break;

        case 9:
            list->traversal();
            break;
	
		default:
			exit(0);
	}
}

int main() {
    SingleLinkedList *s = new SingleLinkedList();

    // int choice;
	
	// while (true) {
	// 	displayMenu();
	// 	cin>>choice;
	// 	handleChoice(s, choice);
	// }

    s->insertEnd(1);
    s->insertEnd(5);
    s->insertEnd(3);
    s->insertEnd(8);

    s->swap(2);

    s->traversal();

    return 0;
}