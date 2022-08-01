class Solution {
public:
    int nCrModp(int n, int r, int p)
{
    if (r > n - r)
        r = n - r;
 
    int C[r + 1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;
 
    for (int i = 1; i <= n; i++) {
 
        for (int j = min(i, r); j > 0; j--)
 
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
    int uniquePaths(int m, int n) {
        return nCrModp(m+n-2, m-1, 2e9);
    }
};