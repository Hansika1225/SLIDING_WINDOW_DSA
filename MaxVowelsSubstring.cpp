#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isVowel(char c){

        return (c=='a' || c=='e' || c=='i' ||
                c=='o' || c=='u');
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // First window
        for(int i = 0; i < k; i++){

            if(isVowel(s[i])){
                count++;
            }
        }

        int maxCount = count;

        // Slide window
        for(int i = k; i < s.length(); i++){

            // Add new character
            if(isVowel(s[i])){
                count++;
            }

            // Remove old character
            if(isVowel(s[i-k])){
                count--;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main() {

    Solution obj;

    string s = "abciiidef";
    int k = 3;

    int result = obj.maxVowels(s, k);

    cout << "Maximum vowels in substring of length "
         << k << " = " << result << endl;

    return 0;
}