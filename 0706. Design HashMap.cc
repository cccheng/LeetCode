class MyHashMap {
    static const size_t prime = 5003;
    vector<list<pair<int,int>>> container;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        container.resize(prime);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& list = container[key % prime];
        auto iter = find_if(list.begin(), list.end(), [&key](auto& x) { return x.first == key; });

        if (iter == list.end())
            list.push_back({key,value});
        else
            iter->second = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& list = container[key % prime];
        auto iter = find_if(list.begin(), list.end(), [&key](auto& x) { return x.first == key; });

        if (iter == list.end())
            return -1;
        else
            return iter->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& list = container[key % prime];
        auto iter = find_if(list.begin(), list.end(), [&key](auto& x) { return x.first == key; });

        if (iter != list.end())
            list.erase(iter);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
