// class Solution
// {
// public:
//     string removeKdigits(string num, int k)
//     {
//         stack<char> st;
//         int n = num.length();

//         for (int i = 0; i < n; i++)
//         {
//             while (!st.empty() && st.top() > num[i] && k > 0)
//             {
//                 st.pop();
//                 k--;
//             }
//             st.push(num[i]);
//         }

//         while (!st.empty() && k > 0)
//         {
//             st.pop();
//             k--;
//         }

//         string ans = "";
//         while (!st.empty())
//         {
//             ans += st.top();
//             st.pop();
//         }

//         reverse(ans.begin(), ans.end());

//         int idx = 0;
//         while (idx < ans.length() && ans[idx] == '0')
//         {
//             idx++;
//         }

//         ans = ans.substr(idx);
//         if (ans.empty())
//             return "0";

//         return ans;
//     }
// };