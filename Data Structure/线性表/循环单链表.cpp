#include <iostream>
using namespace std;

// 与单链表相似，把与尾结点相关的改动即可

// 结点结构
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化
LinkList InitLink()
{
    LNode *head = new LNode;
    head->next = head;     // 自己指向自己
    return head;
}
// 查找
LNode *FindLNode(LinkList L, int x)
{
    LNode *p = L->next; // 首元结点
    while (p != L && p->data != x)    // p不可能为空
    {
        p = p->next;
    }
    if (p == L)
    {
        cout << "未找到该结点" << endl;
    }
    return p;
}
// 插入
// 头插法
LinkList HeadInsert(LinkList L, int x)
{
    LNode *n = new LNode;
    n->data = x;
    n->next = L->next;    // 第一个插入时L->next为L它自己
    L->next = n;
    return L;
}
// 尾插法
LinkList RearInsert(LinkList L, int x)
{
    LNode *n = new LNode;
    n->data = x;
    n->next = L;
    LinkList p = L; // 必须从表头开始
    while (p->next != L)
    {
        p = p->next;
    }
    p->next = n;
    return L;
}
// 指定位置插入(某值之后)
LinkList Insert(LinkList L, int x, int nx)
{
    LinkList p = FindLNode(L, x);
    if (p != L)
    {
        LNode *n = new LNode;
        n->data = nx;
        n->next = p->next;
        p->next = n;
    }
    return L;
}
// 删除（某值）
LinkList Delete(LinkList L, int x)
{
    LinkList p = L->next;
    LinkList pre = L;
    while (p != L && p->data != x)
    {
        p = p->next;
        pre = pre->next;
    }
    if (p == L)
    {
        cout << "未找到该值" << endl;
    }
    else
    {
        pre->next = p->next;
        delete p;
        p = nullptr; // 注意：防止野指针
    }
    return L;
}
// 修改
LinkList ReviseLNode(LinkList L, int x, int nx)
{
    LinkList p = FindLNode(L, x);
    if (p != L)
    {
        p->data = nx;
    }
    return L;
}
void Show(LinkList L)
{
    LinkList p = L->next;
    if (p == L)
    {
        cout << "空链表" << endl;
    }
    while (p != L)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{

    LinkList L = InitLink();

    int op;
    do
    {
        cout << "请输入操作" << endl;
        cout << "1.添加" << endl;
        cout << "2.指定位置插入" << endl;
        cout << "3.指定位置删除" << endl;
        cout << "4.修改某值" << endl;
        cout << "5.展示" << endl;
        cout << "0.退出" << endl;
        cin >> op;
        if (op == 1)
        {
            int n;
            cout << "输入要添加的个数" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int m;
                cin >> m;
                L = HeadInsert(L, m);
            }
        }

        else if (op == 2)
        {
            int n, x;
            cout << "输入要插入的位置和值" << endl;
            cin >> x >> n;
            L = Insert(L, x, n);
        }

        else if (op == 3)
        {
            int x;
            cout << "输入删除的值" << endl;
            cin >> x;
            L = Delete(L, x);
        }
        else if (op == 4)
        {
            int x, nx;
            cout << "输入修改的值和新值" << endl;
            cin >> x >> nx;
            L = ReviseLNode(L, x, nx);
        }
        else if (op == 5)
        {
            Show(L);
        }
        else if (op == 0)
        {
            break;
        }
        else
        {
            cout << "请输入正确的值" << endl;
        }

    } while (op);
    return 0;
}
