{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
using namespace std;\
#define n 5\
\
class circularQueue \{\
private:\
    int front, rear, size;\
    int arr[n];\
\
public:\
    circularQueue() : front(-1), rear(-1), size(0) \{\}\
\
    // Enqueue operation\
    void enQ(int val) \{\
        if ((front == 0 && rear == n - 1) || front == (rear + 1) % n) \{ // Correct overflow condition\
            cout << "Queue is Full. Cannot add more elements.\\n";\
            return;\
        \}\
\
        if (front == -1) \{ // If queue is empty\
            front = rear = 0;\
        \} else \{\
            rear = (rear + 1) % n;\
        \}\
        arr[rear] = val; // Store value at the rear\
        size++;\
        cout << "Added to queue: " << val << endl;\
    \}\
\
    // Dequeue operation\
    void deQ() \{\
        if (front == -1) \{ // Queue is empty\
            cout << "Queue is Empty. Cannot remove elements.\\n";\
            return;\
        \}\
\
        cout << "Removed from queue: " << arr[front] << endl;\
\
        if (front == rear) \{ // If the queue becomes empty after this operation\
            front = rear = -1;\
        \} else \{\
            front = (front + 1) % n;\
        \}\
        size--;\
    \}\
\
    // Display the queue elements\
    void display() \{\
        if (front == -1) \{ // Queue is empty\
            cout << "Queue is Empty.\\n";\
            return;\
        \}\
\
        cout << "Elements in the queue are: ";\
        for (int i = 0; i < size; i++) \{\
            int index = (front + i) % n; // Calculate index in circular manner\
            cout << arr[index] << " ";\
        \}\
        cout << endl;\
    \}\
\};\
\
int main() \{\
    circularQueue q;\
    int choice, val;\
\
    while (true) \{\
        cout << "\\nSelect the operation to perform:\\n"\
             << "1. Enqueue\\n"\
             << "2. Dequeue\\n"\
             << "3. Display Queue\\n"\
             << "4. Exit\\n";\
        cin >> choice;\
\
        switch (choice) \{\
        case 1:\
            cout << "Enter number to be enqueued: ";\
            cin >> val;\
            q.enQ(val);\
            break;\
\
        case 2:\
            q.deQ();\
            break;\
\
        case 3:\
            q.display();\
            break;\
\
        case 4:\
            cout << "Exiting program.\\n";\
            return 0;\
\
        default:\
            cout << "Invalid choice. Try again.\\n";\
        \}\
    \}\
\}\
\
}