#include<iostream>
using namespace std;
#define INF 10005
/*给定一个带权无向连通图：该图中含有n个结点（10<=n<=100），m条边，n个结点的数据刚好是0~n-1*/

int n, m;
int g[105][105];     // 利用邻接矩阵存图
int flag[105];       // 标记数组
int dist[105];       // 最短距离
int pre[105];        // 记录上一个转接点

void Dijkstra(int s)
{
    dist[s] = 0;
    pre[s] = -1;
//     flag[s] = 1;
//     // 更新起点的邻接点的最短路径
//     for (int i = 0; i < n;i++){
//         if(i!=s && g[s][i]<INF)
//         {
//             dist[i] = g[s][i];
//             pre[i] = s;
//         }
//     }

    int minn;     // 保存最小dist的下标
    int min_dist; // 最小dist的值
    // 循环n-1次，找到dist最小且flag==0的结点作为转接点，更新它的邻接点的dist
    for (int i = 0; i < n; i++)    // 如果前面有起点更新，则循环n-1次
    {
        minn = -1;
        min_dist = INF;
        // 找到最小路径
        for (int j = 0; j < n; j++)
        {

            if (flag[j] == 0 && dist[j] < min_dist)
            {
                min_dist = dist[j];
                minn = j;
            }
        }

        // 将其作为转接点，已确定其最小路径
        flag[minn] = 1;

        // 更新转接点的邻接点的dist
        for (int j = 0; j < n; j++)
        {
            if (flag[j] == 0 && g[minn][j] < INF)
            {
                if (dist[minn] + g[minn][j] < dist[j])
                {
                    dist[j] = dist[minn] + g[minn][j];
                    pre[j] = minn;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "到" << s << "的最短路径为" << dist[i] << endl;
        int p = pre[i];
        while (p != -1)
        {
            cout << p << " ";
            p = pre[p];
        }
        cout << endl;
    }
}
int main(){
    cin >> n >> m;
    // 初始化
    for (int i = 0; i < n;i++){
        dist[i] = INF;
        pre[i] = -1;
        for (int j = 0; j < n; j++)
        {
            if(i==j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }
    // 存边
    int x, y, w;
    for (int i = 0; i < m;i++){
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;
    }
    Dijkstra(0);
}