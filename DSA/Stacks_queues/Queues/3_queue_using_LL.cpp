#include <iostream>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class Queue {
	Node<T> * head;
	Node<T> * tail; 
	int size;

   public:
    Queue() {
		head=NULL;
		tail=NULL;
		size=0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		return size;
	}

    bool isEmpty() {
		return size==0;
	}

    void enqueue(T data) {
		Node<T> * newNode = new Node<T>(data);
		if (head==NULL){
			head=newNode;
			tail=newNode;
			size++;
			return;
		}
		tail->next=newNode;
		tail=tail->next;
		size++;
	}

    T dequeue() {
		if (isEmpty()){
			return 0;
		}
		else if (size==1){
			T ans = head->data;
			head=NULL;
			tail=NULL;
			size--;
			return ans;
		}
		T ans = head->data;
        Node<T> * temp = head;
		head=head->next;
        delete temp;
		size--;
		return ans;
    }

    int front() {
        if (isEmpty()){
			return 0;
		}
		return head->data;
    }
};

int main() {
    Queue<int> q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}