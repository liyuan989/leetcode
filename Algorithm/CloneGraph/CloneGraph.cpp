/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (!node) {
            return node;
        }
        if (hash_.find(node) != hash_.end()) {
            return hash_[node];
        }
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        hash_[node] = copy;
        for (UndirectedGraphNode* p : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(p));
        }
        return copy;
    }

private:
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash_;
};

int main(int argc, const char* argv[]) {
    UndirectedGraphNode* p1 = new UndirectedGraphNode(0);
    UndirectedGraphNode* p2 = new UndirectedGraphNode(0);
    UndirectedGraphNode* p3 = new UndirectedGraphNode(0);
    p1->neighbors.push_back(p2);
    p1->neighbors.push_back(p3);
    Solution s;
    UndirectedGraphNode* result = s.cloneGraph(p1);
    std::cout << result->label << ' ' << result->neighbors[0]->label << ' ' << result->neighbors[1]->label << std::endl;
    return 0;
}
