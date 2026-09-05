class ArrayQueue {
private:
    int start, end;
    int currsize;
    int capacity;
    int* q;

public:
    ArrayQueue() {
        capacity=10000;
        currsize=0;
        start = -1;
        end = -1;
        q = new int[capacity];

    }
    
    void push(int x) {
        if(currsize==capacity){
            return ;
        }
        if(currsize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1) % capacity;
        }
        q[end]=x;
        currsize++;
    }
    
    int pop() {
        if(currsize==0){
            return -1;
        }
        int el = q[start];
        if(currsize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1) % capacity;
        }
        currsize--;
        return el;
  
    }
    
    int peek() {
        if (currsize == 0) {
            return -1;
        }
        return q[start];
    
    }
    
    bool isEmpty() {
        return currsize==0;
    }
};

