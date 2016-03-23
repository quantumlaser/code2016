/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/
struct CacheNode {
    int key;
    int val;
    CacheNode(int k=0, int v=0):key(k), val(v){}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(m_cacheMap.find(key)==m_cacheMap.end())
            return -1;
        m_cacheList.splice(m_cacheList.begin(), m_cacheList, m_cacheMap[key]);
        m_cacheMap[key] = m_cacheList.begin();
        return m_cacheMap[key]->val;
    }
    
    void set(int key, int val) {
        if(m_cacheMap.find(key) == m_cacheMap.end()) {
            if(m_cacheMap.size() == m_capacity) {
                m_cacheMap.erase(m_cacheList.back().key);
                m_cacheList.pop_back();
            }
            m_cacheList.push_front(CacheNode(key, val));
        } else {
            m_cacheMap[key]->val = val;
            m_cacheList.splice(m_cacheList.begin(), m_cacheList, m_cacheMap[key]);
        }
        m_cacheMap[key] = m_cacheList.begin();
    }
    
    list<CacheNode> m_cacheList;
    unordered_map<int, list<CacheNode>::iterator> m_cacheMap;
    int m_capacity;
};