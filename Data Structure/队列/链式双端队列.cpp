#include <iostream>
using namespace std;

// 带头结点的链队
// 结点结构
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;
// 队列指针结构
typedef struct LinkQueue
{
    QNode *f; // 队首指针
    QNode *r; // 队尾指针
} Queue;

// 初始化
Queue *InitQueue()
{
    // 创建头结点
    QNode *q = new QNode;
    // 创建指针指向头结点
    Queue *Q = new Queue;
    q->next = nullptr;
    Q->f = Q->r = q;
    return Q;
}
// 入队
Queue *EnQueue(Queue *Q, int x)
{
    QNode *q = new QNode;
    q->data = x;
    q->next = nullptr;
    Q->r->next = q;
    Q->r = q;
    return Q;
}
// 判空
int IsEmpty(Queue *Q)
{
    if (Q->f == Q->r)
    {
        return 1;
    }
    return 0;
}
// 出队
Queue *DeQueue(Queue *Q)
{
    if (IsEmpty(Q) == 1)
    {
        cout << "队空" << endl;
        return Q;
    }
    QNode *p = Q->f->next; // 指向首元结点
    cout << "出队的数据为" << p->data << endl;
    Q->f->next = p->next;
    delete p;
    p = nullptr;
    // 首元结点为空时
    if (Q->f->next == nullptr)
    {
        Q->r = Q->f;
    }
    return Q;
}
int main()
{
    Queue *Q = InitQueue();
    int op;
    do
    {
        cout << "请输入操作" << endl;
        cout << "1.入队" << endl;
        cout << "2.出队" << endl;
        cout << "0.退出" << endl;
        cin >> op;
        if (op == 1)
        {
            int n;
            cout << "输入要入队的个数和数据" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int m;
                cin >> m;
                Q = EnQueue(Q, m);
            }
        }
        else if (op == 2)
        {
            Q = DeQueue(Q);
        }
        else if (op != 0)
        {
            cout << "请输入正确的值" << endl;
        }

    } while (op);
    return 0;
}