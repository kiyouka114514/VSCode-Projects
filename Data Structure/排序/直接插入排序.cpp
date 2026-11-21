#include <iostream>
using namespace std;

int a[105];
int main()
{
    int n;
    cin >> n;
    // 建立乱序区
    for(int i = 1; i <= n;i++){
        cin >> a[i];
    }
    // 直接插入排序，平均时间复杂度O(n^2)，空间复杂度O(1)
    // 默认开始有序区 1 乱序区 2~n
    int x, j;
    for (int i = 1; i < n; i++)
    {
        x = a[i + 1];
        for (j = i; j >= 1;j--){
            if(a[j]>x)
            {
                a[j + 1] = a[j];    // 有序区+1，乱序区-1
            }
            else
            {
                break;
            }
        }
        a[j+1] = x;
    }
    for (int i = 1; i <= n;i++){
        cout << a[i] << " ";
    }
}