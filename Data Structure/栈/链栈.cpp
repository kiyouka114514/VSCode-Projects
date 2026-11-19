#include <iostream>
using namespace std;

// 结点结构
typedef struct StackNode{
    int data;
    struct StackNode *next;
} SNode, *Stack;
// 初始化
Stack InitStack(){
    Stack s = new SNode;
    s->next = nullptr;
    return s;
}
// 入栈
void Push(Stack s, int x){
    // 判满

    SNode *n = new SNode;
    n->data = x;
    n->next = s->next;
    s->next = n;
}
// 判空
int IsEmpty(Stack s){
    if(s->next==nullptr){
        return 1;
    }
    return 0;
}
// 获取栈顶数据
void GetTop(Stack s){
    if(IsEmpty(s)==1){
        cout << "栈空" << endl;
        return;
    }
    else
    {
        cout << "栈顶为" << s->next->data << endl;
    }
}
// 出栈
void Pop(Stack s){
    if (IsEmpty(s) == 1)
    {
        cout << "栈空" << endl;
        return;
    }
    SNode *p = s->next;
    s->next = p->next;
    delete p;
    p = nullptr;
}
int main()
{
    Stack s;
    s = InitStack();
    int op;
    do
    {
        cout << "请输入操作" << endl;
        cout << "1.入栈" << endl;
        cout << "2.出栈" << endl;
        cout << "3.获取栈顶数据" << endl;
        cout << "0.退出" << endl;
        cin >> op;
        if (op == 1)
        {
            int n;
            cout << "输入要入栈的个数和数据" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int m;
                cin >> m;
                Push(s, m);
            }
        }
        else if (op == 2)
        {
            Pop(s);
        }
        else if (op == 3)
        {
            GetTop(s);
        }
        else
        {
            cout << "请输入正确的值" << endl;
        }

    } while (op);

    return 0;
}