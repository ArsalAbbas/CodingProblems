class Solution {
public:
   bool reorderedPowerOf2(int n) {
	string str = to_string(n);
	sort(str.begin(), str.end());
	int ans = 1, k = 30;
	unordered_set<string> h;
	while(k--){
		string anss = to_string(ans);
		sort(anss.begin(), anss.end());
		h.insert(anss);
		ans *= 2;
	}
	if(h.find(str) != h.end())      
		return true;
	return false;
}

};