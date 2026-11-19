#include <iostream>
using namespace std;

typedef struct BSTNode
{
    int data;
    struct BSTNode *l;
    struct BSTNode *r;

} BSTNode, *BSTree;
BSTNode* CreateBSTNode(int x){
    BSTNode *s = new BSTNode;
    s->data = x;
    s->l = s->r = nullptr;
    return s;
}
//查找x----非递归
BSTNode* Search1(BSTree root,int x){

    BSTNode *p = root;
    while(p!=nullptr && p->data==x){
        if(x<p->data)
            p = p->l;
        else
            p = p->r;
    }
    return p;
}
//查找x----递归
BSTNode* Search2(BSTree root,int x){

    if(root==nullptr || root->data==x)
        return root;
    if(x<root->data)
        return Search2(root->l,x);
    else
        return Search2(root->r, x);
}
//插入----非递归
BSTree Insert1(BSTree root, int x)
{
    if(root==nullptr){
        root = CreateBSTNode(x);
        return root;
    }
    BSTNode *p = root;
    BSTNode *pre = nullptr;

    BSTNode *s = CreateBSTNode(x);

    while(p!=nullptr){
        pre = p;
        if(x<p->data)
            p = p->l;
        else
            p = p->r;
    }
    if(s->data<pre->data)
        pre->l = s;
    else
        pre->r = s;

    return root;
}
//插入----递归
BSTree Insert2(BSTree root,int x){
    if (root == nullptr)
    {
        root = CreateBSTNode(x);
        return root;
    }

    if(x<root->data)
        root->l=Insert2(root->l, x);
    else
        root->r=Insert2(root->r, x);

    return root;
}
// 中序遍历
void InOrderBT(BSTree root)
{
    if (root == NULL)
        return;
    InOrderBT(root->l);
    cout << root->data << " ";
    InOrderBT(root->r);
}
int main(){
    int n, x;
    BSTree root = nullptr;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x;
        root = Insert2(root, x);
    }

    InOrderBT(root);
    int f;
    cout << "请输入要查找的数" << endl;
    cin >> f;
    if(Search1(root,f))
        cout << "存在" << endl;
    else
        cout << "不存在" << endl;
    return 0;
}