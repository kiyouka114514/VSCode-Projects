#include <iostream>
using namespace std;
// 堆排序，向下调整建堆，时间复杂度为O(n)
void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
// 向下调整
void DownAdjust(int a[],int i,int n)
{
    // 对以a[i]为根的堆子树进行向下调整
    int now = i;    // 当前下标的结点
    int next;       //值最大的孩子的下标
    while(2*now<=n)
    {
        next = 2 * now;     //now的左孩子的下标
        if(next+1<=n && a[next+1]>a[next])
        {
            next = next + 1;   // 右孩子存在且右孩子大于左孩子
        }
        if(a[now]<a[next])
        {
            Swap(&a[now], &a[next]);
            now = next;        // 调整后继续向下调整
        }
        else
            break;
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

    // 原地向下调整建堆：先调整小子树
    for (int i = n / 2; i >= 1;i--){
        DownAdjust(a, i, n);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}