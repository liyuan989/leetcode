/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        if (s.empty()) {
            return result;
        }
        std::vector<std::string> vec;
        dfs(s, 0, vec, result);
        return result;
    }

    void dfs(std::string& s, size_t start, std::vector<std::string>& vec, std::vector<std::vector<std::string>>& result) {
        if (start > s.size() - 1) {
            return;
        }
        for (size_t len = 1; len <= s.size() - start; ++len) {
            std::string sub = s.substr(start, len);
            if (isPalindrome(sub)) {
                vec.push_back(sub);
                if (start + len == s.size()) {
                    result.push_back(vec);
                } else {
                    dfs(s, start + len, vec, result);
                }
                vec.pop_back();
            }
        }
    }

    bool isPalindrome(std::string& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    std::vector<std::vector<std::string>>&& result = s.partition("aab");
    for (auto& vec : result) {
        for (auto& str : vec) {
            std::cout << str << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

