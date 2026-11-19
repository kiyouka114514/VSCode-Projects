#include <iostream>
using namespace std;

typedef struct BSTNode
{
    int data;
    struct BSTNode *l;
    struct BSTNode *r;

} BSTNode, *BSTree;
BSTNode *CreateBSTNode(int x)
{
    BSTNode *s = new BSTNode;
    s->data = x;
    s->l = s->r = nullptr;
    return s;
}
// 查找x----非递归
BSTNode *Search1(BSTree root, int x)
{

    BSTNode *p = root;
    while (p != nullptr && p->data == x)
    {
        if (x < p->data)
            p = p->l;
        else
            p = p->r;
    }
    return p;
}
// 查找x----递归
BSTNode *Search2(BSTree root, int x)
{

    if (root == nullptr || root->data == x)
        return root;
    if (x < root->data)
        return Search2(root->l, x);
    else
        return Search2(root->r, x);
}
// 插入----非递归
BSTree Insert1(BSTree root, int x)
{
    if (root == nullptr)
    {
        root = CreateBSTNode(x);
        return root;
    }
    BSTNode *p = root;
    BSTNode *pre = nullptr;

    BSTNode *s = CreateBSTNode(x);

    while (p != nullptr)
    {
        pre = p;
        if (x < p->data)
            p = p->l;
        else
            p = p->r;
    }
    if (s->data < pre->data)
        pre->l = s;
    else
        pre->r = s;

    return root;
}
// 插入----递归
BSTree Insert2(BSTree root, int x)
{
    if (root == nullptr)
    {
        root = CreateBSTNode(x);
        return root;
    }

    if (x < root->data)
        root->l = Insert2(root->l, x);
    else
        root->r = Insert2(root->r, x);

    return root;
}
//删除----非递归
BSTree Delete1(BSTree root,int x){

    if(root==nullptr){
        cout << "空树，无法删除" << endl;
        return root;
    }
    BSTNode *p = root;
    BSTNode *pre = nullptr;
    while(p!=nullptr && p->data!=x){
        pre = p;
        if(x<p->data)
            p = p->l;
        else
            p = p->r;
    }
    if(p==nullptr){
        cout << "该数据不存在" << endl;
        return root;
    }
    //度为2
    if (p->l != nullptr && p->r!=nullptr){
        BSTNode *y = p->l;
        BSTNode *fy = p;
        while(y->r!=nullptr){

            fy = y;
            y = y->r;
        }
        p->data = y->data;
        p = y;
        pre = fy;
    }
    //度为2 转换为 度为1或0
    //度为1或0
    BSTNode *ch = nullptr;
    if(p->l!=nullptr)
        ch = p->l;
    else
        ch = p->r;
    if(pre==nullptr){
        root = ch;
    }
    else{
        if(pre->l==p)
            pre->l = ch;
        else
            pre->r = ch;
    }
    delete p;
    p = nullptr;//别忘记置空
    
    return root;
} 
//删除----递归
BSTree Delete2(BSTree root,int x){
    if (root == nullptr)
    {
        cout << "空树或没有找到该结点，无法删除" << endl;
        return root;
    }
    if (x < root->data)
    {
        root->l = Delete2(root->l, x);
    }
    else if (x > root->data)
    {
        root->r = Delete2(root->r, x);
    }
    else
    {
       if(root->l!=nullptr && root->r!=nullptr){
           // 度为2
           // 找root的中序遍历的后继
           BSTNode *y = root->r;
           while (y->l != nullptr)
           {
               y = y->l;
           }
           root->data = y->data;
           root->r = Delete2(root->r, y->data);
       }
       else{
            //度为1或0
            BSTNode *p = root;
            if(root->l!=nullptr){
                root = root->l;
            }
            else{
                root = root->r;
            }
            delete p;
            p = nullptr;
       }
    }
    return root; //链接父结点
}
// 中序遍历
void InOrderBT(BSTree root)
{
    if (root == nullptr)
        return;
    InOrderBT(root->l);
    cout << root->data << " ";
    InOrderBT(root->r);
}
int main()
{
    int n, x;
    BSTree root = nullptr;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        root = Insert2(root, x);
    }

    return 0;
}