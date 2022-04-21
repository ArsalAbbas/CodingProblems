class MyHashSet {
public:
    vector<bool> hashSet;
    MyHashSet() {
        hashSet.resize(1e6+1,false);
    }
    
    void add(int key) {
        hashSet[key]=true;
    }
    
    void remove(int key) {
        hashSet[key]=false;
    }
    
    bool contains(int key) {
        if (hashSet[key]==true)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */