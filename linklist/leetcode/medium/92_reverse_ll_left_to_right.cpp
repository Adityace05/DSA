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
//     ListNode *reverseBetween(ListNode *head, int left, int right)
//     {
//         if (head == NULL || left == right)
//             return head;

//         ListNode *start = head;
//         vector<int> store;

//         int i = 1;
//         while (i < left)
//         {
//             start = start->next;
//             i++;
//         }

//         ListNode *temp = start;

//         while (i <= right)
//         {
//             store.push_back(temp->val);
//             temp = temp->next;
//             i++;
//         }

//         for (int j = store.size() - 1; j >= 0; j--)
//         {
//             start->val = store[j];
//             start = start->next;
//         }

//         return head;
//     }
// };