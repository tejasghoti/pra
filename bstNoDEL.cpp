{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <bits/stdc++.h>\
using namespace std;\
\
class node \{\
public:\
    int data;\
    node* left;\
    node* right;\
\
    node(int key) \{ // Fixed constructor name\
        data = key;\
        left = nullptr;\
        right = nullptr;\
    \}\
\};\
\
class BST \{\
public:\
    node* insert(node* root, int key);\
    node* search(node* root, int key);\
    void displayInOrder(node* root);   // Fixed method signature\
    void displayPostOrder(node* root); // Fixed method signature\
    void displayPreOrder(node* root);  // Fixed method signature\
\};\
\
node* BST::insert(node* root, int key) \{\
    if (root == nullptr) \{\
        return new node(key);\
    \}\
    if (key < root->data) \{\
        root->left = insert(root->left, key);\
    \} else if (key > root->data) \{\
        root->right = insert(root->right, key);\
    \}\
    return root;\
\}\
\
node* BST::search(node* root, int key) \{\
    if (root == nullptr || root->data == key) \{\
        return root;\
    \}\
    if (key < root->data) \{\
        return search(root->left, key);\
    \} else \{\
        return search(root->right, key);\
    \}\
\}\
\
void BST::displayInOrder(node* root) \{\
    if (root != nullptr) \{\
        displayInOrder(root->left);\
        cout << root->data << " ";\
        displayInOrder(root->right);\
    \}\
\}\
\
void BST::displayPostOrder(node* root) \{\
    if (root != nullptr) \{\
        displayPostOrder(root->left);\
        displayPostOrder(root->right);\
        cout << root->data << " ";\
    \}\
\}\
\
void BST::displayPreOrder(node* root) \{\
    if (root != nullptr) \{\
        cout << root->data << " ";\
        displayPreOrder(root->left);\
        displayPreOrder(root->right);\
    \}\
\}\
\
int main() \{\
    BST b;\
    node* root = nullptr;\
    int choice, key;\
    node* result = nullptr;\
\
    while (true) \{\
        cout << endl;\
        cout << "Menu: " << endl;\
        cout << "1. Insert" << endl;\
        cout << "2. Search" << endl;\
        cout << "3. Display Inorder" << endl;\
        cout << "4. Display Postorder" << endl;\
        cout << "5. Display Preorder" << endl;\
        cout << "6. EXIT" << endl;\
        cout << "Enter your choice: ";\
        cin >> choice; // Fixed missing input for choice\
\
        switch (choice) \{\
        case 1:\
            cout << "Enter the value to insert: ";\
            cin >> key;\
            root = b.insert(root, key);\
            cout << key << " inserted into the tree." << endl;\
            break;\
        case 2:\
            cout << "Enter the value to search: ";\
            cin >> key;\
            result = b.search(root, key);\
            if (result != nullptr) \{\
                cout << "Key " << key << " found in the tree." << endl;\
            \} else \{\
                cout << "Key " << key << " not found in the tree." << endl;\
            \}\
            break;\
        case 3:\
            cout << "Inorder Traversal of the BST: ";\
            b.displayInOrder(root);\
            cout << endl;\
            break;\
        case 4:\
            cout << "Postorder Traversal of the BST: ";\
            b.displayPostOrder(root);\
            cout << endl;\
            break;\
        case 5:\
            cout << "Preorder Traversal of the BST: ";\
            b.displayPreOrder(root);\
            cout << endl;\
            break;\
        case 6:\
            cout << "Exiting..." << endl;\
            return 0;\
        default:\
            cout << "Invalid choice. Please try again." << endl;\
            break;\
        \}\
    \}\
\}\
}