
// You are given the head of a singly linked - list.The list can be represented as :

//     L0 → L1 → … → Ln -
//     1 → Ln
//         Reorder the list to be on the following form :

//     L0 → Ln → L1 → Ln -
//     1 → L2 → Ln - 2 → … You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// class Solution {
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == NULL || head->next == NULL)
//             return head;

//         ListNode *curr = head->next;
//         ListNode *prev = head;
//         ListNode *temp;

//         while (curr != NULL)
//         {
//             temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }

//         head->next = NULL;
//         return prev;
//     }

// public:
//     void reorderList(ListNode* head) {

//         if(head == NULL || head->next == NULL)
//             return;

//         ListNode *c2 = head;
//         ListNode *fast = head;
//         ListNode *prev = NULL;

//         while(fast != NULL && fast->next != NULL)
//         {
//             prev = c2;
//             c2 = c2->next;
//             fast = fast->next->next;
//         }

//         prev->next = NULL;

//         c2 = reverseList(c2);

//         ListNode *c1 = head;

//         while(c1 != NULL && c2 != NULL)
//         {
//             ListNode *t1 = c1->next;
//             ListNode *t2 = c2->next;

//             c1->next = c2;

//             if(t1 == NULL)
//                 break;

//             c2->next = t1;

//             c1 = t1;
//             c2 = t2;
//         }
//     }
// };