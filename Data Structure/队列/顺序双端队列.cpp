#include <iostream>
using namespace std;
#define maxx 105
// 队列结构
typedef struct
{
    int *data; // 队列空间
    int f;     // 仿队首指针
    int r;     // 仿队尾指针
} Queue;
// 初始化
Queue InitQueue(Queue q)
{
    q.data = new int[maxx];
    q.f = 0; // 指向待删除
    q.r = 0; // 指向待插入
    return q;
}
// 判空
int IsEmpty(Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
// 入队
void EnQueue(Queue *q, int x)
{
    // 判满
    if ((q->r + 1) % maxx == q->f)
    {
        cout << "队列已满" << endl;
        return;
    }
    q->data[q->r] = x;
    q->r = (q->r + 1) % maxx;
}
// 出队
void DeQueue(Queue *q)
{
    // 判空
    if (IsEmpty(q) == 1)
    {
        cout << "队空" << endl;
        return;
    }
    int s = q->data[q->f];
    q->f = (q->f + 1) % maxx;
    cout << "出队数据为" << s << endl;
}

int main()
{
    Queue q;
    q = InitQueue(q);
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
                EnQueue(&q, m);
            }
        }
        else if (op == 2)
        {
            DeQueue(&q);
        }
        else
        {
            cout << "请输入正确的值" << endl;
        }

    } while (op);

    return 0;
}