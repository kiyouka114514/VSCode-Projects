#include <iostream>
using namespace std;

typedef struct AVLNode
{
    int data;
    struct AVLNode *l;
    struct AVLNode *r;
    int h; // 该结点的高度
} AVLNode, *AVLTree;

int maxx(int a, int b)
{
    return a > b ? a : b;
}

// 获取结点高度
int Get_h(AVLNode *x)
{
    if (x != nullptr)
        return x->h;
    else
        return 0;
}

// 失衡调整
// LL == 右旋
AVLTree LLrotation(AVLNode *x)
{
    AVLNode *y = x->l;
    // 右旋链接
    x->l = y->r; 
    y->r = x;    
    // 调整高度
    x->h = maxx(Get_h(x->l), Get_h(x->r)) + 1;
    y->h = maxx(Get_h(y->l), Get_h(y->r)) + 1;

    return y; // 返回调整之后的根结点
}
// RR == 左旋 
AVLTree RRrotation(AVLNode *x)
{
    AVLNode *y = x->r;
    // 左旋链接
    x->r = y->l; 
    y->l = x;    
    // 调整高度
    x->h = maxx(Get_h(x->l), Get_h(x->r)) + 1;
    y->h = maxx(Get_h(y->l), Get_h(y->r)) + 1;

    return y; // 返回调整之后的根结点
}
//LR
AVLTree LRrotation(AVLNode* x){
    //先左旋
    x->l = RRrotation(x->l);
    //再右旋
    x = LLrotation(x);
    return x;
}

// RL
AVLTree RLrotation(AVLNode *x)
{
    // 先右旋
    x->r = LLrotation(x->r);
    // 再左旋
    x = RRrotation(x);
    return x;
}

AVLNode *CreateBSTNode(int x)
{
    AVLNode *s = new AVLNode;
    s->data = x;
    s->l = s->r = nullptr;
    s->h = 1;
    return s;
}
//插入
AVLTree Insert(AVLTree root,int x){
    if (root == nullptr)
    {
        root = CreateBSTNode(x);
        return root;
    }
    if(x<root->data){
        root->l = Insert(root->l, x);
        //插入完成后，进行判断调整
        if(Get_h(root->l)-Get_h(root->r)>1){
            // LL LR
            AVLNode *left = root->l;
            if(x<left->data){
                root = LLrotation(root);
            }
            else{
                root = LRrotation(root);
            }
        }
    }
    else{
        root->r = Insert(root->r, x);
        // 插入完成后，进行判断调整
        if (Get_h(root->r) - Get_h(root->l) > 1)
        {
            // RR Rl
            AVLNode *right = root->r;
            if (x < right->data)
            {
                root = RLrotation(root);
            }
            else
            {
                root = RRrotation(root);
            }
        }
    }
    //更新高度
    root->h = maxx(Get_h(root->l), Get_h(root->r));
    return root;
}
//删除
AVLTree Del(AVLTree root,int x){
    if (root == nullptr)
    {
        cout << "空树或没有找到该结点，无法删除" << endl;
        return root;
    }
    if (x < root->data)
    {
        root->l = Del(root->l, x);
        //开始调整
        //删除左边 == 右边+1
        // RR / RL
        if(Get_h(root->r)-Get_h(root->l)>1){
            AVLNode *right = root->r;
            if(Get_h(right->r)>=Get_h(right->l)){
                //RR
                root = RRrotation(root);
            }
            else{
                //RL
                root = RLrotation(root);
            }
        }
    }
    else if (x > root->data)
    {
        root->r = Del(root->r, x);
        // 开始调整
        // 删除右边 == 左边+1
        //  LL / LR
        if (Get_h(root->l) - Get_h(root->r) > 1)
        {
            AVLNode *left = root->r;
            if (Get_h(left->l) >= Get_h(left->r))
            {
                // LL
                root = LLrotation(root);
            }
            else
            {
                // LR
                root = LRrotation(root);
            }
        }
    }
    else
    {
        if(root->l!=nullptr && root->r!=nullptr){
            // 度为2
            // 找root的中序遍历的后继
            AVLNode *y = root->r;
            while(y->l!=nullptr){
                y = y->l;
            }
            root->data = y->data;
            root->r = Del(root->r, y->data);
        }
        else{
            // 度为1或0
            AVLNode *p = root;
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
    // 更新高度
    if(root!=nullptr)
    root->h = maxx(Get_h(root->l), Get_h(root->r));
    return root; // 链接父结点
}
void InOrderBT(AVLTree root)
{
    if (root == NULL)
        return;
    InOrderBT(root->l);
    cout << root->data << " ";
    InOrderBT(root->r);
}
int main()
{
    int n, x;
    AVLTree root = nullptr;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        root = Insert(root, x);
    }

    InOrderBT(root);
    while(root!=nullptr){
        int d;
        cout << "请输入要删除的结点" << endl;
        cin >> d;
        root = Del(root, d);
        InOrderBT(root);
    }
    return 0;
}