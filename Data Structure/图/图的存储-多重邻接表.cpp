#include <iostream>
using namespace std;
#define inf 10001

// 带权无向图为例，n个点，m条边   n<=100  0<=w<=10000
int n, m;

typedef struct ENode
{
    int w;
    int x;
    int y;
    struct ENode *xnext;
    struct ENode *ynext;
} ENode;

struct Graph
{
    char data;
    ENode *first;
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
        g[i].first = nullptr;
    }
    char x, y;
    int xi, yi, w;

    for (int i = 1; i <= m;i++){
        cin >> x >> y >> w;
        xi = Find(x);
        yi = Find(y);

        // 开始插入
        // x--------y
        ENode *s = new ENode;
        s->w = w;     
        //作为x的边，插到x的边链表中
        s->x = xi;
        s->xnext = g[xi].first;
        g[xi].first = s;
        //作为y的边，插到y的边链表中
        s->y = yi;
        s->ynext = g[yi].first;
        g[yi].first = s;
    }

    char f;
    int fi, d;
    cout << "请输入要查找的结点" << endl;
    cin >> f;
    fi = Find(f);
    ENode *p = g[fi].first;
    while (p != nullptr)
    {
        d++;
        if(p->x==fi){
            p = p->xnext;
        }
        else{
            p = p->ynext;
        }
    }
    cout << "该结点的度为" << d << endl;

    return 0;
}