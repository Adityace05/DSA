// class Solution
// {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode *root)
//     {

//         if (root == NULL)
//             return {};

//         vector<vector<int>> ans;
//         vector<int> temp;

//         queue<TreeNode *> q;
//         q.push(root);
//         q.push(NULL);

//         bool reverseLevel = false;

//         while (!q.empty())
//         {

//             TreeNode *curr = q.front();
//             q.pop();

//             if (curr == NULL)
//             {

//                 if (reverseLevel)
//                     reverse(temp.begin(), temp.end());

//                 ans.push_back(temp);
//                 temp.clear();

//                 reverseLevel = !reverseLevel;

//                 if (!q.empty())
//                     q.push(NULL);

//                 continue;
//             }

//             temp.push_back(curr->val);

//             if (curr->left)
//                 q.push(curr->left);

//             if (curr->right)
//                 q.push(curr->right);
//         }

//         return ans;
//     }
// };