// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         int n = nums.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//         }

//         if (sum % 2 != 0)
//         {
//             return false;
//         }

//         int w = sum / 2;
//         vector<vector<bool>> t(n + 1, vector<bool>(w + 1));

//         for (int j = 0; j < (w + 1); j++)
//         {
//             t[0][j] = false;
//         }
//         for (int i = 0; i < (n + 1); i++)
//         {
//             t[i][0] = true;
//         }

//         for (int i = 1; i < (n + 1); i++)
//         {
//             for (int j = 1; j < (w + 1); j++)
//             {
//                 if (nums[i - 1] <= j)
//                 {
//                     t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
//                 }
//                 else
//                 {
//                     t[i][j] = t[i - 1][j];
//                 }
//             }
//         }
//         return t[n][w];
//     }
// };