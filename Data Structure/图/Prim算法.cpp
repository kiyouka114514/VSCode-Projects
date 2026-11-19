#include <iostream>
using namespace std;
#define INF 10001 // 模拟无限大
/*给定一个带权无向连通图：该图中含有n个结点（10<=n<=100），m条边，n个结点的数据刚好是0~n-1
求该图的最小生成树：从m条边中，选出n-1个结点，使得图连通并且边权和最小*/

int n, m;
int g[105][105]; // 利用邻接矩阵存储图
int flag[105];   // 标记数组
int dist[105];   // 距离数组，点x到生成树的最短距离(边权)

int Minn(int x,int y)
{
    return x < y ? x : y;
}
void Prim(){
    int s = 1;  //选取起点
    dist[s] = 0;

    int sum = 0;   // 最小生成树的边权和
    int minn;      // 保存最小dist的下标
    int min_dist;  // 最小dist的值
    // 循环n次，每次选取dist值最小且flag==0的点加入到最小生成树中
    for (int i = 0; i < n; i++)
    {
        minn = -1;
        min_dist = INF;
        // 找出最小的dist
        for (int j = 0; j < n;j++){
            if(flag[j]==0 && dist[j]<min_dist){
                min_dist = dist[j];
                minn = j;
            }
        }
        // 插入到最小生成树中
        sum += min_dist;
        flag[minn] = 1;

        // 更新dist
        for (int j = 0; j < n;j++){
            if(flag[j]==0 && g[minn][j]<INF){
                dist[j] = Minn(dist[j], g[minn][j]);
            }
        }
    }
    cout << "边权和为" << sum << endl;
}
int main()
{
    cin >> n >> m;
    // 初始化
    for (int i = 0; i < n;i++){
        dist[i] = INF;
        for (int j = 0; j < n;j++){
            g[i][j] = INF;
        }
    }
    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;
    }
    Prim();
}