// // User function Template for C++

// class Solution
// {
// public:
//     int minimumMultiplications(vector<int> &arr, int start, int end)
//     {
//         vector<int> dist(100000, 1e9);
//         queue<pair<int, int>> q;
//         q.push({0, start});
//         dist[start] = 0;

//         while (!q.empty())
//         {
//             int nums = q.front().second;
//             int steps = q.front().first;
//             q.pop();

//             if (nums % 100000 == end)
//             {
//                 return steps;
//             }
//             for (int i = 0; i < arr.size(); i++)
//             {
//                 int num = nums * arr[i] % 100000;
//                 if (steps + 1 < dist[num])
//                 {
//                     q.push({steps + 1, num});
//                     dist[num] = steps + 1;
//                 }
//             }
//         }

//         return -1;
//     }
// };
