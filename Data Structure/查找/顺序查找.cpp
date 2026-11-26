#include<iostream>
using namespace std;

// 顺序查找，时间复杂度O(n)，不要求有序
int a[105], n, k;
int main()
{
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    int ans = -1;
    cin>>k;
    for (int i = 1; i <= n;i++)
    {
        if(a[i]==k)
        {
            ans = i;
            break;
        }
    }
    cout << ans <<endl;
    return 0;
}