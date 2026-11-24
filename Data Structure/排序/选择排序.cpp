#include<iostream>
using namespace std;

// 选择排序，时间复杂度都是O(n^2),空间复杂度O(1)，不稳定
void Swap(int *a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int n, a[105];
int main()
{
    // 建立乱序区
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 选择排序，在乱序区中选择最小的数，放在最左边
    // 循环n-1次
    // 乱序区 1~n
    int minn = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        minn = i;
        for (int j = i + 1; j <= n; j++)
        {
            if(a[j]<a[minn])
            {
                minn = j;
            }
        }
        // 找到最小的数的下标minn
        Swap(&a[i], &a[minn]);
    }

    for (int i = 1; i <= n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}