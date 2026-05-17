#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.length();

        if(k > s2.length()) return false;

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);

        // Build frequency of s1
        for(char c : s1){
            s1Freq[c - 'a']++;
        }

        // Sliding window on s2
        for(int i = 0; i < s2.length(); i++){

            // Add current character
            s2Freq[s2[i] - 'a']++;

            // Remove old character
            if(i >= k){
                s2Freq[s2[i-k] - 'a']--;
            }

            // Check permutation
            if(s1Freq == s2Freq){
                return true;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool ans = obj.checkInclusion(s1, s2);

    if(ans){
        cout << "Permutation exists" << endl;
    }
    else{
        cout << "Permutation does not exist" << endl;
    }

    return 0;
}