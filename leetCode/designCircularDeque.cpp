Question Link:https://leetcode.com/problems/design-circular-deque/description/?envType=daily-question&envId=2024-09-28

Question:
// 641. Design Circular Deque
// Solved
// Medium
// Topics
// Companies
// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.
 

// Example 1:

// Input
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// Output
// [null, true, true, true, false, 2, true, true, true, 4]

// Explanation
// MyCircularDeque myCircularDeque = new MyCircularDeque(3);
// myCircularDeque.insertLast(1);  // return True
// myCircularDeque.insertLast(2);  // return True
// myCircularDeque.insertFront(3); // return True
// myCircularDeque.insertFront(4); // return False, the queue is full.
// myCircularDeque.getRear();      // return 2
// myCircularDeque.isFull();       // return True
// myCircularDeque.deleteLast();   // return True
// myCircularDeque.insertFront(4); // return True
// myCircularDeque.getFront();     // return 4
 

// Constraints:

// 1 <= k <= 1000
// 0 <= value <= 1000
// At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

// Solution:

class MyCircularDeque {
public:
    deque<int>d;
    int n;
    MyCircularDeque(int k) {
         this->n=k;
    }
    
    bool insertFront(int value) {
        // cout<<n<<" "<<this->d.size()<<endl;
        if(this->d.size()<this->n){
            this->d.push_front(value);
        return true;
        }
        return false;
        }

    
    bool insertLast(int value) {
        // cout<<n<<" "<<this->d.size()<<endl;
        if(this->d.size()<this->n){
            this->d.push_back(value);
        return true;
        }
        return false;
        }
    
    bool deleteFront() {
        if(this->d.size()>0){
            this->d.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(this->d.size()>0){
            this->d.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(this->d.size()>0){
            return d.front();
        }
        return -1;
    }
    
    int getRear() {
        if(this->d.size()>0){
            return d.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        if(this->d.size()==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(this->d.size()==n){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */