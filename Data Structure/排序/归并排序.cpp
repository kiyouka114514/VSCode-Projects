#include<iostream>
using namespace std;

// 归并排序，时间复杂度O(nlogn)
void MergeSort(int a[],int l,int r)
{
    // 先分组
    if(l>=r)
        return;
    int mid = (l + r) / 2;      // 一分为二
    MergeSort(a, l, mid);       // a[l]~a[mid]排成升序
    MergeSort(a, mid + 1, r);   // a[mid+1]~a[r]排成升序

    // 再合并（排序）
    int i = l, j = mid + 1;
    int t[105], k = 0;
    while (i <= mid && j <= r)
    {
        if(a[i]<=a[j])
        {
            t[k++] = a[i];
            i++;
        }
        else
        {
            t[k++] = a[j];
            j++;
        }
    }
    // 剩余的数直接放下去
    while(i<=mid)
    {
        t[k++] = a[i];
        i++;
    }
    while (j <= r)
    {
        t[k++] = a[j];
        j++;
    }
    // 将t放回a
    for (int i = 0; i < k;i++)
    {
        a[l + i] = t[i];
    }
}
int main()
{
    int n, a[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    MergeSort(a, 1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}