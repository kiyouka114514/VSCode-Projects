#include <iostream>
using namespace std;

// 快速排序，时间复杂度为O(nlogn)，最坏为O(n^2)
// 就地排序，但空间复杂度为O(logn)，最坏O(n)
void Qsort(int a[], int l, int r)
{
    // 递归出口
    if (l >= r)
    {
        return;
    }
    int p = a[l];               // 选择第一个数为基准数
    int i = l, j = r;
    while(i<j)
    {
        // 前面空了一个位置a[i]，用j从后往前遍历，找比p小的数据，补过去
        while(i<j && a[j]>p)
            j--;
        if(i<j)
        {
            a[i] = a[j];
            i++;
        }
        // 后面空一个位置a[j]，用i从前往后遍历，找比p大的数据，补过去
        while(i<j && a[i]<p)
            i++;
        if(i<j)
        {
            a[j] = a[i];
            j--;
        }
    }
    // i==j时
    a[i] = p;
    Qsort(a, l, i - 1);
    Qsort(a, i + 1, r);
}
int main()
{
    int n, a[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Qsort(a, 1, n);
    for (int i = 1; i <= n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}