class LRUCache {
private:
    int _capacity;
    list<int> _lru;                               // key (MRU .. LRU)
    unordered_map<int, list<int>::iterator> _map; // key -> iterator
    unordered_map<int, int> _kv;                  // key -> value

public:
    LRUCache(int capacity) : _capacity(capacity) {

    }

    int get(int key) {
        if (!_kv.count(key))
            return -1;
        update(key);
        return _kv[key];
    }

    void put(int key, int value) {
        if (_kv.count(key)) {
            _kv[key] = value;
            update(key);
            return;
        }

        if (_lru.size() >= _capacity)
            evict();
        _lru.push_front(key);
        _kv[key] = value;
        _map[key] = _lru.begin();
    }

    void evict(void) {
        int k = _lru.back();
        _lru.pop_back();
        _map.erase(k);
        _kv.erase(k);
    }

    void update(int key) {
        auto it = _map[key];
        auto k = *it;
        _lru.erase(it);
        _lru.push_front(k);
        _map[key] = _lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
