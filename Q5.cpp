#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int getSize() {
        return size;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

// (a) Stack using Two Queues
class StackUsingTwoQueues {
private:
    Queue* q1;
    Queue* q2;
    int capacity;

public:
    StackUsingTwoQueues(int cap) {
        capacity = cap;
        q1 = new Queue(cap);
        q2 = new Queue(cap);
    }

    ~StackUsingTwoQueues() {
        delete q1;
        delete q2;
    }

    // Push operation - O(1)
    void push(int value) {
        if (q1->isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        q1->enqueue(value);
        cout << value << " pushed to stack" << endl;
    }

    // Pop operation - O(n)
    int pop() {
        if (q1->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        // Move all elements except last from q1 to q2
        while (q1->getSize() > 1) {
            q2->enqueue(q1->dequeue());
        }

        // The last element in q1 is the top of stack
        int popped = q1->dequeue();

        // Swap q1 and q2
        Queue* temp = q1;
        q1 = q2;
        q2 = temp;

        cout << popped << " popped from stack" << endl;
        return popped;
    }

    // Get top element
    int top() {
        if (q1->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        // Move all elements except last from q1 to q2
        while (q1->getSize() > 1) {
            q2->enqueue(q1->dequeue());
        }

        // Get the last element
        int topElement = q1->dequeue();
        q2->enqueue(topElement);

        // Swap q1 and q2
        Queue* temp = q1;
        q1 = q2;
        q2 = temp;

        return topElement;
    }

    bool isEmpty() {
        return q1->isEmpty();
    }
};

// (b) Stack using One Queue
class StackUsingOneQueue {
private:
    Queue* q;
    int capacity;

public:
    StackUsingOneQueue(int cap) {
        capacity = cap;
        q = new Queue(cap);
    }

    ~StackUsingOneQueue() {
        delete q;
    }

    // Push operation - O(n)
    void push(int value) {
        if (q->isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }

        int size = q->getSize();

        // Add new element
        q->enqueue(value);

        // Rotate the queue to make the new element at front
        for (int i = 0; i < size; i++) {
            q->enqueue(q->dequeue());
        }

        cout << value << " pushed to stack" << endl;
    }

    // Pop operation - O(1)
    int pop() {
        if (q->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int popped = q->dequeue();
        cout << popped << " popped from stack" << endl;
        return popped;
    }

    // Get top element
    int top() {
        if (q->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q->getFront();
    }

    bool isEmpty() {
        return q->isEmpty();
    }
};

int main() {
    int choice, method, value;

    cout << "Choose implementation method:" << endl;
    cout << "1. Stack using Two Queues" << endl;
    cout << "2. Stack using One Queue" << endl;
    cout << "Enter choice: ";
    cin >> method;

    if (method == 1) {
        StackUsingTwoQueues stack(10);

        do {
            cout << "\n----- STACK OPERATIONS (Two Queues) -----" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Top" << endl;
            cout << "4. Check if Empty" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack.push(value);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    value = stack.top();
                    if (value != -1) {
                        cout << "Top element: " << value << endl;
                    }
                    break;
                case 4:
                    if (stack.isEmpty()) {
                        cout << "Stack is empty" << endl;
                    } else {
                        cout << "Stack is not empty" << endl;
                    }
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 5);
    }
    else if (method == 2) {
        StackUsingOneQueue stack(10);

        do {
            cout << "\n----- STACK OPERATIONS (One Queue) -----" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Top" << endl;
            cout << "4. Check if Empty" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack.push(value);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    value = stack.top();
                    if (value != -1) {
                        cout << "Top element: " << value << endl;
                    }
                    break;
                case 4:
                    if (stack.isEmpty()) {
                        cout << "Stack is empty" << endl;
                    } else {
                        cout << "Stack is not empty" << endl;
                    }
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 5);
    }
    
    return 0;
}