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
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    
    // Destructor
    ~Queue() {
        delete[] arr;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Check if queue is full
    bool isFull() {
        return size == capacity;
    }
    
    // Add element to rear of queue
    void enqueue(int value) {
        if (isFull()) {
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }
    
    // Remove and return element from front of queue
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }
    
    // Get current size
    int getSize() {
        return size;
    }
    
    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// Function to interleave the queue
void interleaveQueue(Queue& q) {
    int n = q.getSize();
    
    // If queue has odd number of elements or less than 2 elements
    if (n <= 1) {
        return;
    }
    
    // Create a temporary array to store first half
    int halfSize = n / 2;
    int* firstHalf = new int[halfSize];
    
    // Dequeue first half and store in array
    for (int i = 0; i < halfSize; i++) {
        firstHalf[i] = q.dequeue();
    }
    
    // Create temporary array to store second half
    int secondHalfSize = n - halfSize;
    int* secondHalf = new int[secondHalfSize];
    
    // Dequeue second half and store in array
    for (int i = 0; i < secondHalfSize; i++) {
        secondHalf[i] = q.dequeue();
    }
    
    // Interleave and enqueue back
    int i = 0, j = 0;
    while (i < halfSize && j < secondHalfSize) {
        q.enqueue(firstHalf[i++]);
        q.enqueue(secondHalf[j++]);
    }
    
    // If there are remaining elements in second half (odd number case)
    while (j < secondHalfSize) {
        q.enqueue(secondHalf[j++]);
    }
    
    // Clean up
    delete[] firstHalf;
    delete[] secondHalf;
}

int main() {
    int n, value;
    
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    
    Queue q(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }
    
    cout << "\nOriginal ";
    q.display();
    
    interleaveQueue(q);
    
    cout << "\nAfter interleaving ";
    q.display();
    
    return 0;
}