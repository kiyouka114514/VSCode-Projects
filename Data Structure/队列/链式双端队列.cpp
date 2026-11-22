#include <iostream>
using namespace std;

// 带头结点的链队
// 结点结构
typedef struct QNode
{
    int data;
    struct QNode *next;
    struct QNode *pre;
} QNode;
// 队列指针结构
typedef struct Deque
{
    QNode *f; // 队首指针
    QNode *r; // 队尾指针
} Deque;

// 初始化
Deque *InitDeque()
{
    // 创建头结点
    QNode *q = new QNode;
    // 创建指针指向头结点
    Deque *Q = new Deque;
    q->next = nullptr;
    q->pre = nullptr;
    Q->f = Q->r = q;
    return Q;
}


// 未完待续