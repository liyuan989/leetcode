/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        for (std::string& str : wordDict) {
            dict_.insert(str);
        }
        int len = static_cast<int>(s.size());
        dp_.resize(len);
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (dict_.count(s.substr(i, j - i + 1))) {
                    dp_[i].push_back(1);
                } else {
                    dp_[i].push_back(0);
                }
            }
        }
        std::vector<std::string> vec;
        dfs(s, len, vec);
        return result_;
    }

    void dfs(const std::string& s, int len, std::vector<std::string>& vec) {
        if (len <= 0) {
            std::string str;
            for (int i = static_cast<int>(vec.size()) - 1; i >= 0; --i) {
                str += vec[i];
                if (i > 0) {
                    str += ' ';
                }
            }   
            result_.push_back(str);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (dp_[i][len - i - 1]) {
                vec.push_back(s.substr(i, len - i));
                dfs(s, i, vec);
                vec.pop_back();
            }
        }
    }

private:
    std::unordered_set<std::string> dict_;
    std::vector<std::string> result_;
    std::vector<std::vector<char>> dp_;
};

int main(int argc, const char* argv[]) {
    std::vector<std::string> vec = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    const char* str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    Solution s;
    std::vector<std::string>&& result = s.wordBreak(str, vec);
    for (std::string& str : result) {
        std::cout << str << std::endl;        
    }
    return 0;
}

