// class Solution
// {
// public:
//     int largestRectangleArea(vector<int> &heights)
//     {
//         stack<int> s;
//         int n = heights.size();
//         vector<int> r(n, 0);
//         vector<int> l(n, 0);

//         for (int i = n - 1; i >= 0; i--)
//         {
//             while (s.size() > 0 && heights[s.top()] >= heights[i])
//             {
//                 s.pop();
//             }

//             if (s.empty())
//             {
//                 r[i] = n;
//             }
//             else
//             {
//                 r[i] = s.top();
//             }
//             s.push(i);
//         }

//         while (!s.empty())
//         {
//             s.pop();
//         }
//         for (int i = 0; i < n; i++)
//         {
//             while (s.size() > 0 && heights[s.top()] >= heights[i])
//             {
//                 s.pop();
//             }

//             if (s.empty())
//             {
//                 l[i] = -1;
//             }
//             else
//             {
//                 l[i] = s.top();
//             }
//             s.push(i);
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int width = (r[i] - l[i] - 1);
//             int area = heights[i] * width;
//             ans = max(ans, area);
//         }

//         return ans;
//     }
// };