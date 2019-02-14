/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //问题：长度不等时，进位之后还有进位
 //
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class List
{
    ListNode* head;
    ListNode* tail;
    int length;

public:
    List()
    {
        length = 0;
        head = 0;
        tail = 0;
    }

    ListNode* getHead()
    {
        return head;
    }


    void add(int x)
    {
        if(length == 0) 
        {
            head = new ListNode(x);
            tail = head;
            length++;
        }
        else
        {
            tail->next = new ListNode(x);
            tail = tail->next;
            length++;
        }
    }
};

class Solution {
public:
    ListNode* head;
    ListNode* tail;
    int length;

    Solution()
    {
        length = 0;
        head = NULL;
        tail = NULL;
    }

    void showSolution()
    {
        ListNode* p = head;
        while(p)
        {
            cout<<p->val<<" "<<endl;
            p = p->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                
        ListNode* p1=l1;
        ListNode* p2=l2;

        int jw = 0;
        int ys = 0;
        int state;
        while(p1 || p2)
        {
            int a,b,c;
            if(p1 == NULL)
            {
                a = 0;
                b = p2->val;
                state = 1;
            }
            else if(p2 == NULL)
            {
                a = p1->val;
                b = 0;
                state = 2;
            }
            else
            {
                a = p1->val;
                b = p2->val;
                state = 3;
            }
            c = a+b+jw;
            if(c>9)
            {
                jw = 1;
                ys = c%10;
            }
            else
            {
                jw = 0;
                ys = c;
            }
            ListNode* p3=new ListNode(ys);
            if(length == 0)
            {
                head = p3;
                tail = p3;
                length++;
            }
            else
            {
                tail->next = p3;
                tail = p3;
                length++;
            }

            switch(state)
            {
                case 1:
                    p1 = 0;
                    p2 = p2->next;
                    break;
                case 2:
                    p1 = p1->next;
                    p2 = 0;
                    break;
                case 3:
                    p1 = p1->next;
                    p2 = p2->next;
                    break;
                default:
                    break;
            }
        }

        if(jw!=0)
        {
            tail->next = new ListNode(jw);
            tail = tail->next;
        }
        return head;
    }
};

int main()
{
    List l1,l2;
    cout<<"List 1:"<<endl;
    int a = 0;
        
    while(1)
    {
        cin>>a;
        if(a>10)
            break;
        else
            l1.add(a);

    }
    cout<<"list 2:"<<endl;
    while(1)
    {
        cin>>a;
        if(a>10)
            break;
        else
            l2.add(a);
    }

    Solution solution;
    solution.addTwoNumbers(l1.getHead(),l2.getHead());
    solution.showSolution();
}
