#include<iostream>
using namespace std;

/*给定一个带权无向连通图：该图中含有n个结点（10<=n<=100），m条边，n个结点的数据刚好是0~n-1
求该图的最小生成树：从m条边中，选出n-1个结点，使得图连通并且边权和最小*/
// 采用边集数组存图
int n, m;
typedef struct{
    int w;    // 边权
    int u, v; // 无向边的两个端点
} Edge;
Edge e[10005];  // 边
int f[105];     // 结点，并查集

// 选择排序   （时间复杂度为n*n）
void Sortt(int l,int r){
    int minn;
    Edge t;
    for (int i = l; i <= r; i++)
    {
        minn = i;
        for (int j = i; j <= r;j++){
            if(e[j].w<e[minn].w){
                minn = j;
            }
        }

        t = e[i];
        e[i] = e[minn];
        e[minn] = t;
    }
}
//找根结点
int Find(int x)
{
    if (x == f[x])
        return x;
    else
    {
        int p = Find(f[x]); // 找到根结点
        f[x] = p;
        return p; // 路径压缩，把x插到根结点下
    }
}
void Kruskal(){
    //初始化并查集
    for (int i = 0; i < n;i++){
        f[i] = i;
    }
    int sum = 0; // 边权和
    int cnt = 0; // 选择的边数
    int fv, fu;
    for (int i = 1; i <= m; i++)
    {
        fv = Find(e[i].v);
        fu = Find(e[i].u);
        if(fv!=fu){
            f[fu] = fv;
            sum += e[i].w;
            cnt++;
            //可选
            // cout << "新增连接" << endl;
            // cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
        }
        if(cnt==n-1)    // 最多n-1条边
            break;
    }
    cout << "边权和为" << sum << endl;
}

int main(){

    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    Sortt(1, m);
    Kruskal();
}