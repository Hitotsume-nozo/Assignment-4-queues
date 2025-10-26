

# UCS301 Data Structures

## Lab Assignment 4: Queues

---

## **Explanations**

### **1. Simple Queue**

A **queue** is a linear data structure that follows **FIFO (First In First Out)**.

* The **rear** is where new elements are added.
* The **front** is where elements are removed.
* Operations like `enqueue()` and `dequeue()` simulate real-life waiting lines.

In the program, the queue is implemented with basic operations: insert, delete, check if empty/full, peek at the front element, and display all contents.

**Code**
```cpp
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
    // Constructor initialized
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
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " enqueued successfully" << endl;
    }

    // Remove element from front of queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully" << endl;
        front = (front + 1) % capacity;
        size--;
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
        cout << "Queue elements: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int capacity, choice, value;

    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);

    do {
        cout << "\n----- QUEUE OPERATIONS MENU -----" << endl;
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
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                value = q.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;

            case 4:
                q.display();
                break;

            case 5:
                if (q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;

            case 6:
                if (q.isFull()) {
                    cout << "Queue is full" << endl;
                } else {
                    cout << "Queue is not full" << endl;
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
```
**Sample Output:**

```
Enter the capacity of the queue:6

----- QUEUE OPERATIONS MENU -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:5
 Queue is empty

----- QUEUE OPERATIONS MENU -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:1
 Enter value to enqueue:2
 2 enqueued successfully

----- QUEUE OPERATIONS MENU -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:7
 Exiting program...

Process finished with exit code 0

```

---

### **2. Circular Queue**

A **circular queue** connects the last position back to the first, optimizing memory use. Unlike a simple queue where empty slots are wasted after deletions, circular queues reuse them. This makes it especially useful in buffering (like CPU scheduling or streaming).

**Code:**
```cpp
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
```
**Sample Output:**

```
Enter the capacity of the circular queue:4

----- CIRCULAR QUEUE OPERATIONS MENU -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:1
 Enter value to enqueue:11
 11 enqueued successfully

----- CIRCULAR QUEUE OPERATIONS MENU -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:1
 Enter value to enqueue:44
 44 enqueued successfully

----- CIRCULAR QUEUE OPERATIONS MENU -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:3
 Front element is: 44

Process finished with exit code 0
```

---

### **3. Interleaving Queue Halves**

This problem rearranges elements by **interleaving** the first half of the queue with the second half. It demonstrates how queues can be manipulated beyond simple enqueue and dequeue, and is a practical application in data reordering problems.

**Code:**
```cpp
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
```
**Sample Output:**

```
Enter the number of elements in the queue:4
Enter 4 elements:11
22
33
44

Original Queue elements: 11 22 33 44

After interleaving Queue elements: 11 33 22 44

Process finished with exit code 0

```

---

### **4. First Non-Repeating Character**

By maintaining a queue of characters and tracking their frequencies, the first non-repeating character can be found at any point in a stream of characters. This concept is important in **real-time data processing** (like typing suggestions or live text analysis).

**Code:**
```cpp
#include <iostream>
using namespace std;

class Queue {
private:
    char* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new char[capacity];
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
    
    // Add element to rear of queue
    void enqueue(char value) {
        if (size == capacity) {
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }
    
    // Remove element from front of queue
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
    
    // Get front element
    char getFront() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[front];
    }
    
    // Remove specific character from queue
    void removeChar(char ch) {
        if (isEmpty()) {
            return;
        }
        
        // Store current size
        int currentSize = size;
        
        // Process all elements once
        for (int i = 0; i < currentSize; i++) {
            char frontChar = getFront();
            dequeue();
            
            // Re-enqueue only if it's not the character to remove
            if (frontChar != ch) {
                enqueue(frontChar);
            }
        }
    }
};

void findFirstNonRepeating(char* str, int n) {
    // Frequency array for lowercase letters
    int freq[26] = {0};
    
    // Queue to maintain order of characters
    Queue q(n);
    
    cout << "Output: ";
    
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        
        // Increase frequency
        freq[ch - 'a']++;
        
        // Add to queue if it's the first occurrence
        if (freq[ch - 'a'] == 1) {
            q.enqueue(ch);
        }
        // If it's a repeating character, remove from queue
        else if (freq[ch - 'a'] > 1) {
            q.removeChar(ch);
        }
        
        // Check front of queue for first non-repeating character
        while (!q.isEmpty() && freq[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }
        
        // Print result
        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.getFront() << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    
    char* str = new char[n];
    cout << "Enter " << n << " characters (separated by space): ";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    findFirstNonRepeating(str, n);
    
    delete[] str;
    return 0;
}
```


**Sample Output:**

```
Enter the number of characters:6
Enter 6 characters (separated by space):a a d d c e
Output: a -1 d -1 c c

Process finished with exit code 0
```

---

### **5. Stack Using Queues**

A **stack (LIFO)** can be implemented using **queues (FIFO)** in two ways:

1. **Two Queues:** Elements are rearranged on every push to ensure pop always gives the last inserted element.
2. **One Queue:** After each insertion, elements are rotated so that the newest element comes to the front.

This shows how different data structures can simulate each other, which is a common idea in advanced algorithms.

**Code:**
```cpp
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
```

**Sample Output (Two Queues):**

```
Choose implementation method:
1. Stack using Two Queues
2. Stack using One Queue
Enter choice:1

----- STACK OPERATIONS (Two Queues) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:1
 Enter value to push:23
 23 pushed to stack

----- STACK OPERATIONS (Two Queues) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:1
 Enter value to push:12
 12 pushed to stack

----- STACK OPERATIONS (Two Queues) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:3
 Top element: 12

----- STACK OPERATIONS (Two Queues) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:5
 Exiting...

Process finished with exit code 0

```

**Sample Output (One Queue):**

```
Choose implementation method:
1. Stack using Two Queues
2. Stack using One Queue
Enter choice:2

----- STACK OPERATIONS (One Queue) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:1
 Enter value to push:12
 12 pushed to stack

----- STACK OPERATIONS (One Queue) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:3
 Top element: 12

----- STACK OPERATIONS (One Queue) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:2
 12 popped from stack

----- STACK OPERATIONS (One Queue) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:4
 Stack is empty

----- STACK OPERATIONS (One Queue) -----
1. Push
2. Pop
3. Top
4. Check if Empty
5. Exit
Enter choice:5
 Exiting...

Process finished with exit code 0

```

---

## **Conclusion**

This Assignment highlights the **mechanics of queues and stacks**, but also their **applications and versatility**:

* **Simple vs. Circular Queues:** highlighted memory handling efficiency.
* **Interleaving and Non-Repeating Character problems:** showed how queues can solve real-world data streaming and reordering challenges.
* **Stack via Queues:** reinforced the adaptability of data structures by demonstrating how a FIFO system can mimic LIFO behavior.

Overall, this exercise strengthened both **theoretical understanding** and **practical implementation skills** of fundamental data structures.

---
