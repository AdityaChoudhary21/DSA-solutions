class ArrayStack {
private:
    int topI;
    int capacity;
    int* st;

public:
    ArrayStack() {
        capacity = 10000;
        st = new int[capacity];
        topI = -1;
    }
    
    void push(int x) {
        if(topI>=capacity-1){
            return ;
        }
        topI++;
        st[topI]=x;
    }
    
    int pop() {
        if(topI==-1){
            return -1;
        }
        int el=st[topI];
        topI--;
        return el;
    }
    
    int top() {
        if(topI==-1){
            return -1;
        }
        return st[topI];
    }
    
    bool isEmpty() {
        return topI==-1;
    }
};

