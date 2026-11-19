#include<iostream>
using namespace std;
#define maxx 100
// 结构体数组结构
typedef struct {
    int *data;
    int top;    // 栈顶“指针”
} Stack;

// 初始化
Stack InitStack(Stack s){
    s.data = new int[maxx];
    s.top = -1;
    return s;
}

// 栈不可以遍历，不存在查找和展示操作

void Push(Stack *s,int x){
    // 判满
    if(s->top==maxx-1){
        cout << "栈已满" << endl;
    }
    else{
        s->data[++s->top] = x;
    }
}
// 判空
int IsEmpty(Stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
// 获取栈顶数据
void GetTop(Stack s){
    if (IsEmpty(&s) == 1)
    {
        cout << "栈空" << endl;
        return;
    }
    else{
        cout << "栈顶为" << s.data[s.top] << endl;
    }
}
// 出栈
void Pop(Stack *s){
    if(IsEmpty(s)==1){
        cout << "栈空" << endl;
    }
    else{
        s->top--;
    }
}

int main()
{
    Stack s;
    s = InitStack(s);
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
                Push(&s, m);
            }
        }
        else if (op == 2)
        {
            Pop(&s);
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