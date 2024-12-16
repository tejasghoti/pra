{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <bits/stdc++.h>\
using namespace std;\
\
void heapifyMax(int arr[], int n, int i) \{\
    int largest = i;\
    int lchild = 2 * i + 1;\
    int rchild = 2 * i + 2;\
\
    // Check if left child exists and is greater than root\
    if (lchild < n && arr[lchild] > arr[largest]) \{\
        largest = lchild;\
    \}\
\
    // Check if right child exists and is greater than the largest\
    if (rchild < n && arr[rchild] > arr[largest]) \{\
        largest = rchild;\
    \}\
\
    // Swap and recursively heapify the affected subtree\
    if (largest != i) \{\
        swap(arr[largest], arr[i]);\
        heapifyMax(arr, n, largest);\
    \}\
\}\
\
void createHeapMax(int arr[], int n) \{\
    // Build a max heap by heapifying non-leaf nodes\
    for (int i = n / 2 - 1; i >= 0; i--) \{\
        heapifyMax(arr, n, i);\
    \}\
\}\
\
void heapifyMin(int arr[], int n, int i) \{\
    int smallest = i;\
    int lchild = 2 * i + 1;\
    int rchild = 2 * i + 2;\
\
    // Check if left child exists and is smaller than root\
    if (lchild < n && arr[lchild] < arr[smallest]) \{\
        smallest = lchild;\
    \}\
\
    // Check if right child exists and is smaller than the smallest\
    if (rchild < n && arr[rchild] < arr[smallest]) \{\
        smallest = rchild;\
    \}\
\
    // Swap and recursively heapify the affected subtree\
    if (smallest != i) \{\
        swap(arr[smallest], arr[i]);\
        heapifyMin(arr, n, smallest);\
    \}\
\}\
\
void createHeapMin(int arr[], int n) \{\
    // Build a min heap by heapifying non-leaf nodes\
    for (int i = n / 2 - 1; i >= 0; i--) \{\
        heapifyMin(arr, n, i);\
    \}\
\}\
\
void DeleteMax(int arr[], int n) \{\
    for (int i = n - 1; i >= 0; i--) \{\
        swap(arr[0], arr[i]);       // Move current root to end\
        heapifyMax(arr, i, 0);      // Call max heapify on reduced heap\
    \}\
\}\
\
void DeleteMin(int arr[], int n) \{\
    for (int i = n - 1; i >= 0; i--) \{\
        swap(arr[0], arr[i]);       // Move current root to end\
        heapifyMin(arr, i, 0);      // Call min heapify on reduced heap\
    \}\
\}\
\
void Display(int arr[], int n) \{\
    for (int i = 0; i < n; i++) \{\
        cout << arr[i] << " ";\
    \}\
    cout << endl;\
\}\
\
int main() \{\
    bool go = true;\
    int choice;\
    int n;\
\
    cout << "Enter the Size of Array: ";\
    cin >> n;\
    int arr[n];\
    cout << "Enter the Elements of Array:" << endl;\
    for (int i = 0; i < n; i++) \{\
        cin >> arr[i];\
    \}\
    cout << endl;\
\
    while (go) \{\
        cout << "1] Create Min Heap\\n";\
        cout << "2] Create Max Heap\\n";\
        cout << "3] Perform Heap Sort on Max Heap\\n";\
        cout << "4] Perform Heap Sort on Min Heap\\n";\
        cout << "5] Exit\\n";\
        cin >> choice;\
\
        switch (choice) \{\
            case 1:\
                createHeapMin(arr, n);\
                Display(arr, n);\
                break;\
            case 2:\
                createHeapMax(arr, n);\
                Display(arr, n);\
                break;\
            case 3:\
                DeleteMax(arr, n);\
                Display(arr, n);\
                break;\
            case 4:\
                DeleteMin(arr, n);\
                Display(arr, n);\
                break;\
            case 5:\
                go = false;\
                cout << "Thanks..." << endl;\
                break;\
            default:\
                cout << "Invalid choice! Try again." << endl;\
                break;\
        \}\
    \}\
\}\
}