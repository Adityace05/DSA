// class Solution {
// public:
//     unordered_map<string, bool> mp;
//     bool isScramble(string s1, string s2) {
//          if (s1 == s2)
//             return true;

//         if (s1.length() != s2.length())
//             return false;

//         int n = s1.length();

//         if (n <= 1)
//             return false;

//         string key = s1 + " " + s2;

//         if (mp.find(key) != mp.end())
//             return mp[key];

       
//         vector<int> freq(26, 0);

//         for (int i = 0; i < n; i++) {
//             freq[s1[i] - 'a']++;
//             freq[s2[i] - 'a']--;
//         }

//         for (int x : freq) {
//             if (x != 0)
//                 return mp[key] = false;
//         }
       
//         bool flag = false;
//         for(int i=1; i<n; i++){
//             bool cond1 = isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i));
//             bool cond2 = isScramble(s1.substr(0, i), s2.substr(0,i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i));

//             if(cond1 || cond2){
//                 flag = true;
//                 break;
//             }
//         }

//         mp[key] = flag;
//         return flag;
//     }
// };