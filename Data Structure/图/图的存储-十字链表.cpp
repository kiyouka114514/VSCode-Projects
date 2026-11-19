#include <iostream>
using namespace std;
#define inf 10001

// 带权有向图为例，n个点，m条边   n<=100  0<=w<=10000
int n, m;

typedef struct ENode{
    int w;
    int tail;
    int head;
    struct ENode *tnext;
    struct ENode *hnext;
} ENode;

struct Graph{
    char data;
    ENode *firstout;
    ENode *firstin;
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
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i].data;
        g[i].firstin = nullptr;
        g[i].firstout = nullptr;
    }
    char x, y;
    int xi, yi, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w;
        xi = Find(x);
        yi = Find(y);

        // 开始插入
        // x-------->y
        ENode *s = new ENode;
        s->w = w;
        s->tail = xi;
        s->head = yi;
        //s插到x的出边链表中
        s->tnext = g[xi].firstout;
        g[xi].firstout = s;
        // s插到y的入边链表中
        s->hnext = g[yi].firstin;
        g[yi].firstin = s;
    }
    
    char f;
    int fi, d;
    cout << "请输入要查找的结点" << endl;
    cin >> f;
    fi = Find(f);
    ENode *p = g[fi].firstout;
    while (p != nullptr)
    {
        d++;
        p = p->tnext;
    }
    p = g[fi].firstin;
    while (p != nullptr)
    {
        d++;
        p = p->hnext;
    }
    cout << "该结点的度为" << d << endl;

    return 0;
}