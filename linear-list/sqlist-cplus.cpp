#include <iostream>
#include <malloc.h>
using namespace std;

#define MaxSize 50 // 顺序线性表的长度

typedef int ElemType; // 自定义类型，假设 ElemType 为 int 类型

typedef struct
{
    ElemType data[MaxSize]; // 存放顺序线性表中元素
    int length;             // 存放顺序线性表的长度
} SqList;                   // 顺序线性表的类型定义

/* 创建顺序线性表 */
void CreateList(SqList *&L, ElemType a[], int n) // 由 a 中的 n 个元素建立顺序线性表
{
    int i;
    L = (SqList *)malloc(sizeof(SqList)); // 分配存放顺序线性表的空间
    for (i = 0; i < n; i++)               // 放置数据元素
        L->data[i] = a[i];
    L->length = n; // 设置长度
}

/* 初始化顺序线性表 */
void InitList(SqList *&L)
{
    L = new SqList; // 分配存放顺序线性表的空间
    L->length = 0;  // 置空顺序线性表长度为 0
}

/* 销毁顺序线性表 */
void DestroyList(SqList *&L)
{
    free(L); // 释放顺序线性表 L 占用的内存空间
}

/* 判断顺序线性表是否为空表 */
bool ListEmpty(SqList *L)
{
    return (L->length == 0); // 如果 L 为空表，则返回 true，否则返回 false
}

/* 求顺序线性表长度 */
int ListLength(SqList *L)
{
    return (L->length); // 返回 length 域的值
}

/* 输出顺序线性表 */
void DispList(SqList *L)
{
    int i;
    for (i = 0; i < L->length; i++) // 扫描顺序线性表输出各元素值
        cout << L->data[i] << " ";
    cout << "\n";
}

/* 求顺序线性表中某个数据元素值 */
bool GetElem(SqList *L, int i, ElemType &e)
{
    if (i < 1 || i > L->length) // 参数错误时返回 false
        return false;
    e = L->data[i - 1]; // 取元素值
    return true;        // 成功找到元素时返回 true
}

/* 按元素值查找 */
int LocateElem(SqList *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e) // 循环查找元素 e
        i++;
    if (i > L->length) // 未查找到时返回 0
        return 0;
    else
        return i + 1; // 找到后返回其逻辑序号
}

/* 插入数据元素 */
bool ListInsert(SqList *&L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return false;               // 参数错误时返回 false
    i--;                            // 将顺序线性表逻辑序号转化为物理序号
    for (j = L->length; j > i; j--) // 将 data[i] 及后面元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e; // 插入元素 e
    L->length++;    // 顺序线性表长度 加1
    return true;    // 成功插入返回 true
}

/* 删除数据元素 */
bool ListDelete(SqList *&L, int i, ElemType &e)
{
    int j;
    if (i < 1 || i > L->length) // 参数错误时返回 false
        return false;
    i--; // 将逻辑序号转化为物理序号
    e = L->data[i];
    for (j = i; j < L->length; j++) // 将 data[i] 之后的元素前移一个位置
        L->data[j] = L->data[j + 1];
    L->length--; // 顺序线性表长度 减1
    return true; // 成功删除返回 true
}

int main()
{
    SqList *L;
    ElemType e;
    InitList(L); // 初始化顺序线性表
    int i;
    for (i = 1; i <= 5; i++) // 依次插入 5 个元素
        ListInsert(L, i, i);
    cout << "ListLength(L) = " << ListLength(L) << endl; // 顺序线性表长度
    cout << "ListEmpty(L) = " << ListEmpty(L) << endl;   // 判断是否为空表
    GetElem(L, 3, e);                                    // 获取第3个元素值
    cout << "e = " << e << endl;
    cout << "LocateElem(L, 1) = " << LocateElem(L, 1) << endl; // 查找是否存在元素值1
    ListInsert(L, 4, 5);                                       // 在第4个位置插入5
    DispList(L);                                               // 输出顺序线性表 L 各元素值
    ListDelete(L, 3, e);                                       // 删除第3个元素值
    DispList(L);                                               // 输出顺序线性表 L 各元素值
    DestroyList(L);                                            // 销毁顺序线性表 L 所占用内存空间
    return 0;
}
