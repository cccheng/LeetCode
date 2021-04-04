class MyCircularQueue {
    int front;
    int rear;
    int size;
    vector<int> cqueue;

public:
    MyCircularQueue(int k) {
        rear = k - 1;
        front = 0;
        size = 0;
        cqueue = vector<int>(k);
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        rear = (rear + 1) % cqueue.size();
        cqueue[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % cqueue.size();
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : cqueue[front];
    }

    int Rear() {
        return isEmpty() ? -1 : cqueue[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cqueue.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
