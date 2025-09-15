#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Add element to rear of queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        // If queue is empty, set front to 0
        if (front == -1) {
            front = 0;
        }

        // Update rear circularly
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        cout << value << " enqueued successfully" << endl;
    }

    // Remove element from front of queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }

        int value = arr[front];

        // If only one element was present
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            // Update front circularly
            front = (front + 1) % capacity;
        }

        cout << value << " dequeued successfully" << endl;
    }

    // Get front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Circular Queue elements: ";

        // If rear hasn't wrapped around yet
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        // If rear has wrapped around
        else {
            // Print from front to end of array
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            // Print from start of array to rear
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        cout << "Front index: " << front << ", Rear index: " << rear << endl;
    }
};

int main() {
    int capacity, choice, value;

    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    do {
        cout << "\n----- CIRCULAR QUEUE OPERATIONS MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                value = cq.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;

            case 4:
                cq.display();
                break;

            case 5:
                if (cq.isEmpty()) {
                    cout << "Circular Queue is empty" << endl;
                } else {
                    cout << "Circular Queue is not empty" << endl;
                }
                break;

            case 6:
                if (cq.isFull()) {
                    cout << "Circular Queue is full" << endl;
                } else {
                    cout << "Circular Queue is not full" << endl;
                }
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}