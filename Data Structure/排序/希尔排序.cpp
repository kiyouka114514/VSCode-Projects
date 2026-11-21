#include <iostream>
using namespace std;

int a[105];
int main()
{
    int n;
    cin >> n;
    // 建立乱序区
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 希尔排序,平均时间复杂度为O(n^1.3),空间复杂度为O(1)
    int k=0;
    for (int d = n / 2; d >= 1; d = d/2)
    {
        int x, j;
        // 从第1组的第2个数据开始排序
        for (int i = 1 + d; i <= n; i+=d)
        {
            x = a[i];     // 乱序区第一个待排序的数据
            // 直接插入排序
            for (j = i - d; j >= 1;j-=d)     // 倒着遍历有序区 
            {
                if(a[j]>x){
                    a[j + d] = a[j];
                }
                else
                    break;
            }
            a[j + d] = x;
        }
        k++;
        cout << "第" << k << "次排序为" << endl;
        for (int i = 1; i <= n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}