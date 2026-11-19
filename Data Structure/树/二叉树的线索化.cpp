#include<iostream>
using namespace std;

typedef struct BTNode{
    char data;
    struct BTNode *l;
    struct BTNode *r;
    bool lflag, rflag; //false表示指向孩子，true表示线索
}BTNode,*BTree;

BTNode *pre = nullptr;

BTree InitBTree(char r)
{
    BTNode *s = new BTNode;
    s->data = r;
    s->l = nullptr;
    s->r = nullptr;
    s->lflag = s->rflag = false;
    return s;
}

BTNode *Find(BTree root, char x)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == x)
        return root;

    BTNode *ans = nullptr;
    if (root->l != nullptr && root->lflag==false)
    {
        ans = Find(root->l, x);
        if (ans != nullptr)
            return ans;
    }
    if (root->r != nullptr && root->rflag == false)
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
    s->lflag = s->rflag = false;


    BTNode *p = Find(root, fx);
    if (flag == 0)
        p->l = s;
    else
        p->r = s;
    return root;
}
void Visit(BTNode* p){
    if(p->l==nullptr){
        p->l = pre;
        p->lflag = true;
    }
    if(pre!=nullptr && pre->r==nullptr){
        pre->r = p;
        pre->rflag = true;
    }
    pre = p;
}
void InOrderBT(BTree root){
    if(root==nullptr)
        return;
    if(root->lflag==false)
        InOrderBT(root->l);
    Visit(root);
    if(root->rflag==false)
        InOrderBT(root->r);
}
//找前驱
void FindPre(BTree root,char x){
    BTNode *p = Find(root, x);
    BTNode *q = nullptr;
    if (p->l == nullptr)
        cout << "该结点没有前驱" << endl;
    else{
        if(p->lflag==true)
            cout << "该结点的前驱是" << p->l->data << endl;
        else{
            //根结点的前驱一定是左子树最靠右的结点
            q = p->l;
            while(q->r!=nullptr && q->rflag==false){
                q = q->r;
            }
            cout << "该结点的前驱是" << q->data << endl;
        }
    }
}
//找后继
void FindPost(BTree root,char x){
    BTNode *p = Find(root, x);
    BTNode *q = nullptr;
    if (p->r == nullptr)
        cout << "该结点没有后继" << endl;
    else{
        if (p->rflag == true)
            cout << "该结点的后继是" << p->r->data << endl;
        else{
            q = p->r;
            while(q->l!=nullptr && q->lflag==false){
                q = q->l;
            }
        }
        cout << "该结点的后继是" << q->data << endl;
    }
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
    for (int i = 1;  i < n; i++)
    {
        cin >> x >> fx >> flag;
        root = Insert(root, x, fx, flag);
    }

    InOrderBT(root);
    char f;
    cout << "请输入要查找的节点：" << endl;
    cin >> f;
    FindPre(root,f);
    FindPost(root, f);
    return 0;
}

