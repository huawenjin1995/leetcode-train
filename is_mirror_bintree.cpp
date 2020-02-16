#include <string>
#include <iostream>
#include "binary_tree.h"


bool is_mirror_left_and_right(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right)
{
    string s(4,'\t');
//    cout <<"\n"<< s<<"is_mirror_left_and_right" << endl;

    if (left == nullptr && right == nullptr)
    {
//        cout <<s<< "true"<<endl;
        return true;
    }

    if (left == nullptr || right == nullptr)
    {
//        cout <<s<< "false"<<endl;
//        cout <<s << "left:" <<left <<"\trighr:" << right<< endl;
        return false;
    }

    return ((left->data == right->data) && is_mirror_left_and_right(left->lChild, right->rChild)
            && is_mirror_left_and_right(left->rChild, right->lChild));
}


bool is_mirror_bintree(BinaryTreeNode<int>* root)
{
    if (root == nullptr)
    {
        return true;
    }
    return is_mirror_left_and_right(root->lChild, root->rChild);
}



//int main()
//{

//    BinaryTree<int> btree;
////    btree.PreCreateTree();//先序构建二叉树,以 ‘#’ 代表空节点,节点之间用空格分开

//    btree.CreateTree();     //中序构建二叉树,以 ‘#’ 代表空节点

//    cout << "先序遍历:";
//    btree.preOderTraversal(btree.root); cout << endl;//先序遍历
//    cout << "中序遍历:";
//    btree.inOrderTraversal(btree.root); cout << endl;//中序遍历
//    cout << "后序遍历:";
//    btree.postOrderTraversal(btree.root); cout << endl;//后序遍历
//    cout << "逐层序遍历:";
//    btree.levelTraversal(btree.root);

//    if (is_mirror_bintree(btree.root))
//    {
//        cout << "\nthis binarytree is mirror" << endl;
//    }
//    else {
//        cout << "\nthis binarytree is not mirror"<< endl;
//    }
//    cout <<"max depth=" << btree.maxDepth(btree.root) << endl;

//    return 0;


//}
