// class Solution
// {
// public:
//     int longestPalindromeSubseq(string s)
//     {
//         int n = s.size();
//         string p = s;
//         reverse(p.begin(), p.end());
//         vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (s[i - 1] == p[j - 1])
//                 {
//                     t[i][j] = 1 + t[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     t[i][j] = max(t[i][j - 1], t[i - 1][j]);
//                 }
//             }
//         }

//         return t[n][n];
//     }
// };