#include <iostream>
using namespace std;
#define maxx 105
// 队列结构
typedef struct
{
    int *data; // 队列空间
    int f;     // 仿左端指针
    int r;     // 仿右端指针
} Deque;
// 初始化
Deque InitDeque(Deque q)
{
    q.data = new int[maxx];
    q.f = 0; // 指向待删除
    q.r = 0; // 指向待插入
    return q;
}
// 判空
int IsEmpty(Deque *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
// 右端入队
void RightEnDeque(Deque *q, int x)
{
    // 判满
    if ((q->r + 1) % maxx == q->f)
    {
        cout << "队列已满" << endl;
        return;
    }
    q->data[q->r] = x;          // 先放，再动指针
    q->r = (q->r + 1) % maxx;
}
// 左端入队
void LeftEnDeque(Deque *q, int x)
{
    // 判满
    if ((q->f +maxx- 1) % maxx == q->r)
    {
        cout << "队列已满" << endl;
        return;
    }
    q->f = (q->f+maxx - 1) % maxx; // 先动指针，后放，左右不能相同
    q->data[q->f] = x;
}
// 左端出队
void LeftDe(Deque *q)
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
// 右端出队
void RightDe(Deque *q)
{
    // 判空
    if (IsEmpty(q) == 1)
    {
        cout << "队空" << endl;
        return;
    }
    q->r = (q->r + maxx-1) % maxx;
    int s = q->data[q->r];
    cout << "出队数据为" << s << endl;
}
int main()
{
    Deque q;
    q = InitDeque(q);
    int op;
    do
    {
        cout << "请输入操作" << endl;
        cout << "1.左端入队" << endl;
        cout << "2.右端入队" << endl;
        cout << "3.左端出队" << endl;
        cout << "4.右端出队" << endl;
        cout << "0.退出" << endl;
        cin >> op;
        if (op == 1)
        {
            int n;
            cout << "输入要入队的数据" << endl;
            cin >> n;
            LeftEnDeque(&q, n);
        }
        else if (op == 2)
        {
            int n;
            cout << "输入要入队的数据" << endl;
            cin >> n;
            RightEnDeque(&q, n);
        }
        else if(op==3){
            LeftDe(&q);
        }
        else if(op==4){
            RightDe(&q);
        }
        else
        {
            cout << "请输入正确的值" << endl;
        }

    } while (op);

    return 0;
}