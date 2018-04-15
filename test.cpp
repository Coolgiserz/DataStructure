#include<iostream>
using namespace std;
#define  max    100
typedef  int ElemType;
typedef struct OLNode{
    int row, col;
    union
    {
        struct OLNode *next;	//表头结点使用next域
        ElemType e;				//表中元素结点使用e域
    }uval;
    struct OLNode *down, *right;
}OLNode,*OLink;
OLink CreateCrossList() {		//建立十字链表
    int m, n, t,row,col,e, maxmn;
    OLink h[max],p,q;
    cout << "请输入行数、列数以及非零元素的个数" << endl;
    cin >> m >> n >> t;
    if (m > n) maxmn = m;
    else maxmn = n;
    OLink head = (OLNode*)malloc(sizeof(OLNode));
    head->row = m;
    head->col = n;
    h[maxmn] = head;		//h[maxmn+1]为一组指示行列表头结点的指针
    for (int i = 0; i < maxmn;i++) {	//建立表头结点的循环链表
        p= (OLNode*)malloc(sizeof(OLNode));
        p->row = 0; p->col = 0;
        p->down = p; p->right = p;
        h[i] = p;
        if (i == 0) head->uval.next = p;
        else h[i - 1]->uval.next = p;
    }
    p->uval.next = head;		//最后一个结点指向表头结点*head
    for (int num = 1; num <= t;num++) {
        cout << "请输入一个非零元素的三元组" << endl;
        cin >> row >> col >> e;
        p= (OLNode*)malloc(sizeof(OLNode));  //生成结点
        p->row = row;
        p->col = col;
        p->uval.e = e;
        q = h[row];
        while (q->right!=h[row] && q->right->col<col) {	//查*p在第row行的插入位置
            q = q->right;
        }
        p->right = q->right; q->right = p;  //将*p插入到第row行的循环链表中
        q = h[col];
        while (q->down != h[col] && q->down->row < row) {//查*p在第col列的插入位置

            q = q->down;
        }
        p->down = q->down; q->down = p;  //将*p插入到第col列的循环链表中
    }
    return head;
}
void print(OLink head) {
    OLink p = head->uval.next;
    int m = 0,n = 0;
    while (m != head->row) {
        p = p->right;
        while (n != head->col) {
//            cout<<endl;
            if (m == p->row && n == p->col && p->uval.next!=NULL) {
                cout << p->uval.e << " ";
                p = p->right;
            }
            else {
                cout << "0 ";
            }
            n++;
        }
        n = 0;
        m++;
        p = p->uval.next;
        cout << endl;
    }
}
int main() {
    OLink list;
    list = CreateCrossList();
    cout << "链表内容为:" << endl;
    print(list);
}