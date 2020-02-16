#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Stack
{
 public:
        void push(T const&elem)     // 入栈
        {
            elems.push_back(elem);
        };

        void pop()                  // 出栈
        {
            if (elems.empty()) {
                throw out_of_range("Stack<>::pop(): empty stack");
            }
            // 删除最后一个元素
            elems.pop_back();
        };

        T top() const               // 返回栈顶元素
        {
            if (elems.empty()) {
                throw out_of_range("Stack<>::top(): empty stack");
            }
            // 返回最后一个元素的副本
            return elems.back();
        };

        bool empty() const{         // 如果为空则返回真。
            return elems.empty();
        }

private:
         vector<T> elems;           // 元素

};




int isValid(char targ, char inpt)		//判断左右括号是否是一对
{
    if ((targ == '(' && inpt == ')') || (targ == '[' && inpt == ']') || (targ == '{' && inpt == '}'))	//有效括号
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int isValidBracket(string &input, int lenth)
{
    Stack<char>  stack;					//创建栈
    printf("in isValidBracket:\nlenth=%d \n", lenth);
    for (int i =0; i < lenth; i++)
    {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{')		//遇到左括号，压入栈
        {
            printf("左括号i=%d, input[i]=%c\n", i,input[i]);

            stack.push(input[i]);
        }

        if (input[i] == ')' || input[i] == ']' || input[i] == '}')		//遇到右括号，与栈顶元素比较
        {
            if (isValid(stack.top(),input[i]))		//栈顶元素跟输入相同
            {
                printf("右括号i=%d, input[i]=%c\n", i, input[i]);
                stack.pop();
            }
            else									//栈顶元素与输入不同，或者栈为空
            {
                return 0;
            }
        }

    }
    if (stack.empty())          //stack is empty
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


//int main()
//{
//    int tar_lenth, result = 0;

//    string target;
//    cout << "请输入只包含括号的字符串：\n";
//    cin >> target;
//    cout << target;
//    tar_lenth = target.length();

//    result = isValidBracket(target, tar_lenth);
//    if (result == 0)
//     {
//        cout << "invalid\n";
//     }
//     else
//     {
//        cout << "valid\n";
//     }

//     return 0;
//}
