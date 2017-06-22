/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stdio.h>

struct Node {
    std::string word;
    int level;
};

class Solution {
public:
    int ladderLength(const std::string& beginWord, 
                     const std::string& endWord, 
                     std::vector<std::string>& wordList) {
        if (beginWord == endWord) {
            return 2;
        }
        std::unordered_set<std::string> dict;
        for (std::string& str : wordList) {
            dict.insert(str);
        }
        std::queue<Node> q;
        int result = 0;

        Node first;
        first.word = beginWord;
        first.level = 1;
        q.push(first);

        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            if (node.word == endWord) {
                result = node.level;
                break;
            }
            std::string s = node.word;
            int level = node.level;
            for (size_t i = 0; i < node.word.size(); ++i) {
                char letter = s[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    s[i] = ch;
                    if (dict.find(s) != dict.end()) {
                        Node new_node;
                        new_node.word = s;
                        new_node.level = level + 1;
                        q.push(new_node);
                        dict.erase(s);
                    }
                }
                s[i] = letter;
            }
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    std::vector<std::string> vec = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution solution;
    int result = solution.ladderLength("hit", "cog", vec);
    printf("%d\n", result);
    return 0;
}

