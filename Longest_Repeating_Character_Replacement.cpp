#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int longest = 0;

        for(int right = 0; right < s.length(); right++){

            // Add current character
            freq[s[right] - 'A']++;

            // Track highest frequency
            maxFreq = max(maxFreq,
                          freq[s[right] - 'A']);

            // Shrink invalid window
            while((right - left + 1) - maxFreq > k){

                freq[s[left] - 'A']--;
                left++;
            }

            // Update answer
            longest = max(longest,
                          right - left + 1);
        }

        return longest;
    }
};

int main() {

    Solution obj;

    string s = "AABABBA";
    int k = 1;

    int ans = obj.characterReplacement(s, k);

    cout << "Longest Repeating Substring Length = "
         << ans << endl;

    return 0;
}