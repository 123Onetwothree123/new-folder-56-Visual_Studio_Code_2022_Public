#include <iostream>
#include <cstdio>
const int ArSize = 8;
int sum_arr(int arr[], int n); // arr=array name,n=size
int main(void)
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    int sum = sum_arr(cookies, ArSize);
    std::cout << "Total cookies eaten: " << sum << "\n";
    return 0;
}
int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + arr[i];
    }
    return total;
}
int fill_array(double ar[],int limit){//函数
    double temp;//声明一个double变量
    int i;//声明一个int变量
    for (i = 0; i < limit; i++)//for循环
    {
        std::cout<<"Enter value #"<<(i+1)<<": ";//打印输出
        std::cin>>temp;//输入temp变量，接收输入内容
        if (!std::cin)//bad input如果cin发生了错误，将会执行if语句内容
        {
            std::cin.clear();
            while (std::cin.get()!= '\n')
            {
                continue;
            }
            std::cout<<"Bad input; input process terminated.\n";
            break;
        }else if (temp<0)
        {
            break;
        }
        ar[i]=temp;
    }
    return i;
}