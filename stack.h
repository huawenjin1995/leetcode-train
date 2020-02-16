#ifndef STACK_H
#define STACK_H

#endif // STACK_H

#include <iostream>
#include <vector>

using namespace std;

template <typename  T>
class Stack{
public:
    Stack()
    {

    };


    void push(T val){
        vector<T> temp;
//        cout << "val: " << val << endl;
        this->data.push_back(val);
//        cout << "data.size: " << this->data.size() << endl;
        if (this->min_data.empty())
        {
            this->min_data.push_back(val);
        }
        if (val < this->min_data.back())
        {
            this->min_data.push_back(val);
//            cout << "aaa min_data top: " << this->min_data.back() << "\tdata_top: " << this->data.back() <<endl;
        }
        else
        {
            while (this->min_data.back() < val && !this->min_data.empty()) {
                temp.push_back(this->min_data.back());
                this->min_data.pop_back();
//                cout << "bbb min_data top: " << this->min_data.back() << "\tdata_top: " << this->data.back() <<endl;
            }

            this->min_data.push_back(val);

            while (! temp.empty()) {
                this->min_data.push_back(temp.back());
                temp.pop_back();
//                cout << "ccc min_data top: " << this->min_data.back() << "\tdata_top: " << this->data.back() <<endl;
            }
        }


    };


    void pop(){
        vector<T> temp;
        T top_val = this->data.back();
        this->data.pop_back();
        if (top_val == this->min_data.back())
        {
            this->min_data.pop_back();
        }
        else
        {
            while (this->min_data.back() != top_val) {
                temp.push_back(this->min_data.back());
                this->min_data.pop_back();
            }

            this->min_data.pop_back();

            while (! temp.empty()) {
                this->min_data.push_back(temp.back());
                temp.pop_back();
            }
        }

    };


    T top(){
        return  this->data.back();
    };

    T getMin(){
        return this->min_data.back();

    };

    bool isEmpty(){
        return this->data.empty();
    };


private:
    vector<T> data;
    vector<T> min_data;
};
