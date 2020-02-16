#ifndef LINK_LIST_H
#define LINK_LIST_H

#endif // LINK_LIST_H
#include <iostream>
#include <list>

using namespace std;


//定义LinkListNode 类
template<typename T >class LinkList;
template <typename T> class LinkListNode {
public:
    friend class LinkList<T>;
    LinkListNode() {
        data = NULL;
        nextNode = NULL;
    }
    LinkListNode(T newdata) {
        this->data = newdata;
        nextNode = NULL;
    }
    T getData() {
        return data;
    }
    LinkListNode<T> * getNextNode() {
        return nextNode;
    }

    T data;
    LinkListNode<T>* nextNode;

private:

};


//定义LinkList 类
template <typename T> class LinkList {
public:
    LinkListNode<T> *head;
    LinkList() { head = NULL; }
    LinkList(T data) {
        head = new LinkListNode<T>(data);
        head->nextNode = NULL;

    }
    ~LinkList() {
        delete head;
    }



    void push_back(T value) {
        LinkListNode<int>* lnlt = nullptr;

        lnlt = new LinkListNode<T>(value);

//        cout << "in push_back\n" << "lnlt->data:"<< lnlt->data << endl;
        if (this->head == nullptr)
         {
            this->head = new LinkListNode<T>(value);
            return;
         }
        LinkListNode<T>* node;
        node = this->head;
//        cout << "head: " << head<<endl;
        for(; node != nullptr; )
        {
           if (node->nextNode == nullptr)
           {
               break;
           }
           node = node->nextNode;
//           cout << node->data << endl;
        }
        node->nextNode = new LinkListNode<T> (value);
//        cout << node->nextNode->data <<endl;

    };


    void cycl(int position)             // 表示环的入口在position处
    {
        int count = 0;
        LinkListNode<T>* node;
        LinkListNode<T>* temp = nullptr;
        node = this->head;
        for(; node != nullptr; node= node->nextNode)
        {
            if (count == position)
            {
                temp = node;
            }
            if (node->nextNode == nullptr)
            {
                break;
            }
            else
            count +=1;

        }

//        cout <<"temp->data:" << temp->data <<endl;
        node->nextNode = temp;
//        cout << node->nextNode->data << endl;

    };


    int is_linklist_cycl()      //return position: position=-1 表示无环， position>=0 表示环的入口在position处
    {
        if (this->head == nullptr)
        {
            return -1;
        }
        LinkListNode<T>* fast = this->head;
        LinkListNode<T>* slow = this->head;

        for(; slow !=nullptr, fast !=nullptr; )
        {
            slow=slow->nextNode, fast=fast->nextNode->nextNode;
//            cout << "\tslow->data: " << slow->data << "\tfast->data: " << fast->data << endl;
//            cout <<"slow: " <<slow << "\tfast: " << fast <<"\n" << endl;
            if (slow == fast)
            {
                break;
            }
            if ((slow->nextNode == nullptr) || (fast->nextNode->nextNode == nullptr))
            {

                return -1;
            }

        }

        fast = this->head;

        while (slow != fast) {
            slow = slow->nextNode;
            fast = fast->nextNode;
//            cout << "\tslow->data: " << slow->data << "\tfast->data: " << fast->data << endl;
//            cout <<"slow: " <<slow << "\tfast: " << fast <<"\n" << endl;

        }

       if(slow != nullptr)
        {
            int postion = 0;
            LinkListNode<T>* node = this->head;
            {
                for(; node != slow; node=node->nextNode)
                {
                    postion +=1;
                }
            }
            return postion;
        }

    };


    void display( )
    {
        if (this->head == nullptr)
        {
            cout << "empty" << endl;
        }
        LinkListNode<T>* node;

        node = this->head;
        for(; node != nullptr;node=node->nextNode)
        {
//            cout << "node: " << node<< "\tnode->data:" <<node->data << endl;
            cout << node->data << " ";
        }
    };
};
