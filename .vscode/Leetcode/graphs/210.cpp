// class Solution
// { kahn's Algorithm
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
//     {

//         vector<vector<int>> adj(numCourses);
//         vector<int> indegree(numCourses, 0);
//         queue<int> q;
//         vector<int> topo;

//         // Build graph
//         for (auto &p : prerequisites)
//         {
//             int course = p[0];
//             int prereq = p[1];
//             adj[prereq].push_back(course);
//             indegree[course]++;
//         }

//         // Push nodes with indegree 0
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // Kahn's BFS
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             topo.push_back(node);

//             for (int next : adj[node])
//             {
//                 indegree[next]--;
//                 if (indegree[next] == 0)
//                 {
//                     q.push(next);
//                 }
//             }
//         }

//         // Cycle check
//         if (topo.size() != numCourses)
//             return {};

//         return topo;
//     }
// };
