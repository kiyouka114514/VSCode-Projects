#include <iostream>
using namespace std;

// 树结点
typedef struct BTNode
{
    char data;
    struct BTNode *l;
    struct BTNode *r;
} BTNode, *BTree;

// 将树的结点入栈
typedef struct stackNode
{
    BTNode *data;
    struct stackNode *next;
} sstack;

sstack *Initstack()
{
    sstack *s = new sstack;
    s->next = nullptr;
    return s;
}

void Push(sstack *s, BTNode *k)
{
    sstack *p = new sstack;
    p->data = k;
    p->next = s->next;
    s->next = p;
}

int Empty(sstack *s)
{
    if (s->next == nullptr)
        return 1;
    return 0;
}

BTNode *Pop(sstack *s)
{
    if (Empty(s) == 1)
    {
        cout << "栈空" << endl;
        return nullptr;
    }
    sstack *p = s->next;
    BTNode *k = p->data;
    s->next = p->next;
    delete p;
    p = nullptr;
    return k;
}

// 获得栈顶元素
BTNode *Get(sstack *s)
{
    if (Empty(s) == 1)
    {
        cout << "栈空" << endl;
        return nullptr;
    }
    BTNode *k = s->next->data;
    return k;
}

//-----------树---------------

BTree InitBTree(char r)
{
    BTNode *s = new BTNode;
    s->data = r;
    s->l = nullptr;
    s->r = nullptr;
    return s;
}

BTNode *Find(BTree root, char x)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == x)
        return root;

    BTNode *ans = nullptr;
    if (root->l != nullptr)
    {
        ans = Find(root->l, x);
        if (ans != nullptr)
            return ans;
    }
    if (root->r != nullptr)
    {
        ans = Find(root->r, x);
        if (ans != nullptr)
            return ans;
    }
    return nullptr;
}
BTree Insert(BTree root, char x, char fx, int flag)
{
    BTNode *s = new BTNode;
    s->data = x;
    s->l = nullptr;
    s->r = nullptr;

    BTNode *p = Find(root, fx);
    //防止p变成空指针，队空指针解引用报错
    if (p == nullptr)
    {
        cout << "父结点 " << fx << " 不存在" << endl;
        delete s;
        return root;
    }
    if (flag == 0)
        p->l = s;
    else
        p->r = s;
    return root;
}
// 先序遍历
void PreOrderBT(BTree root)
{
    if (root == nullptr)
    {
        cout << "树空，无法遍历" << endl;
        return;
    }
    sstack *top = Initstack();
    BTNode *p = root;
    BTNode *f = nullptr;
    while (p != nullptr || Empty(top)==0)
    {
        if(p!=nullptr){
            cout << p->data << " ";
            Push(top, p);
            p = p->l;
        }
        else{
            f = Pop(top);
            p = f->r;
        }
    }
    cout << endl;
}
//中序遍历
void InOrderBT(BTree root){
    if(root==nullptr){
        cout << "树空，无法遍历" << endl;
        return;
    }
    sstack *top = Initstack();
    BTNode *p = root;
    BTNode *f = nullptr;
    while(p!=nullptr || Empty(top)==0){
        if (p != nullptr){
            Push(top, p);
            p = p->l;
        }
        else{
            f = Pop(top);
            cout << f->data << " ";
            p = f->r;
        }
    }
    cout << endl;
}
//后序遍历
void PostOrderBT(BTree root){
    if(root==nullptr){
        cout << "树空，无法遍历" << endl;
        return;
    }
    sstack *top = Initstack();
    BTNode *p = root;
    BTNode *f = nullptr;
    BTNode *pre = nullptr;
    while (p != nullptr || Empty(top) == 0)
    {
        if(p!=nullptr){
            Push(top, p);
            p = p->l;
        }
        else{
            f = Get(top);
            if(f->r!=nullptr && pre!=f->r){
                p = f->r;
            }
            else{
                f = Pop(top);
                cout << f->data << " ";
                pre = f;
            }
        }
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

    // 插入
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
