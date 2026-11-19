#include <iostream>
using namespace std;
// 队列
typedef struct QNode
{
    char data;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *f; // 队首
    QNode *r; // 队尾
} Queue;

Queue Initqueue()
{
    Queue q;
    q.f = new QNode;
    q.f->next = NULL;
    q.r = q.f;
    return q;
}

void enqueue(Queue *q, char x)
{
    QNode *s = new QNode;
    s->data = x;
    s->next = NULL;
    q->r->next = s;
    q->r = s;
}

int empty(Queue *q)
{
    if (q->f->next == NULL)
        return 1; // 空
    else
        return 0; // 非空
}

char dequeue(Queue *q)
{
    char x = ' ';
    if (empty(q) == 1)
        cout << "队空" << endl;
    else
    {
        QNode *p = q->f->next;
        x = p->data;
        // 若出队的是队尾,则队尾指针回退到队首
        if (q->r == q->f->next)
        {
            q->r = q->f;
        }
        q->f->next = p->next;
        delete p;
        p = NULL;
    }
    return x;
}

// 二叉树
typedef struct BTNode
{
    char data;
    struct BTNode *l;  // 左孩子
    struct BTNode *r;  // 右孩子
} BTNode, *BTree;

BTree InitBTree(char r)
{
    BTNode *s = new BTNode;
    s->data = r;
    s->l = NULL;
    s->r = NULL;
    return s;
}
/*
    查找思路:
    1.若root结点就是要找的结点,则返回root(结束条件)
    2.否则递归查找l(左)子树
    3.否则递归查找r(右)子树,都找不到返回NULL
*/
BTNode *Find(BTree root, char x)
{
    if (root->data == x)
        return root;

    BTNode *ans = NULL;
    if (root->l != NULL)
    {
        ans = Find(root->l, x);
        if (ans != NULL)
            return ans;
    }
    if (root->r != NULL)
    {
        ans = Find(root->r, x);
        if (ans != NULL)
            return ans;
    }
    return NULL;
}
BTree Insert(BTree root, char x, char fx, int flag)
{
    BTNode *s = new BTNode;
    s->data = x;
    s->l = NULL;
    s->r = NULL;

    BTNode *p = Find(root, fx);
    if (flag == 0)
        p->l = s;
    else
        p->r = s;
    return root;
}
// 层次遍历
void LevelOrderBT(BTree root)
{
    if (root == NULL)
        return;
    Queue q = Initqueue();
    enqueue(&q, root->data);

    char x;
    BTNode *p = NULL;
    while (empty(&q) == 0)
    {
        x = dequeue(&q);
        cout << x << " ";
        p = Find(root, x);
        if (p->l != NULL)
            enqueue(&q, p->l->data);
        if (p->r != NULL)
            enqueue(&q, p->r->data);
    }
    cout << endl;
}
int main()
{

    int n, flag;
    cin >> n;
    char r;
    cin >> r;
    BTree root = InitBTree(r);

    // 建树
    char x, fx;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> fx >> flag;
        root = Insert(root, x, fx, flag);
    }

    LevelOrderBT(root);
    return 0;
}