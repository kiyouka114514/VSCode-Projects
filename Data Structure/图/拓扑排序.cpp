#include<iostream>
using namespace std;
#define INF 10005
// 利用链栈来存放度为0的结点，利用邻接表来存图
//----------- 链栈--------------------
typedef struct stackNode{
    int data;             // 顶点下标
    struct stackNode *next;
} SNode, *Stack;
// 初始化
Stack InitStack(){
    Stack s = new SNode;
    s->next = nullptr;
    return s;
}
// 入栈
Stack Push(Stack s,int k){
    SNode *p = new SNode;
    p->data = k;
    p->next = s->next;
    s->next = p;
    return s;
}
// 判空
int IsEmpty(Stack s){
    if (s->next == nullptr)
    {
        return 1;
    }
    return 0;
}
// 获取栈顶数据
int GetTop(Stack s){
    if(IsEmpty(s)==0){
        return s->next->data;
    }
    else{
        return -1;
    }
}
// 出栈
Stack Pop(Stack s){
    if(IsEmpty(s)==0){
        SNode *p = s->next;
        s->next = p->next;
        delete p;
        p = nullptr;
    }
    return s;
}

// 邻接表存储无权有向图
// n个结点，m条边 ,n<100
int n, m;
// 邻接点链表的结点结构
typedef struct ENode{
    int adj;
    struct ENode *next;
} ENode;
// 邻接点结构
struct Graph
{
    char data;    // 顶点数组
    ENode *first; // 头指针，指向邻接点链表
} g[105];

int ind[105];     // 入度数组
int topo[105], k = 0; // 拓扑序列数组和数组下标

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
// 拓扑排序
void TopoSort(){
    // 建立一个栈并初始化
    Stack s = InitStack();
    // 找到入度为0的结点，入栈
    for (int i = 1; i <= n;i++){
        if(ind[i]==0){
            s = Push(s, i);
        }
    }
    int j;
    ENode *p = nullptr;
    for (int i = 1; i <= n; i++)
    {
        // 判空，防止成环
        if(IsEmpty(s)==1){
            break;
        }
        // 出栈
        j = GetTop(s);
        s = Pop(s);
        topo[++k] = j;
        p = g[j].first;
        while(p!=nullptr){

            ind[p->adj]--;
            if(ind[p->adj]==0)
                s = Push(s, p->adj);
            p = p->next;
        }
    }
}
void ShowTopo(){
    if(k<n){
        cout << "有环" << endl;
        cout << k;
    }
    else{
        for (int i = 1; i <= n;i++){
            cout << g[topo[i]].data << " ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i].data;
        g[i].first = nullptr;
    }
    char x, y;
    int xi, yi;

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        xi = Find(x);
        yi = Find(y);

        // 开始插入
        // x------>y ,y做邻接点
        ind[yi]++;             // y的入度+1
        ENode *s = new ENode;
        s->adj = yi;
        s->next = g[xi].first;
        g[xi].first = s;

    }
    TopoSort();
    ShowTopo();
    return 0;
}