class Solution {
public:
    static bool isVowel(char ch) {
        return
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    static string sortVowels(string s) {
        array<int, 128> cnt = {};
        for (char ch : s) ++cnt[ch];

        int w = 0;
        for (char ch : "AEIOUaeiou")
            while (cnt[ch]--) {
                while (!isVowel(s[w])) ++w;
                s[w++] = ch;
            }
        
        return s;
    }
};