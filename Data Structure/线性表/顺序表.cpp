#include<iostream>
using namespace std;
#define maxx 105

typedef struct ArrayList{
    // int data[maxx];// 存放顺序表的数据
    int *data;        // 声明一个数组，方便后续扩容
    int len;          // 表长
}Array;
//初始化，值传递
Array InitArray(Array a){
    a.data = new int[maxx];   
    // 空间申请失败判断
    // if(a.data==nullptr){
    //     cout << "空间申请失败" << endl;
    //     return a;
    // }
    a.len = 0;
    return a;
}
// 添加
void Add(Array *a,int k){
    //判满
    if(a->len == maxx){
        cout << "顺序表已满" << endl;
        return;
    }
    a->data[a->len] = k;
    a->len++;
}
// 插入
void Insert(Array *a,int i,int k){
    // 判满
    if (a->len == maxx)
    {
        cout << "顺序表已满" << endl;
        return;
    }
    a->len++;
    for (int j = a->len - 1; j > i;j--){
        a->data[j] = a->data[j - 1];
    }
    a->data[i] = k;
}
// 查找（某个值的下标）
int Find(Array *a, int k){
    for (int i = 0; i < a->len; i++){
        if(a->data[i]==k)
            return i;
    }
    return -1;
}
// 删除(删除某个值)
void Delete(Array *a, int k){
    // 判空
    // 空表一定找不到
    int i = Find(a, k);
    if(i==-1){
        cout << "该数据不存在" << endl;
        return;
    }
    for (int j = i; j < a->len - 1;j++)
    {
        a->data[j] = a->data[j + 1];
    }
    a->len--;
}
void Show(Array a){
    for (int i = 0; i < a.len;i++){
        cout << a.data[i] << " ";
    }
    cout << endl;
}
int main(){

    Array a;
    a = InitArray(a);
    int op;
    do{
        cout << "请输入操作" << endl;
        cout << "1.增加" << endl;
        cout << "2.删除" << endl;
        cout << "3.插入" << endl;
        cout << "4.展示" << endl;
        cout << "0.退出" << endl;
        cin >> op;
        if (op == 1)
        {
            int n;
            cout << "输入要插入的个数" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int m;
                cin >> m;
                Add(&a, m);
            }
        }
        else if(op==2){
            int n;
            cout << "输入要删除的值" << endl;
            cin >> n;
            Delete(&a, n);
        }
        else if (op == 3)
        {
            int n,m;
            cout << "输入要插入的位置和值" << endl;
            cin >> n >> m;
            Insert(&a, n, m);
        }
        else if(op==4){
            Show(a);
        }
        else{
            cout << "请输入正确的值" << endl;
        }

    } while (op);

    return 0;
}