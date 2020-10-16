#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
    int data = -1;
    Node *left = nullptr;
    Node *right = nullptr;
};
using Node_P = Node *;

void CreatTree(Node_P *T) //出现了！，指针的指针
{
    int ch;
    cin >> ch;
    if (ch == 0)
    {
        *T = nullptr;
    }
    else
    {
        *T = new Node;
        (*T)->data = ch;
        CreatTree(&(*T)->left); //指针的指针，所以要用&符
        CreatTree(&(*T)->right);
    }
}

void PreOrder(Node_P root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void MidOrder(Node_P root)
{
    if (root != nullptr)
    {
        PreOrder(root->left);
        cout << root->data << " ";
        PreOrder(root->right);
    }
}
void BackOrder(Node_P root)
{
    if (root != nullptr)
    {
        PreOrder(root->left);
        PreOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node_P root;
    cout << "test begin!" << endl;
    CreatTree(&root);
    cout << " the PreOrder is " << endl;
    PreOrder(root);
    return 0;
}
