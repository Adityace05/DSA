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
//     ListNode *rotateRight(ListNode *head, int k)
//     {
//         if (head == NULL || head->next == NULL || k == 0)
//             return head;

//         int n = 1;
//         ListNode *temp = head;

//         while (temp->next != NULL)
//         {
//             n++;
//             temp = temp->next;
//         }

//         k = k % n;
//         if (k == 0)
//             return head;

//         temp->next = head;

//         int p = n - k;
//         ListNode *prev = head;
//         temp = head;

//         while (p > 0)
//         {
//             prev = temp;
//             temp = temp->next;
//             p--;
//         }

//         head = temp;
//         prev->next = NULL;

//         return head;
//     }
// };