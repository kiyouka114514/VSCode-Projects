#include <iostream>
using namespace std;
#define inf 10001 // 模拟无限大

int n, m;
char v[105];     // 顶点
int e[105][105]; // 利用二维数组存储图
int flag[105];

int Find(char x)
{
    int j = -1;
    for (j = 1; j <= n; j++)
    {
        if (v[j] == x)
            break;
    }
    return j;
}

void DFS(int i){
    cout << v[i] << " ";
    flag[i] = 1;
    for (int j = 1; j <= n;j++){
        if(e[i][j]==1 && flag[i]==0){
            DFS(j);
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            e[i][j] = inf; // 初始化
        }
    }
    char x, y;
    int xi, yi;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        xi = Find(x);
        yi = Find(y);
        e[xi][yi] = e[yi][xi] = 1;
    }

    for (int i = 1; i <= n;i++){
        if(flag[i]==0)
        DFS(i);
    }
    return 0;
}