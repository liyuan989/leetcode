/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2); // init capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

#include <list>
#include <unordered_map>

struct Node {
    int key;
    int value;

    Node(int k, int v)
        : key(k),
          value(v) {
    }
};

class LRUCache {
public:
    LRUCache(int capacity) 
        : size_(capacity) {
    }

    int get(int key) {
        if (map_.find(key) == map_.end()) {
            return -1;
        }
        std::list<Node>::iterator it = map_[key];
        list_.splice(list_.begin(), list_, it);
        map_[key] = list_.begin();
        return list_.front().value;
    }
    
    void put(int key, int value) {
        if (map_.find(key) == map_.end()) {
            if (list_.size() == size_) {
                map_.erase(list_.back().key);
                list_.pop_back();
            }
            Node node(key, value);
            list_.push_front(node);
            map_[key] = list_.begin();
        } else {
            std::list<Node>::iterator it = map_[key];
            it->value = value;
            list_.splice(list_.begin(), list_, it);
            map_[key] = list_.begin();
        }
    }

private:
    std::unordered_map<int, std::list<Node>::iterator> map_;
    std::list<Node> list_;
    size_t size_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
