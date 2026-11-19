//              树  ————>  二叉树
#include <iostream>
using namespace std;
const int maxx = 100;

typedef struct Node
{
    char data;        // 数据域
    struct Node *son; // 长子
    struct Node *bro; // 兄弟
} Node, *TreeList;
/*
    *TreeList == Node*
    作用：增强可阅读性
*/
TreeList InitTree(char r)
{

    Node *s = new Node;
    s->data = r;
    s->bro = NULL;
    s->son = NULL;
    return s;
}
/*
    利用递归算法：
    1.找root，找到返回自身，找不到，执行2
    2.找son，找到返回自身，找不到，执行3
    3.找bro，找到返回自身，找不到，返回NULL
*/
Node *Find(TreeList root, char fx)
{
    // 1
    if (root->data == fx)
        return root;

    Node *ans = NULL;
    // 2
    if (root->son != NULL)
    {
        ans = Find(root->son, fx);
        if (ans != NULL)
            return ans;
    }
    // 3
    if (root->bro != NULL)
    {
        ans = Find(root->bro, fx);
        if (ans != NULL)
            return ans;
    }
    return NULL;
}
TreeList Insert(TreeList root, char x, char fx)
{

    Node *s = new Node;
    s->data = x;
    s->bro = NULL;
    s->son = NULL;

    // 如果x为fx的长子
    Node *p = Find(root, fx);
    if (p->son == NULL)
        p->son = s;
    // 如果fx有长子，则x为fx长子的兄弟
    else
    {
        Node *k = p->son;
        while (k->bro != NULL)
            k = k->bro;
        k->bro = s;
    }
    return root; // 新的树
}
// 找孩子
void FindSon(TreeList root, char x)
{
    Node *p = Find(root, x); // 找到该节点
    if (p == NULL)
        cout << "该节点不存在" << endl;
    else
    {
        Node *k = p->son; // 找到长子
        if (k == NULL)
            cout << "该节点没有孩子" << endl;
        else
        {
            cout << "该节点的孩子有：" << endl;
            while (k != NULL)
            {
                cout << k->data << " ";
                k = k->bro; // 长子的兄弟
            }
            cout << endl;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    char r;
    cin >> r;
    // 创建一个树
    TreeList root = InitTree(r);

    char x, fx;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> fx;
        root = Insert(root, x, fx);
    }

    // 开始查找
    char f;
    cout << "请输入要查找的节点：" << endl;
    cin >> f;
    FindSon(root, f);

    return 0;
}