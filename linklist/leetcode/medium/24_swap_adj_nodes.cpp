// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution
// {
// public:
//     ListNode *swapPairs(ListNode *head)
//     {
//         if (head == NULL)
//             return NULL;
//         if (head->next == NULL)
//             return head;
//         ListNode *t1 = head;
//         ListNode *t2 = head->next;
//         ListNode *prev = NULL;

//         while (t2 != NULL)
//         {
//             if (prev)
//             {
//                 prev->next = t2;
//             }
//             else
//             {
//                 head = t2;
//             }
//             t1->next = t2->next;
//             t2->next = t1;
//             prev = t1;
//             t1 = t1->next;
//             if (t1)
//                 t2 = t1->next;
//             else
//                 t2 = NULL;
//         }

//         return head;
//     }
// };