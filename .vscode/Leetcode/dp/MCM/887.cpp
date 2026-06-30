// class Solution
// {
// public:
//     static int t[101][10001];

//     int solve(int k, int n)
//     {

//         if (n == 0 || n == 1)
//             return n;

//         if (k == 1)
//             return n;

//         if (t[k][n] != -1)
//             return t[k][n];

//         int low = 1;
//         int high = n;

//         int ans = INT_MAX;

//         while (low <= high)
//         {

//             int mid = low + (high - low) / 2;

//             int left, right;

//             // Egg breaks
//             if (t[k - 1][mid - 1] != -1)
//                 left = t[k - 1][mid - 1];
//             else
//             {
//                 left = solve(k - 1, mid - 1);
//                 t[k - 1][mid - 1] = left;
//             }

//             // Egg survives
//             if (t[k][n - mid] != -1)
//                 right = t[k][n - mid];
//             else
//             {
//                 right = solve(k, n - mid);
//                 t[k][n - mid] = right;
//             }

//             int temp = 1 + max(left, right);

//             ans = min(ans, temp);

//             // Move binary search
//             if (left < right)
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }

//         return t[k][n] = ans;
//     }

//     int superEggDrop(int k, int n)
//     {

//         memset(t, -1, sizeof(t));

//         return solve(k, n);
//     }
// };

// int Solution::t[101][10001];