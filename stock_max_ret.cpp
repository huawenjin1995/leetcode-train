#include <iostream>


using namespace std;


int get_max_ret(int* prices, int lenth)
{
    if (lenth == 0)
    {
        return 0;
    }
    int min = prices[0];
    int ret = 0;
    int temp = 0;
    for (int i = 0; i < lenth; i++)
    {
        min = (min <= prices[i] ? min : prices[i]);   		//记录最小值
        temp = prices[i] - min;								//计算每一个元素与最小值的差
        ret = (ret > temp ? ret : temp);					//保留最大利润
//        printf("i=%d\tmin=%d\tret=%d\n",i, min, ret );
    }
    return ret;
}



//int main()
//{
//    int prices[] = {1, 3, 5, 7, 0, 5};
//    int lenth = sizeof(prices)/sizeof(prices[0]);
////    printf("lenth=%d\n",lenth );
//    int max_ret ;
//    max_ret = get_max_ret(prices, lenth);
//    printf("max_ret=%d\n", max_ret );

//    return 0;
//}
