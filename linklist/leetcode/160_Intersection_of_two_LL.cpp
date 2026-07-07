// #Intuition
// <!--Describe your first thoughts on how to solve this problem.-->

// #Approach
//     <!--Describe your approach to solving the problem.-->

// #Complexity
//     - Time complexity : <!--Add your time complexity here, e.g.$$O(n) $$-->

//                         -
//                         Space complexity : <!--Add your space complexity here, e.g.$$O(n) $$-->

// #Code
// ```cpp[]
//                                            /**
//                                             * Definition for singly-linked list.
//                                             * struct ListNode {
//                                             *     int val;
//                                             *     ListNode *next;
//                                             *     ListNode(int x) : val(x), next(NULL) {}
//                                             * };
//                                             */
//                                            class Solution
// {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         unordered_set<ListNode *> s;
//         ListNode *tempA = headA;
//         ListNode *tempB = headB;

//         while (tempA != NULL)
//         {
//             s.insert(tempA);
//             tempA = tempA->next;
//         }
//         while (tempB != NULL)
//         {
//             if (s.find(tempB) != s.end())
//             {
//                 return tempB;
//             }
//             tempB = tempB->next;
//         }

//         return NULL;
//     }
// };
// ```