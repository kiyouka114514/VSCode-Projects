#include <iostream>
using namespace std;
#define size 15
#define nul -1
/*
    以下使用开放定址法：新地址 Hi=(H(key)+di)%m
    n个数据构造表长为m的散列表，保证n<m，且非负
    哈希函数：Hash(key)=key%13
    处理冲突方法：线性探测法
*/
// 哈希表结构体
typedef struct
{
    int *data;
    int m;      // 表长
} HashTable;
// 创建哈希表
HashTable CreateHashTable()
{
    // 初始化
    HashTable h;
    h.data = new int[size];
    h.m = size;
    // 初始化为空
    for (int i = 0; i < h.m;i++)
    {
        h.data[i] = nul;
    }
    return h;
}
// 哈希函数（初始位置）
int Hash(int k)
{
    return k % 13;
}
// 更新最终地址
int FinalAddress(HashTable *h,int k)
{
    int i = Hash(k);
    if(h->data[i]!=nul)
    {
        // 产生冲突
        int d = 1;
        int newi = (i + d) % h->m;      // 更新地址
        while(h->data[newi]!=nul)
        {
            d++;
            newi = (i + d) % h->m;
        }
        return newi;
    }
    return i;
}
// 插入
void Insert(HashTable *h,int k)
{
    // 保证n<m，无需判满
    int i = FinalAddress(h, k);
    h->data[i] = k;
}
// 哈希查找
void Search(HashTable h,int k)
{
    int i = Hash(k);
    if (h.data[i] == nul)
    {
        cout << "不存在" << endl;
    }
    else
    {
        int newi = i, d = 0;
        while (h.data[newi] != nul)
        {
            if(h.data[newi]==k)
            {
                cout << "该值位于" << newi << endl;
                return;
            }
            d++;
            newi = (i + d) % h.m;
        }
        cout << "不存在" << endl;
    }
}
int main()
{
    int n, k;
    // 创建哈希表
    HashTable h = CreateHashTable();
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> k;
        Insert(&h, k);
    }

    // 开始查找
    cout << "请输入要查找的值" << endl;
    cin >> k;
    Search(h, k);
    return 0;
}