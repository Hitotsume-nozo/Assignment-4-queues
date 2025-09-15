

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

**Sample Output Placeholder:**

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