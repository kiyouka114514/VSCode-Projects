#include <iostream>
using namespace std;
const int maxx = 100;

typedef struct Node
{
    int son; // 孩子下标
    Node *next;
} SonNode;

struct Tree
{
    char data;
    SonNode *first; // 指向第一个孩子的指针
} t[maxx];

int len;
// 查找下标
int Find(char fx)
{
    for (int i = 0; i <= len - 1; i++)
    {
        if (t[i].data == fx)
            return i;
    }
}
// 插入新节点
void Insert(char x, char fx)
{
    t[len].data = x;
    t[len].first = NULL;

    int i = Find(fx);
    SonNode *s = new SonNode;
    /*  c
        SonNode* s=(SonNode*)malloc(sizeof(SonNode));
    */
    s->son = len;
    // 头插法(无序树）
    s->next = t[i].first;
    t[i].first = s;
    len++;
}

// 找孩子
void FindSon(char x)
{
    int i = Find(x);
    SonNode *p = t[i].first;
    if (p == NULL)
        cout << "该节点没有孩子" << endl;
    else
    {
        cout << "该节点的孩子为：" << endl;
        while (p != NULL)
        {
            cout << t[p->son].data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

// 找父亲
void FindFa(char x)
{

    int i = Find(x);
    SonNode *p = t[i].first;
    int flag = 0;
    for (int k = 0; k < len; k++)
    {
        p = t[k].first;
        while (p != NULL)
        {
            if (p->son == i)
            {
                cout << "该节点的父亲为：" << endl;
                cout << t[k].data << endl;
                flag = 1;
                break;
            }
            p = p->next;
            if (flag)
                break;
        }
    }
    if (flag == 0)
        cout << "该节点没父亲" << endl;
}

int main()
{

    int n;
    cin >> n;
    char r;
    cin >> r;
    t[0].data = r;
    t[0].first = NULL;
    len++;

    char x, fx;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> fx;
        Insert(x, fx);
    }

    // 开始查找
    char f;
    cout << "请输入要查找的节点：" << endl;
    cin >> f;
    FindSon(f);
    FindFa(f);
    return 0;
}