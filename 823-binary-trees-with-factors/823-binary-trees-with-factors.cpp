class Solution {
public:
	int numFactoredBinaryTrees(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int n = arr.size();

		unordered_map<int,long long> mp; 
		for(int i : arr) mp[i] = 1;

		int mod = int(1e9 + 7);

		for(int i = 0 ; i < n ; i++){
			long long count = 0;
			for(int j=0;j<i;j++){ 
				if(arr[i]%arr[j]==0){   
					if(mp.find(arr[i]/arr[j]) != mp.end()){
						count += (mp[arr[i]/arr[j]] * mp[arr[j]]) % mod;
					}
				}
			}
			mp[arr[i]] += count;
			mp[arr[i]] = mp[arr[i]] % mod;
		}

		long long ans = 0;
		for(auto i : mp) {ans += i.second ; ans = ans % mod ;}
		return (int)ans % mod; 
	}
};