// class Solution
// {
// private:
//     bool dfs(int node, vector<vector<int>> &prerequisites, vector<int> &vis, vector<int> &visPath)
//     {
//         vis[node] = 1;
//         visPath[node] = 1;

//         for (auto it : prerequisites[node])
//         {
//             if (!vis[it])
//             {
//                 if (dfs(it, prerequisites, vis, visPath))
//                 {
//                     return true;
//                 }
//             }
//             else if (visPath[it])
//             {
//                 return true;
//             }
//         }

//         visPath[node] = 0;
//         return false;
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {


//         vector<int> vis(numCourses, 0);
//         vector<int> visPath(numCourses, 0);

//         for (int i = 0; i < numCourses; i++)
//         {
//             if(!vis[i]){
//                 if (dfs(i, prerequisites, vis, visPath))
//             {
//                 return true;
//             }
//             }
//         }
//         return false;
//     }
// };


// By kahn's Algorithm

// class Solution Kahn's Algorithm
    // { leetcode 210  time complexity:- O(v + e)
    // public:
    //     vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    //     {

    //         vector<vector<int>> adj(numCourses);
    //         vector<int> indegree(numCourses, 0);
    //         queue<int> q;
    //         int count;

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
    //             count++;

    //             for (int next : adj[node])
    //             {
    //                 indegree[next]--;
    //                 if (indegree[next] == 0)
    //                 {
    //                     q.push(next);
    //                 }
    //             }
    //         }

    //         if(count == v) return false; // found a cycle
    //         return true;
    //     }
    // };