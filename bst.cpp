#include<bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node* left;
    node* right;
    node(int key)
    {
        data = key;
        left =NULL;
        right=NULL;
    }
    friend class BST;
};
class BST
{
    friend class node;
    public:
    node* insert(node* root,int key);
    node* search(node* root, int key) ;
    void displayInOrder(node* root);
    void displayPostOrder(node* root);
    void displayPreOrder(node* root);
    node* mirrorBST(node* root);
    int heightOf(node* root);
    void displayLevelOrder(node* root);
    void displayLeafNodes(node* root) ;
    node* copyTree(node* originalRoot);
};
node* BST :: insert(node* root,int key)
{
    if(root==NULL)
    {
        root = new node(key);
        return root;
    }
    if(key<root->data)
    {
        root->left = insert(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = insert(root->right,key);
    }   
    return root;
}
node* BST :: search(node* root, int key) {
        if (root == NULL || root->data == key) {
            return root;
        }

        if (key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

void BST:: displayInOrder(node* root) {
    if (root != nullptr) {
        displayInOrder(root->left);
        cout << root->data << " ";
        displayInOrder(root->right);
    }
}
void BST :: displayPostOrder(node* root)
{
    if (root != nullptr) {
        displayInOrder(root->left);
        displayInOrder(root->right);
        cout << root->data << " ";
    }
}
void BST :: displayPreOrder(node* root)
{
    if (root != nullptr) {
        cout << root->data << " ";
        displayInOrder(root->left);
        displayInOrder(root->right);
        
    }
}
node* BST:: mirrorBST(node* root)
{
    if(root==NULL)
    {
        return root;
    }
    node* temp = root->right;
    root->right =root->left;
    root->left = temp;
    cout<<root->data<<" "<<endl;
    mirrorBST(root->left);
    mirrorBST(root->right);
}
int BST:: heightOf(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return(1+max(heightOf(root->left),heightOf(root->right)));
}
void BST :: displayLevelOrder(node* root)
{
     queue<node*> q;
     if(root==NULL)
     {
        cout<<"Tree is Empty"<<endl;
        return;
     }
     q.push(root);
     while(!(q.empty()))
     {
        node* node = q.front();
        cout << node->data << " ";
        if(node->left!=nullptr)
        {
            q.push(node->left);
        }
        if (node->right != NULL) q.push(node->right);
        q.pop();
     }
}
void BST:: displayLeafNodes(node* root) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
            cout << root->data << " ";

        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
node* BST:: copyTree(node* originalRoot) {
        if (originalRoot == nullptr)
            return nullptr;

        node* newRoot;
        newRoot->data = originalRoot->data;
        newRoot->left = copyTree(originalRoot->left);
        newRoot->right = copyTree(originalRoot->right);
        return newRoot;
    }
int main()
{
    BST b;
    node* root =NULL;
    node* copiedTree=NULL;
    
    int choice;
    int key;
    node* result = nullptr;

    while (true) {
        cout<<endl;
        cout << "Menu: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display Inorder" << endl;
        cout << "4. Display Postorder" << endl;
        cout << "5. Display Preorder" << endl;
        cout << "6. Display Level order" << endl;
        cout << "7. Display height of BST" << endl;
        cout << "8. Mirrored BST" << endl;
        cout << "9. Display leaf nodes" << endl;
        cout << "10. Copy the tree" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> key;
                root = b.insert(root, key);
                cout << key << " inserted into the tree." << endl;
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> key;
                result = b.search(root, key);
                if (result != nullptr) {
                    cout << "Key " << key << " found in the tree." << endl;
                } else {
                    cout << "Key " << key << " not found in the tree." << endl;
                }
                break;
            case 3:
                if(root==NULL)
                {
                    cout<<"Tree is empty"<<endl;
                }
                else
                {cout<<"Inorder Traversal of the given BST is :"<<endl;
                b.displayInOrder(root);}
                break;
            case 4:
                b.displayPostOrder(root);
                break;
            case 5:
                b.displayPreOrder(root);
                break;
            case 6:
                b.displayLevelOrder(root);
                break;
            case 7:
                cout<<"Height of the binary tree is : "<<b.heightOf(root)<<endl;
                break;

            case 8:
                b.mirrorBST(root);
                cout << "Tree mirrored successfully." << endl;
                break;
            case 9:
                b.displayLeafNodes(root);
                break;
            case 10:
                copiedTree = b.copyTree(root);
                cout << "Original Tree Inorder Traversal: ";
                b.displayInOrder(root);
                cout << "Copied Tree Inorder Traversal: ";
                b.displayInOrder(copiedTree);
                cout << endl;
                break;
            case 11:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;

}

