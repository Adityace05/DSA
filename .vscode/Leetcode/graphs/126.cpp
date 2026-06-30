// class Solution
// {
// public:  // memory limit exided
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
//     {
//         queue<vector<string>> q;
//         q.push({beginWord});

//         unordered_set<string> st(wordList.begin(), wordList.end());
//         vector<string> usedOnLevel;
//         usedOnLevel.push_back(beginWord);

//         vector<vector<string>> ans;
//         int level = 1;

//         while (!q.empty())
//         {
//             vector<string> vec = q.front();
//             q.pop();

//             // New level
//             if (vec.size() > level)
//             {
//                 level = vec.size();
//                 for (auto &it : usedOnLevel)
//                 {
//                     st.erase(it);
//                 }
//                 usedOnLevel.clear();
//             }

//             string word = vec.back();

//             if (word == endWord)
//             {
//                 if (ans.empty())
//                 {
//                     ans.push_back(vec);
//                 }
//                 else if (ans[0].size() == vec.size())
//                 {
//                     ans.push_back(vec);
//                 }
//             }

//             for (int i = 0; i < word.size(); i++)
//             {
//                 char org = word[i];
//                 for (char ch = 'a'; ch <= 'z'; ch++)
//                 {
//                     if (ch == org)
//                         continue;
//                     word[i] = ch;

//                     if (st.find(word) != st.end())
//                     {
//                         vec.push_back(word);
//                         q.push(vec);
//                         usedOnLevel.push_back(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i] = org;
//             }
//         }
//         return ans;
//     }
// };
