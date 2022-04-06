class Solution {
public:
    long long mod = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i = 0; i <= n - 3; i++){
            int low = i + 1;
            int high = n - 1;
            int need = target - arr[i];
            while(low < high){
            if(arr[low] + arr[high] < need)
            low++;
            else if(arr[low] + arr[high] > need)
            high--;
            else{
            if(arr[low] != arr[high]){
            int left_count = 1;
            int right_count = 1;
            while(low < high && arr[low] == arr[low + 1]){
            left_count++; 
            low++;
            }   
            while(high > low && arr[high] == arr[high - 1]){
            right_count++;
            high--; 
            } 
            count = (count % mod + left_count % mod * right_count % mod) % mod;         
            low++;
            high--;
            }
         else{
                int total_duplicate = (high - low + 1);
                count = (count % mod + (total_duplicate % mod * (total_duplicate - 1) % mod) / 2) % mod;  
                        break;
                    }
                }
            }
        }
        return count;
    }
};