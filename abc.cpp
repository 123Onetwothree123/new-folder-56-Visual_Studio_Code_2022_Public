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
int fill_array(double ar[],int limit){
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        std::cout<<"Enter value #"<<(i+1)<<": ";
        std::cin>>temp;
        if (!std::cin)
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