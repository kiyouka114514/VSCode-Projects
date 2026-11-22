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
    // 冒泡排序,最好时间复杂度为O（n），最坏时间复杂度为O（n^2）
    int t = 0;
    int flag = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        // 优化：如果已经排序完成，则无需再次排序
        flag = 0;
        for (int j = 1; j <= n - i; j++)
        {
            if(a[j+1]<a[j]){
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
            flag = 1;       // 表面需要仍排序
        }
        if(flag==0){
            break;          // 优化：如果已经排序完成，则无需再次排序
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}