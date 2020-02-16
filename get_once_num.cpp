#include <iostream>

using namespace std;


int get_alone_num(int* target, int lenth)
{
    int result = 0;

    for(int i =0; i <lenth; i++)
    {
        result = (result^target[i]);                // a^0 =a;  a^a =0;  a^b^c^d^b^a = (a^a) ^ (b^b) ^ c= 0 ^ 0 ^ c = c
//        cout << "i= " <<i << "\tresult= " << result << endl;
    }
    return result;
}



//int main()
//{
//    int array[] = {1,56, 4, 3,10,3, 1,4, 56};
//    int result = 0;
//    int lenght =0;
//    lenght = sizeof(array)/sizeof(array[0]);

//    result = get_alone_num(array, lenght);
//    cout << "the alone number: " << result << endl;

//    return 0;
//}
