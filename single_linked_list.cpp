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
	
		SingleLinkedList() {
			this->head = NULL;
		}
		
		void insertEnd(int val) {
			Node *node = new Node();
			node->data = val;
			node->next = head;
			this->head = node;
		}
		
		void insertAfter(int afterVal, int val) {			
			Node *current = this->head;
			while (!! current) {
				if (current->data == afterVal) {
					Node *node = new Node();
				   	node->data = val;
  			  	   	node->next = current->next;
  			  	   	current->next = node;
					break;
				}
				current = current->next;
			}
		}
		
		void insertBefore(int beforeVal, int val) {
			
			Node *current = this->head;
			while (!! current) {
				if (!! current->next && current->next->data == beforeVal) {
				   	Node *node = new Node();
				   	node->data = val;
  			  	   	node->next = current->next;
  			  	   	current->next = node;
					break;
				}
				current = current->next;
			}
		}
		
		void remove(int val) {
			if (! this->head) return;
			
			Node *current = this->head;

			// If value found at head node.
			if (this->head->data == val) {
				Node *temp = this->head;
				this->head = this->head->next;
				delete temp;
			}

			while (!! current) {
				if (!! current->next && current->next->data == val) {
					Node *temp = current->next;
					current->next = current->next->next;
					delete temp;
				}
				current = current->next;
			}
		}
		
		void traversal() {
			Node *current = this->head;
			cout<<"Elements in list : ";
			while(!! current) {
				cout<<current->data<<' ';
				current = current->next;
			}
			cout<<endl;
		}
		
		void reverse() {
			if(! this->head) return;
			
			Node * current = this->head;
			Node * prev = NULL;
			Node * next = NULL;
			
			while (!!current) {
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			this->head = prev;
		}
};

void displayMenu() {
	cout<<"------------------------------"<<endl;
	cout<<"Choice | Operation"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"   1   | Insert At End"<<endl;
	cout<<"   2   | Insert After Element"<<endl;
	cout<<"   3   | Insert Before Element"<<endl;
	cout<<"   4   | Remove Element"<<endl;
	cout<<"   5   | Reverse List"<<endl;
	cout<<"   6   | Print List"<<endl;
	cout<<"   0   | Exit"<<endl<<endl;
}

void handleChoice(SingleLinkedList *list, int choice) {
	int val, afterVal, beforeVal;
	switch (choice) {
		case 1:
			cout<<"Enter value to be inserted ";
			cin>>val;
			
			list->insertEnd(val);
			list->traversal();
			
			break;

		case 2:
			cout<<"Insert after value ";
			cin>>afterVal;
			
			cout<<"Enter value to be inserted ";
			cin>>val;
		
			list->insertAfter(afterVal, val);
			list->traversal();

			break;
		
		case 3:
			cout<<"Insert before value ";
			cin>>beforeVal;
			
			cout<<"Enter value to be inserted ";
			cin>>val;
		
			list->insertBefore(beforeVal, val);
			list->traversal();

			break;

		case 4:
			cout<<"Enter value to be deleted ";
			cin>>val;
			list->remove(val);
			list->traversal();
			
			break;
		
		case 5:
			list->reverse();
			cout<<"After reverse operation"<<endl;
			list->traversal();

			break;

		case 6:
			list->traversal();

			break;
	
		default:
			exit(0);
	}
}

int main() {
	SingleLinkedList *list = new SingleLinkedList();
	
	int choice;
	
	while (true) {
		displayMenu();
		cin>>choice;
		handleChoice(list, choice);
	}

	return 0;
}


