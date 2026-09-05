struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* start;
    Node* end;
    int size;
public:
    LinkedListQueue() {
        start=NULL;
        end=NULL;
        size=0;
    }
    
    void push(int x) {
        Node* temp = new Node (x);
        if(start==NULL){
            start=temp;
            end=temp;
        }
        end=temp;
        size++;
   
    }
    
    int pop() {
        if(start==NULL){
            return -1;
        }
        Node* temp = start;
        int el = start->val;
        start=start->next;
        if(start==NULL){
            end=NULL;
        }
        delete temp;
        size--;
        return el;
  
    }
    
    int peek() {
        if(size==0){
            return -1;
        }
        return start->val;
    
    }
    
    bool isEmpty() {
        return size==0;
  
    }
};

