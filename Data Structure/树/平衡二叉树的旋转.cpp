#include<iostream>
using namespace std;

typedef struct AVLNode{
    int data;
    struct AVLNode *l;
    struct AVLNode *r;
    int h;   //该结点的高度
} AVLNode, *AVLTree;

int maxx(int a,int b){
    return a > b ? a : b;
}

//获取结点高度
int Get_h(AVLNode* x){
    if(x!=nullptr)
        return x->h;
    else
        return 0;
}

//右旋
AVLTree Right(AVLNode *x)
{
    AVLNode *y = x->l;
    //右旋链接
    x->l = y->r;   //1
    y->r = x;      //2
    //调整高度
    x->h = maxx(Get_h(x->l), Get_h(x->r)) + 1;
    y->h = maxx(Get_h(y->l), Get_h(y->r)) + 1;

    return y;   //返回调整之后的根结点
}
//左旋
AVLTree Left(AVLNode* x){
    AVLNode *y = x->r;
    //左旋链接
    x->r = y->l;    //1
    y->l = x;       //2
    //调整高度
    x->h = maxx(Get_h(x->l), Get_h(x->r)) + 1;
    y->h = maxx(Get_h(y->l), Get_h(y->r)) + 1;

    return y; // 返回调整之后的根结点
}


