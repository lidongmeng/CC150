/*************************************************************************
	> File Name: 2.1.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月28日 星期日 09时01分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

struct ListNode
{
    ListNode * next;
    int data;
};

ListNode * buildListFromArray(int * array, int n)
{
    ListNode dummy;
    ListNode * cur = &dummy;
    for (int i = 0; i < n; ++i)
    {
        ListNode * temp = new ListNode();
        temp->data = array[i];
        cur->next = temp;
        cur = cur->next;
    }
    return dummy.next;
}

void printList(ListNode * head)
{
    ListNode * temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// use extra O(n), O(n)
void removeDuplicatedFromList(ListNode * head)
{
    if (!head)
        return ;
    ListNode * p = head;
    ListNode * cur = head->next;
    map<int, bool> hash_map;
    hash_map[p->data] = 1;
    while (cur)
    {
        if (hash_map.count(cur->data))
        {
            cur = cur->next;   
            if (!cur)
                p->next = NULL;
        }
        else
        {
            hash_map[cur->data] = 1;
            p->next = cur;
            p = cur;
            cur = cur->next;
        }
    }

}

// use no extra but O(n2)
void removeDuplicatedFromListII(ListNode * head)
{
    if (!head)
        return ;
    ListNode * cur = head;
    ListNode * p;
    ListNode * q;
    while (cur)
    {
        int d = cur->data;
        q = cur;
        p = cur->next;
        while (p)
        {
            if (p->data == d)
            {
                p = p->next;
                if (!p)
                    q->next = NULL;
            }
            else
            {
               q->next = p;
               q = p;
               p = p->next;
            }
        }
        cur = cur->next;
    }
}

int main()
{
    int array[8] = {1,2,3,4,5,4,3,3};
    ListNode * head = buildListFromArray(array, 8);
    printList(head);
    removeDuplicatedFromList(head);
    printList(head);
   int arrayII[10] = {2,2,4,5,6,8,10,2,6,10};
    ListNode * h = buildListFromArray(arrayII, 10);
    printList(h);
    removeDuplicatedFromListII(h);
    printList(h);
    return 0;
}

