#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stddef.h>
using namespace std;

typedef struct node
{
    string no, name;
    double price;
    struct node *next;
} LNode, *LinkList;

int InitList(LinkList &LKlist)
{
    LKlist = new LNode;
    LKlist->next = NULL;
    return 1;
}

void Input(LinkList &LKlist)
{
    LinkList head, ptr;
    string no, name;
    double price;
    int flag = 1;
    int n;
    cin >> n;
    head = LKlist;
    for (int i = 0; i < n; ++i)
    {
        cin >> no >> name >> price;
        ptr = new LNode;
        ptr->no = no;
        ptr->name = name;
        ptr->price = price;
        ptr->next = NULL;
        LKlist->next = ptr;
        LKlist = ptr;
    }
    LKlist = head;
}

void out_expensive(LinkList &LKlist)
{
    LinkList head, pre, p, tmp,head2;
    head = LKlist;
    pre = LKlist;
    p = LKlist->next;
    while (p)
    {
        pre = p;
        while (pre->next)
        {
            if (pre->next->price < p->price)
            {
                tmp = pre->next;
                pre->next = tmp->next;
                free(tmp);
            }
            else
            {
                pre = pre->next;
            }
        }
        p = p->next;
    }

    LKlist = head;
    if (LKlist->price < LKlist->next->price)
    {
        LKlist = LKlist->next;
        free(LKlist);
    }
}

void Output(LinkList &LKlist)
{
    LinkList ptr;
    ptr = LKlist;
    int count = 0;
    while (LKlist->next)
    {
        LKlist = LKlist->next;
        count++;
    }
    cout << count << endl;
    LKlist = ptr;
    while (LKlist->next)
    {
        cout << LKlist->next->no << " " << LKlist->next->name;
        printf(" %.2f\n", LKlist->next->price);
        LKlist = LKlist->next;
    }
    LKlist = ptr;
}

int main()
{
    LinkList LKlist, head, ptr;
    InitList(LKlist); //初始化创建
    Input(LKlist);

    out_expensive(LKlist);

    Output(LKlist);

    return 0;
}
//链表