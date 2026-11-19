#include<iostream>
#include<cstring>     //strcpy头文件
using namespace std;

typedef struct Node{
    int w;     // 权值
    int f;     // 父亲的下标
    int l, r;  // 左右孩子的下标
} HuffmanNode;
// 找权值最小的根结点
void Find(HuffmanNode* tree,int x,int *s1,int *s2){
    //tree[0]~tree[x]中找权值最小的两个根结点
    //先找最小的
    int minn = 0; // 保存权值最小的根结点的下标

    for (int i = 0; i <= x;i++){
        if(tree[i].f==-1){
            minn = i;     //先找一个根结点
            break;
        }
    }
    for (int i = 0; i <= x;i++){
        if(tree[i].f==-1 && tree[i].w<tree[minn].w){
            minn = i;    // 更新最小结点坐标
        }
    }
    *s1 = minn;
    //再找第二小的
    for (int i = 0; i <= x; i++)
    {
        if (tree[i].f == -1 && i!=*s1)
        {
            minn = i; // 先找一个根结点
            break;
        }
    }
    for (int i = 0; i <= x; i++)
    {
        if (i!=*s1 && tree[i].f == -1 && tree[i].w < tree[minn].w)
        {
            minn = i; // 更新最小结点坐标
        }
    }
    *s2 = minn;
}
// 构造哈夫曼树
HuffmanNode* CreateHuffmanTree(int w[],int n)
{
    //以n个结点为叶子结点构造哈夫曼树
    int m = 2 * n - 1; //哈夫曼树的总结点数
    HuffmanNode *tree = new HuffmanNode[m];
    //tree[0]~tree[n-1] 保存叶子结点
    for (int i = 0; i <= n-1; i++){
        tree[i].w = w[i];
        tree[i].l = tree[i].r = -1;
        tree[i].f = -1;
    }
    int s1, s2;// 权值最小的两个根结点的下标
    // 合并，循环n-1次，每次合并两棵树，添加一个新的根结点
    // n~m-1 为度为2的结点的下标
    for (int i = n; i <= m-1; i++){
        Find(tree, i - 1, &s1, &s2);    // 新结点也要参与合并
        //开始合并
        tree[i].f = -1;  //新的根结点
        tree[i].l = s1;
        tree[i].r = s2;
        tree[i].w = tree[s1].w + tree[s2].w;  //权值相加
        tree[s1].f = tree[s2].f = i;         //更新父结点
    }
    return tree;

}
//编码
char** Createcode(HuffmanNode* tree,int n){
    //编码过程中，临时存放编码的一维数组
    char *t = new char[n];
    //二维指针模拟开二维数组，保存n个编码
    char **codes = new char *[n];
    for (int i = 0; i < n;i++){
        codes[i] = nullptr;
    }
    int start;
    int p = 0, pre = 0;
    for (int i = 0; i <= n-1; i++)
    {
        start = n - 1;
        t[start] = '\0';

        p = i;
        pre = tree[p].f;

        while(pre!=-1){
            start--;
            if(tree[pre].l==p){
                t[start] = '1';
            }
            else{
                t[start] = '0';
            }
            p = pre;
            pre = tree[p].f;//向上走
        }

        codes[i] = new char[n - start];
        strcpy(codes[i], &t[start]);    //自动从start位置 到 \0
    }
    return codes;
}
int main(){

    int n;  //对n个字符进行编码
    char a[105];  //保存字符
    int w[105];   //权值
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n;i++){
        scanf("%c", &a[i]);
    }
    for (int i = 0; i < n;i++){
        scanf("%d", &w[i]);
    }
    HuffmanNode *Tree = CreateHuffmanTree(w, n);
    char **codes = Createcode(Tree, n);

    for (int i = 0; i <= n - 1;i++){
        cout << a[i] << ": " << codes[i] << endl;
    }
    return 0;
}