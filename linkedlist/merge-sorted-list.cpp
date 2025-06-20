#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private: 
    struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        // while(list1||list2)
        // {
        //     int l1Val = (list1)?list1->val:INT_MIN;
        //     int l2Val = (list2)?list2->val:INT_MIN;

        //     if(l1Val <= l2Val && l1Val != INT_MIN)
        //     {
        //         ListNode* newNode = new ListNode(l1Val);
        //         curr->next = newNode;
        //         curr = newNode;
        //         if(list1) list1 = list1->next;
        //     }
        //     else if(l2Val < l1Val && l2Val != INT_MIN)
        //     {
        //     ListNode* newNode = new ListNode(l2Val);
        //     curr->next = newNode;
        //     curr = newNode;
        //     if(list2) list2 = list2->next;
        //     }
        //     else if(list1 && !list2)
        //     {
        //         ListNode* newNode = new ListNode(l1Val);
        //         curr->next = newNode;
        //         curr = newNode;
        //         if(list1) list1 = list1->next;
        //     }
        //     else if(list2 && !list1)
        //     {
        //         ListNode* newNode = new ListNode(l2Val);
        //         curr->next = newNode;
        //         curr = newNode;
        //         if(list2) list2 = list2->next;
        //     }
        // }

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1? list1:list2; 
        return res->next;
    }
};