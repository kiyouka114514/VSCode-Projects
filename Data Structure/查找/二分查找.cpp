#include <iostream>
using namespace std;

// 二分查找，时间复杂度O(logn)，要求有序(升序)
int a[105], n, k;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = -1;
    cin >> k;
    int l = 1, r = n;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (k == a[mid])
        {
            ans = mid;
            break;
        }
        else if(k>a[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}