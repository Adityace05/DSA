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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* t1 = l1->next;
//         ListNode* t2 = l2->next;
//         int sum = l1->val + l2->val;
//         ListNode* prev = new ListNode(sum % 10);
//         ListNode* head = prev;
//         int p = sum / 10;

//         while(t1 != NULL && t2 != NULL){
//             sum = t1->val + t2->val;
//             ListNode* Node = new ListNode((sum + p) % 10);
//             prev->next = Node;
//             prev = Node;
//             p = (sum + p) / 10;
//             t1 = t1->next;
//             t2 = t2->next;
//         }
//         while(t1 != NULL){
//             ListNode* Node = new ListNode((t1->val + p) % 10);
//             prev->next = Node;
//             prev = Node;
//             p = (t1->val + p) / 10;
//             t1 = t1->next;
//         }
//         while(t2 != NULL){
//             ListNode* Node = new ListNode((t2->val + p) % 10);
//             prev->next = Node;
//             prev = Node;
//             p = (t2->val + p)/ 10;
//             t2 = t2->next;
//         }
//         if(p != 0){
//             ListNode* Node = new ListNode(p);
//             prev->next = Node;
//             Node->next = NULL;
//         }else{
//             prev->next = NULL;
//         }
        
        
//         return head;
//     }
// };