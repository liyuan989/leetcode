/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<size_t, vector<vector<string>>> results;
        vector<string> vec;
        vec.push_back(beginWord);
        exec(endWord, wordList, results, vec);
        return results.begin()->second;
    }

    void exec(string endWord, vector<string>& wordList, map<size_t,vector<vector<string>>>& result, vector<string>& vec) {
        if (vec.back() == endWord) {
            result[vec.size()].push_back(vec);
            return;
        }
        for (size_t i = vec.size() - 1; i < wordList.size(); ++i) {
            if (IsOnceDiff(vec.back(), wordList[i])) {
                swap(wordList[vec.size() - 1], wordList[i]);
                string s = wordList[vec.size() - 1];
                vec.push_back(s);
                exec(endWord, wordList, result, vec);
                vec.pop_back();
                swap(wordList[vec.size() - 1], wordList[i]);
            }
        } 
    }

    bool IsOnceDiff(const string& lhs, const string& rhs) {
        int count = 0;
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) {
                ++count;
            }
        }
        return count == 1;
    }
};


int main(int argc, const char *argv[]) {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    vector<vector<string>>&& result = s.findLadders("hit", "cog", wordList);
    for (auto& v : result) {
        for (auto& s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
