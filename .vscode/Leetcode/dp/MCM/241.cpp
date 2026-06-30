// class Solution
// {
// public:
//     vector<int> solve(string expression, int i, int j)
//     {

//         vector<int> ans;
//         bool isNumber = true;

//         for (int k = i; k <= j; k++)
//         {
//             if (expression[k] == '+' || expression[k] == '-' || expression[k] == '*')
//             {
//                 isNumber = false;
//                 break;
//             }
//         }

//         if (isNumber)
//         {
//             ans.push_back(stoi(expression.substr(i, j - i + 1)));
//             return ans;
//         }

//         for (int k = i; k <= j; k++)
//         {
//             if (expression[k] == '+' || expression[k] == '-' || expression[k] == '*')
//             {
//                 vector<int> left = solve(expression, i, k - 1);
//                 vector<int> right = solve(expression, k + 1, j);

//                 for (int l : left)
//                 {
//                     for (int r : right)
//                     {
//                         if (expression[k] == '+')
//                         {
//                             ans.push_back(l + r);
//                         }
//                         else if (expression[k] == '-')
//                         {
//                             ans.push_back(l - r);
//                         }
//                         else if (expression[k] == '*')
//                         {
//                             ans.push_back(l * r);
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
//     vector<int> diffWaysToCompute(string expression)
//     {
//         return solve(expression, 0, expression.size() - 1);
//     }
// };