// A hash tabe based solution in c++ using the data structure unordered_map<,>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (auto x : s) {
            count[x]++;
        }

        for (auto x : t) {
            count[x]--;
        }

        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }
};
