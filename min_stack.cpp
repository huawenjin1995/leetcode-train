#include <iostream>
#include "stack.h"


int main()
{
    Stack<int> stack;
    int a[] = {-10, 9, -7, -1, 1,3,-1,0,8,-3,2,5,-2};
    int lenth = 0;
    lenth = sizeof(a) / sizeof(a[0]);

    for (int i=0; i<lenth; i++)
    {
        stack.push(a[i]);
    }
    cout << "top: " << stack.top() << "\tmin: " << stack.getMin()<<endl;
    stack.pop();
    cout << "top: " << stack.top() << "\tmin: " << stack.getMin()<<endl;
    stack.push(-10);
    cout << "top: " << stack.top() << "\tmin: " << stack.getMin()<<endl;


}
