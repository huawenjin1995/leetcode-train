#include <iostream>

using namespace std;


int get_max_sum_subsequence(int* target, int lenth)		//获取最大和子序列
{
    int sum = target[0];
    int max_sum = sum;

    for (int i=0; i <lenth; i++)
    {

        if (sum+target[i] >= 0)
        {
            sum = sum+target[i];
            sum = (sum > target[i] ? sum : target[i]); /*max(sum, target[i])*/;
        }

        max_sum = (sum > max_sum ? sum : max_sum);      /*max(sum, max_sum);*/

//        printf("i=%d , max_sum=%d\n",i, max_sum);
    }
    return max_sum;


}


//int main()
//{

//    int array[] = {-1,-2,-3,100,0,-10,3,10};

//    int lenth = sizeof(array)/sizeof(array[0]);
//    printf("lenth=%d\n",lenth);
//    int max_sum = get_max_sum_subsequence(array, lenth);
//    printf("max_sum=%d\n", max_sum);
//}
