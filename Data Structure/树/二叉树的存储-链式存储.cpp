#include <iostream>
using namespace std;

typedef struct BTNode
{
    char data;
    struct BTNode *l; // 左孩子
    struct BTNode *r; // 右孩子
    // struct BTNode *fa; // 父亲结点,若需要找父亲，可以加上
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
    利用递归算法：
    1.找root，找到返回自身，找不到，执行2
    2.找l，找到返回自身，找不到，执行3
    3.找r，找到返回自身，找不到，返回NULL
*/
BTNode *Find(BTree root, char x)
{
    if (root->data = x)
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
// 找儿子
void FindSon(BTree root, char x)
{
    BTNode *s = Find(root, x);

    if (s->l == NULL)
        cout << "该结点没有左孩子" << endl;
    else
        cout << "该结点的左孩子是" << s->l->data << endl;
    if (s->r == NULL)
        cout << "该结点没有右孩子" << endl;
    else
        cout << "该结点的右孩子是" << s->r->data << endl;
}
int main()
{

    int n, flag;
    cin >> n;
    char r;
    cin >> r;
    BTree root = InitBTree(r);

    // 插入
    char x, fx;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> fx >> flag;
        root = Insert(root, x, fx, flag);
    }

    // 开始查找
    char f;
    cout << "请输入要查找的节点：" << endl;
    cin >> f;
    FindSon(root, f);

    return 0;
}