#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#endif // BINARY_TREE_H
#include <iostream>
#include <string>
#include <queue>
using namespace std;



//定义BinaryTreeNode 类
template<typename T >class BinaryTree;
template <typename T> class BinaryTreeNode {
public:
    friend class BinaryTree<T>;
    BinaryTreeNode() {
        data = NULL;
        lChild = rChild = NULL;
    }
    BinaryTreeNode(T newdata) {
        this->data = newdata;
        lChild = rChild = NULL;
    }
    T getData() {
        return data;
    }
    BinaryTreeNode<T> * getLeftNode() {
        return lChild;
    }
    BinaryTreeNode<T> * getRightNode() {
        return rChild;
    }
    T data;
    BinaryTreeNode<T>* lChild;
    BinaryTreeNode<T>* rChild;
private:

};


//定义BinaryTree 类
template <typename T> class BinaryTree {
public:
    BinaryTreeNode<T> *root;
    char* p;
    BinaryTree() { root = NULL; }
    BinaryTree(T data) {
        root = new BinaryTreeNode<T>(data);
        root->lChild = NULL;
        root->rChild = NULL;
    }
    ~BinaryTree() {
        delete root;
    }

    //构建二叉树并返回
    BinaryTreeNode<T>* CreateTree() {
        BinaryTreeNode<int>* bt = NULL;
        string t;
        cin >> t;
        if (t == "#")
        {
            return NULL;
        }
        else {
            int num = stoi(t);
            bt = new BinaryTreeNode<T>(num);
            if (this->root == NULL)
            {
                this->root = bt;
            }
            bt->lChild = CreateTree();
            bt->rChild = CreateTree();
        }
        return bt;
    }

    //先序构建二叉树
    BinaryTreeNode<T>* PreCreateTree() {
        BinaryTreeNode<int>* bt = NULL;
        if (this->root == NULL)
        {
            cout << "请输入根节点（#代表空树）:";
        }
        else {
            cout << "请输入节点（#代表空树）:";
        }
        string t;
        cin >> t;
        if (t == "#")
        {
            return NULL;
        }
        else {
            int num = stoi(t);
            bt = new BinaryTreeNode<T>(num);
            if (this->root == NULL)
            {
                this->root = bt;
            }
            cout << bt->data << "的左孩子";
            bt->lChild = PreCreateTree();

            cout << bt->data << "的右边孩子";
            bt->rChild = PreCreateTree();
        }
        return bt;
    }

    void preOderTraversal(BinaryTreeNode<T> *bt);  //先序遍历
    void inOrderTraversal(BinaryTreeNode<T> *bt);  //中序遍历
    void postOrderTraversal(BinaryTreeNode<T> *bt);//后序遍历
    void levelTraversal(BinaryTreeNode<T> *bt);    //逐层遍历
    int  maxDepth(BinaryTreeNode<T> *bt);

private:

};

template <typename T>
void BinaryTree<T>::preOderTraversal(BinaryTreeNode<T> *bt) {
    if (bt)
    {
        cout << bt->data <<" ";
        BinaryTree<T>::preOderTraversal(bt->getLeftNode());
        BinaryTree<T>::preOderTraversal(bt->getRightNode());
    }
}

template <typename T>
void BinaryTree<T>::inOrderTraversal(BinaryTreeNode<T> *bt) {
    if (bt)
    {
        BinaryTree<T>::inOrderTraversal(bt->getLeftNode());
        cout << bt->data<<" ";
        BinaryTree<T>::inOrderTraversal(bt->getRightNode());
    }
}

template <typename T>
void BinaryTree<T>::postOrderTraversal(BinaryTreeNode<T> *bt) {
    if (bt)
    {
        BinaryTree<T>::postOrderTraversal(bt->getLeftNode());
        BinaryTree<T>::postOrderTraversal(bt->getRightNode());
        cout << bt->data<<" ";
    }
}

template <typename T>
void BinaryTree<T>::levelTraversal(BinaryTreeNode<T> *bt) {

    queue<BinaryTreeNode<T>*> que;
    que.push(bt);
    while (!que.empty())
    {
        BinaryTreeNode<T>* proot = que.front();
        que.pop();
        cout << proot->data<<" ";

        if (proot->lChild != NULL)
        {
            que.push(proot->lChild);//左孩子入队
        }
        if (proot->rChild != NULL)
        {
            que.push(proot->rChild);//右孩子入队
        }
    }
}


template <typename T>
int BinaryTree<T>::maxDepth(BinaryTreeNode<T> *bt)
{
    int p1, p2;
    if (bt == nullptr)
    {
        return 0;
    }
    else
    {
        p1 = maxDepth(bt->lChild);
        p2 = maxDepth(bt->rChild);
    }
    return (p1 > p2 ? p1+1 : p2+1);
}
