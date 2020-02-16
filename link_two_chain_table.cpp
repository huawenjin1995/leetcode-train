#include <iostream>
#include <list>

using namespace std;


template <class T>
list<T> link_two_sorted_list(list<T> l1, list<T> l2)
{

    list<T> result;
    int total_lenth = l1.size()+ l2.size();

    for(int i=0; i< total_lenth; i++)
    {
        cout <<"i=" <<i << endl;
        if (l1.empty())
        {
            result.merge(l2);
            return result;
        }
        if (l2.empty())
        {
            result.merge(l1);
            return result;
        }
        if(l1.front() <= l2.front())
         {
             result.push_back(l1.front());
             l1.pop_front();
         }
         if(l2.front() < l1.front())
         {
              result.push_back(l2.front());
              l2.pop_front();
         }
     }
//     return result;

}




//int main()
//{
//    typedef list<int> ListInt;
//    ListInt l1={1,1,4,3,5,7,8,9,10,2};
//    ListInt l2={1,2,4,6,9,10};
//    ListInt l3;
//    l1.sort();
//    l2.sort();

//    l3 = link_two_sorted_list(l1,l2);
//    cout <<"l3 size=" << l3.size()<<endl;

//    ListInt ::iterator it;
//    for(it =l3.begin(); it != l3.end(); ++it)
//    {
//        cout << *it << endl;

//    }


//    return 0;
//}
