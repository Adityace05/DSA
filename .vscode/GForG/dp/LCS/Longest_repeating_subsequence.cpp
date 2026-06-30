// class Solution
// {
// public:
//     int LongestRepeatingSubsequence(string &s)
//     {
//         int n = s.size();
//         string b = s;
//         vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (s[i - 1] == b[j - 1] && i != j)
//                 {
//                     t[i][j] = 1 + t[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     t[i][j] = max(t[i][j - 1], t[i - 1][j]);
//                 }
//             }    
//         }

//         return t[n][n - 1];
//     }
// };