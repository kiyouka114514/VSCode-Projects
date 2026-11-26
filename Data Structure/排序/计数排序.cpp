#include <iostream>
using namespace std;

int n, a[105];
int t[105];
int cnt[10005];
int sum[10005];
int main()
{
    int n, a[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int maxx = a[1];
    for (int i = 1; i <= n;i++)
    {
        cnt[a[i]]++;
        if(a[i]>maxx)
        {
            maxx = a[i];
        }
    }
    sum[1] = cnt[1];
    for (int i = 2; i <= maxx;i++)
    {
        sum[i] = sum[i - 1] + cnt[i];
    }
    int k;
    for (int i = n; i >= 1;i--)
    {
        k = a[i];
        t[sum[k]] = k;
        sum[k]--;
    }
    for (int i = 1; i <= n;i++)
    {
        cout << t[i] << " ";
    }
    
    // 以下版本不稳定
    /*int minn = a[1], maxx = a[1];
    for (int i = 1; i <= n;i++)
    {
        cnt[a[i]]++;
        if(a[i]<minn)
            minn = a[i];
        if(a[i]>maxx)
            maxx = a[i];
    }

    for (int j = minn; j <= maxx;j++)
    {
        for (int i = 1; i <= cnt[j]; i++)
        {
            cout << j << " ";
        }
    }*/
    cout << endl;
    return 0;
}