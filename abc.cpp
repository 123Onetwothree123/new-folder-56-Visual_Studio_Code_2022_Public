#include <iostream>
#include <cstdio>
const int ArSize = 8;
const int Max = 5;
int sum_arr(int arr[], int n);              // arr=array name,n=size
int fill_array(double ar[], int limit);     //填充数组
void show_array(const double ar[], int n);  //显示数据及用const保护数组don't change data不要更改数据
void revalue(double r, double ar[], int n); //修改数组
int main(void)
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    int sum = sum_arr(cookies, ArSize);
    std::cout << "Total cookies eaten: " << sum << "\n";
    printf("-------------------------------------------\n");
    //将填充数组，显示数据及用const保护数组，修改数组的函数的上述代码组合起来
    double properties[Max];//创建一个double类型的数组
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        printf("Enter revaluation factor: ");
        double factor;
        while (!(std::cin >> factor))
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
            {
                continue;
            }
            printf("Bad input; Please enter a number: ");
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    printf("Done.\n");
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
int fill_array(double ar[], int limit)//填充数组
{                               //函数
    double temp;                //声明一个double变量
    int i;                      //声明一个int变量
    for (i = 0; i < limit; i++) // for循环，i赋值为0，如果i<limit开始执行循环，条件不满足将会停止
    {
        std::cout << "Enter value #" << (i + 1) << ": "; //打印输出
        std::cin >> temp;                                //输入temp变量，接收输入内容
        if (!std::cin)                                   // bad input如果cin发生了错误，将会执行if语句内容
        {
            std::cin.clear();              // std::cin.clear让错误标识改回为0
            while (std::cin.get() != '\n') //输入内容只要不是换行符，将执行while循环
            {
                continue; //结束本次循环，进行下一次循环，而不终止整个循环的执行。
            }
            std::cout << "Bad input; input process terminated.\n"; //打印输出
            break;//跳出
        }
        else if (temp < 0) //如果temp<0将执行这一个分支
        {
            break; //跳出
        }
        ar[i] = temp; //赋值，将temp的值赋给ar[i]
    }
    return i; //函数最后返回i
}
void show_array(const double ar[], int n)//显示数据及用const保护数组don't change data不要更改数据
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Property #" << (i + 1) << ": $";
        std::cout << ar[i] << std::endl;
    }
}
void revalue(double r, double ar[], int n)//修改数组
{
    for (int i = 0; i < n; i++)
    {
        ar[i] *= r;
    }
} //由于这个函数将修改数组的值，因此在声明ar时，不能使用const。