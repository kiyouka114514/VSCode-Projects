#include<iostream>
using namespace std;
#define inf 10001   //模拟无限大
//带权无向图为例，n个点，m条边   n<=100  0<=w<=10000
int n, m;
char v[105];      //顶点
int e[105][105];  //利用二维数组存储图

int Find(char x){
    int j = -1;
    for (j = 1; j <= n; j++)
    {
        if(v[j]==x)
            break;
    }
    return j;
}
int main(){

    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            e[i][j] = inf;        //初始化
        }
    }
    char x, y;
    int xi, yi, w;
    for (int i = 1; i <= m;i++){
        cin >> x >> y >> w;
        xi = Find(x);
        yi = Find(y);
        e[xi][yi] = e[yi][xi] = w;
    }

    char f;
    int fi, d=0;
    cout << "请输入要查找的结点" << endl;
    cin >> f;
    fi = Find(f);
    for (int i = 1; i <= n;i++){
        if(e[fi][i]<inf){
            d++;
        }
    }
    cout << "该结点的度为" << d << endl;
    return 0;
}