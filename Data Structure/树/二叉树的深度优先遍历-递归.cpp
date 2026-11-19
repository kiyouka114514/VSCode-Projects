#include <iostream>
using namespace std; 

// 二叉树
typedef struct BTNode
{
    char data;
    struct BTNode *l; // 左孩子
    struct BTNode *r; // 右孩子
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
// 先序遍历
void PreOrderBT(BTree root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrderBT(root->l);
    PreOrderBT(root->r);
}
// 中序遍历
void InOrderBT(BTree root)
{
    if (root == NULL)
        return;
    InOrderBT(root->l);
    cout << root->data << " ";
    InOrderBT(root->r);
}
// 后序遍历
void PostOrderBT(BTree root)
{
    if (root == NULL)
        return;
    PostOrderBT(root->l);
    PostOrderBT(root->r);
    cout << root->data << " ";
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
    
    PreOrderBT(root);
    InOrderBT(root);
    PostOrderBT(root);
    return 0;
}