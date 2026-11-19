#include<iostream>
using namespace std;

const int maxx = 105;

// 循环队列
typedef struct 
{
    int data[maxx];    //顶点下标入队
    int f;             //仿队首指针
    int r;             //仿队尾指针
} Queue;
//初始化
void InitQueue(Queue* q){
    q->f = 0;
    q->r = 0;
}
// 入队
void EnQueue(Queue *q, int i)
{

    if ((q->r + 1 % maxx) == q->f)
    {
        cout << "队满，不能入队" << endl;
        return;
    }
    q->data[q->r] = i;
    q->r = (q->r + 1) % maxx;
}
//判空
int isEmpty(Queue* q){
    if(q->f==q->r){
        return 1;   //空
    }
    return 0;      //非空
}
//出队
int DeQueue(Queue *q){
    if(isEmpty(q)==1){
        cout << "队空，无法出队" << endl;
        return;
    }
    int s = q->data[q->f];
    q->f = (q->f + 1) % maxx;
    return s;
}

//以无权无向图为例
int n, m;
// 邻接点链表的结点结构
typedef struct ENode
{
    int adj; // 邻接点的下标
    struct ENode *next;
} ENode;

// 邻接点结构
struct Graph
{
    char data;    // 顶点数组
    ENode *first; // 头指针，指向邻接点链表
} g[105];

//标记数组
int flag[maxx];
// 距离数组
int dist[maxx];
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
// 广度遍历, 从i开始遍历
void BFS(int i){

    //初始化距离数组
    for (int i = 1; i <= n;i++){
        dist[i] = maxx;
    }

    Queue q;
    InitQueue(&q);
    //起点入队
    EnQueue(&q, i);
    flag[i] = 1;   //i点已入队
    dist[i] = 0;

    int x, j;
    ENode *p = nullptr;
    while (isEmpty(&q) == 0)
    {
        x = DeQueue(&q);
        cout << g[x].data << " ";
        p = g[x].first;
        while(p!=nullptr){
            j = p->adj;
            if (flag[j] == 0)
            {
                EnQueue(&q, j);
                flag[j] == 1;
                dist[j] = dist[x] + 1;
            }
            p = p->next;
        }
    }
}
//使用邻接表时间复杂度为 n+m，使用邻接矩阵时间复杂度为n*n
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
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
        s->next = g[xi].first;
        g[xi].first = s;

        // y------x ,x做邻接点
        s = new ENode;
        s->adj = xi;
        s->next = g[yi].first;
        g[yi].first = s;
    }

    // 开始遍历
    // 如果为非连通图，则可以通过循环，找到未遍历的结点
    for (int i = 1; i <= n; i++)
    {
        if(flag[i]==0) BFS(i);
    }
    //计算距离
    char f;
    int fi;
    cout << "输入你要查询的结点" << endl;
    cin >> f;
    fi = Find(f);
    cout << "该结点与起始位置的距离是 " << dist[fi] << endl;
    return 0;
}