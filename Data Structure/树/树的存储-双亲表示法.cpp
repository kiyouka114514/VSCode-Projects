#include <iostream>
using namespace std;
const int maxx = 100;

struct Node
{
    char data;
    int fa;
} t[maxx];

int len;
// 查找下标
int Find(char fx)
{
    for (int i = 0; i <= len - 1; i++)
    {
        if (t[i].data == fx)
            return i;
    }
}
// 插入节点
void Insert(char x, char fx)
{

    if (len == maxx)
    {
        cout << "数据已满" << endl;
        return;
    }
    t[len].data = x;
    t[len].fa = Find(fx);
    len++;
}
// 找儿子
void FindSon(char x)
{
    int flag = 0;
    cout << "该节点的孩子为：" << endl;
    for (int i = 0; i <= len - 1; i++)
    {

        if (t[i].fa == Find(x))
        {
            cout << t[i].data << " ";
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "该节点没有孩子" << endl;
    cout << endl;
}
// 找父亲
void FindFa(char x)
{
    int i = Find(x);
    if (i == -1)
        cout << "这个是根节点" << endl;
    else
        cout << "该数据的父亲节点是" << t[t[i].fa].data << endl;
}

int main()
{

    int n;
    cin >> n;
    char r;
    cin >> r;
    t[0].data = r;
    t[0].fa = -1;
    len++;

    char x, fx;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> fx;
        Insert(x, fx);
    }

    // 开始查找
    char f;
    cout << "请输入要查找的节点：" << endl;
    cin >> f;
    FindSon(f);
    FindFa(f);
    return 0;
}
