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