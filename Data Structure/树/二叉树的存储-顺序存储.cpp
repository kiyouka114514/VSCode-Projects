#include <iostream>
using namespace std;
const int maxx = 1005;
char my_data[maxx];

int Find(char fx)
{
    for (int i = 1; i <= maxx; i++)
    {
        if (my_data[i] == fx)
            return i;
    }
}
// 找父亲
void FindFa(char x)
{
    int i = Find(x);
    if (i == 1)
        cout << "该结点是根结点" << endl;
    else
        cout << "该结点的父亲是" << my_data[i / 2] << endl;
}
// 找儿子
void FindSon(char x)
{
    int i = Find(x);
    if (my_data[i * 2] == ' ')
        cout << "该结点没有左孩子" << endl;
    else
        cout << "该结点的左孩子是" << my_data[i * 2] << endl;
    if (my_data[i * 2 + 1] == ' ')
        cout << "该结点没有右孩子" << endl;
    else
        cout << "该结点的右孩子是" << my_data[i * 2 + 1] << endl;
}
int main()
{

    // 初始化
    for (int i = 1; i < maxx; i++)
    {
        my_data[i] = ' ';
    }

    int n;
    cin >> n;
    char r;
    cin >> r;
    my_data[1] = r;

    char x, fx;
    int flag; // 0 为左孩子，1 为右孩子

    // 插入
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> fx >> flag;
        int j = Find(fx);
        if (flag == 0)
            my_data[j * 2] = x;
        else
            my_data[j * 2 + 1] = x;
    }

    // 开始查找
    char f;
    cout << "请输入要查找的节点：" << endl;
    cin >> f;
    FindSon(f);
    FindFa(f);

    return 0;
}
