#include<iostream>
using namespace std;

int m, n;
int f[105];//父结点
int h[105];//高度

// 找到根结点
// int Find(int x){
//     int p = x;
//     while(f[p]!=p){
//         p = f[p];
//     }
//     return p;
// }

// 找到根结点
// 优化：路径压缩————重中之重！
int Find(int x){
    if(x==f[x])
        return x;
    else{
        int p = Find(f[x]);   //找到根结点
        f[x] = p;       
        return p;    //路径压缩，把x插到根结点下
    }
}
int maxx(int a, int b)
{
    return a > b ? a : b;
}

int main(){
    cin >> n >> m;    //n个集合，m次操作
    // 初始化f数组
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    int op, x, y, fx, fy;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if(op==1){
            //合并
            fx = Find(x);
            fy = Find(y);
            // if(fx!=fy){
            //     f[fx] = fy; //合并，根结点改变
            // }
            // 优化（可选择）：按秩合并，以高的树的根结点为合并后的根结点
            if(fx!=fy){
                if(h[fx]>=h[fy]){
                    f[fy] = fx;
                    h[fx] = maxx(h[fx], h[fy] + 1);
                }
                else{
                    f[fx] = fy;
                    h[fy] = maxx(h[fy], h[fx] + 1);
                }
            }
        }
        else{
            //查找
            fx = Find(x);
            fy = Find(y);
            if(fx==fy){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}