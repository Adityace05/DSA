// class Solution
// {
// public:
//     bool canVisitAllRooms(vector<vector<int>> &rooms)
//     {
//         int n = rooms.size();
//         vector<int> vis(n, 0);
//         vis[0] = 1;
//         queue<int> q;
//         q.push(0);

//         while (!q.empty())
//         {
//             a int key = q.front();
//             q.pop();
//             vis[key] = 1;

//             for (auto it : rooms[key])
//             {
//                 if (!vis[it])
//                 {
//                     q.push(it);
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (!vis[i])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };