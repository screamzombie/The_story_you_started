#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};
using tree_p = tree *;

void maketree(tree_p &bot)  //这里可以把tree_p看作一个类型，所以要传一个引用，或者指针
//在这里是指针的指针
{
    int val;
    cin >> val;
    if (val == 1)
        bot = NULL;
    else
    {
        bot = new tree;
        bot->data = val;
        maketree(bot->left);
        maketree(bot->right);
    }
}

void watchtree(tree_p &root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    watchtree(root->left);
    watchtree(root->right);
}

void preOrderTraverse(tree_p T)
{
    if (T == NULL)
        return;
    cout << T->data << ' ';
    preOrderTraverse(T->left);
    preOrderTraverse(T->right);
}
int main()
{
    cout << "experiment!" << endl;
    tree_p root;
    maketree(root);
    preOrderTraverse(root);
    return 0;
}