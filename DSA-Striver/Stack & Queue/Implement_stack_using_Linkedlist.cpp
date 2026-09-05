struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* topI;
    int size;

public:
    LinkedListStack() {
        topI = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = topI;
        topI = temp;
        size++;
    }
    
    int pop() {
        if (topI == nullptr) {
            return -1;
        }
        Node* temp = topI;
        int poppedVal = temp->data;
        topI = topI->next;
        delete temp;
        size--;
        return poppedVal;
    }
    
    int top() {
        if (topI == nullptr) {
            return -1;
        }
        return topI->data;
    }
    
    bool isEmpty() {
        return topI == nullptr;
    }
};

