#include <iostream>
using namespace std;

// 堆排序，总时间复杂度都为O(nlogn),空间复杂度为O(1)，不稳定

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
// 方法一
// 向下调整，先填入数组，再向下调整建堆，时间复杂度为O(n)
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
// 方法二
// 向上调整，边填入数组边建立堆，同时向上调整，时间复杂度为O(nlogn)
void UpAdjust(int a[],int i)
{
    int now = i; // 当前下标的结点
    int next;    // 父结点的下标
    while(now>1)
    {
        next = now / 2;
        if(a[now]>a[next])
        {
            Swap(&a[now], &a[next]);
            now = next;
        }
        else
            break;
    }
}

// 向下调整更快，建议使用方法一

int main()
{
    int n, a[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 原地向下调整建堆：
    for (int i = n / 2; i >= 1;i--)
    {
        DownAdjust(a, i, n);
    }

    // 原地向上调整建堆：
    // for (int i = 1; i <= n;i++)
    // {
    //     UpAdjust(a, i);
    // }

    // 开始执行堆排序,时间复杂度O(nlogn)
    // 默认大顶堆，默认升序，最大的数放在最后面
    int r = n;
    for (int i = 1; i <= n - 1; i++)
    {
        Swap(&a[1], &a[r]);
        r--;
        // 头尾交换之后继续向下调整
        DownAdjust(a, 1, r);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}