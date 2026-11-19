#include <iostream>
using namespace std;
#define inf 10001

// 带权无向图为例，n个点，m条边   n<=100  0<=w<=10000
int n, m;

//邻接点链表的结点结构
typedef struct ENode{
    int adj;   //邻接点的下标
    int w;     //边权
    struct ENode *next;
} ENode;

//邻接点结构
struct Graph{
    char data;    //顶点数组
    ENode *first; //头指针，指向邻接点链表
} g[105];

int Find(char x)
{
    int j = -1;
    for (j = 1; j <= n; j++)
    {
        if (g[j].data == x)
            break;
    }
    return j;
}

int main(){

    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> g[i].data;
        g[i].first = nullptr;
    }
    char x, y;
    int xi, yi, w;

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w;
        xi = Find(x);
        yi = Find(y);

        // 开始插入
        // x------y ,y做邻接点
        ENode *s = new ENode;
        s->adj = yi;
        s->w = w;
        s->next = g[xi].first;
        g[xi].first = s;

        // y------x ,x做邻接点
        s = new ENode;
        s->adj = xi;
        s->w = w;
        s->next = g[yi].first;
        g[yi].first = s;
        // 如果是有向图，则只要连接一次，连接出度或者入度，称为邻接表和逆邻接表
    }

    char f;
    int fi, d;
    cout << "请输入要查找的结点" << endl;
    cin >> f;
    fi = Find(f);
    ENode *p = g[fi].first;
    while(p!=nullptr){
        d++;
        p=p->next;
    }
    cout << "该结点的度为" << d << endl;

    return 0;
}