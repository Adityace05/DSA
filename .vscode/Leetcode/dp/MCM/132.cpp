// class Solution
// {
// public:
//     bool isPalindrome(string s, int i, int j)
//     {
//         while (i < j)
//         {
//             if (s[i] != s[j])
//             {
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int static t[1001][1001];

//     int solve(string s, int i, int j)
//     {
//         if (t[i][j] != -1)
//         {
//             return t[i][j];
//         }
//         if (i >= j)
//         {
//             return t[i][j] = 0;
//         }
//         if (isPalindrome(s, i, j))
//         {
//             return t[i][j] = 0;
//         }
//         int mn = INT_MAX;

//         for (int k = i; k < j; k++)
//         {
//             int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);

//             if (temp < mn)
//             {
//                 mn = temp;
//             }
//         }

//         return t[i][j] = mn;
//     }

//     int minCut(string s)
//     {
//         memset(t, -1, sizeof(t));
//         return solve(s, 0, s.size() - 1);
//     }
// };

// int Solution::t[1001][1001];