class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int sum = 0;
        priority_queue<int> pq;
        for(auto x: courses) {
            sum += x[0];
            pq.push(x[0]);
            if(sum > x[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};