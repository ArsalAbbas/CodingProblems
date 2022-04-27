class Solution {
private:
    vector<int> vp;
    vector<int> vr;
    void make_set(int v) {
        vp[v] = v;
        vr[0] = 0;
    }
    int find_set(int v) {
        if (vp[v] < 0) make_set(v);
        if (v == vp[v]) return v;
        return vp[v] = find_set(vp[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (vr[a] < vr[b])
                swap(a, b);
            vp[b] = a;
            if (vr[a] == vr[b])
                vr[a]++;
        }
    }
public:
    string smallestStringWithSwaps(
        string s,
        vector<vector<int>>& ve
    ) {
        if (ve.empty())
            return s;
        int n = s.size();
        vp.assign(n, -1);
        vr.assign(n, -1);
        for (auto& e: ve)
            union_sets(e[0], e[1]);
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < n; ++i)
            umap[find_set(i)].push_back(i);
        vector<char> vc;
        for (auto& [p, vi]: umap) {
            int sz = vi.size();
            vc.assign(sz, 0);
            for (int i = 0; i < sz; ++i)
                vc[i] = s[vi[i]];
            sort(vc.begin(), vc.end());
            for (int i = 0; i < sz; ++i)
                s[vi[i]] = vc[i];
        }
        return s;
    }
};
// class Solution {
// public:
//     string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//         unordered_map<int,vector<int>> mp;
//         for(int i=0; i<pairs.size(); i++){
//             mp[pairs[i][0]].push_back(pairs[i][1]);
//             mp[pairs[i][1]].push_back(pairs[i][0]);
//         }
//         vector<int> visited(s.size());
//         queue<int> q;
//         string res = s;
//         for(int i=0; i<s.size(); i++){
//             vector<char> characters;
//             vector<int> indexes;
//             if(!visited[i]){
//                 visited[i] = 1;
//                 q.push(i);
//                 while(!q.empty()){
//                     int ind = q.front();
//                     characters.push_back(s[ind]);
//                     indexes.push_back(ind);
//                     q.pop();
//                     for(int b : mp[ind]){
//                         if(!visited[b]){
//                             cout<<b<<" ";
//                             visited[b] = 1;
//                             q.push(b);
//                         }
//                     }
//                 }
//                 sort(characters.begin(), characters.end());
//                 sort(indexes.begin(), indexes.end());
//                 for(int j = 0; j<indexes.size();j++){
//                     res[indexes[j]] = characters[j];
//                 }
//             }
//         }
//        return res;
//     }
// };