#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> freq;

        int left = 0;
        int longest = 0;

        for(int right = 0; right < fruits.size(); right++){

            // Add fruit to window
            freq[fruits[right]]++;

            // Shrink if more than 2 distinct fruits
            while(freq.size() > 2){

                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }

                left++;
            }

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};

int main() {

    Solution obj;

    vector<int> fruits = {1,2,1,2,3};

    cout << obj.totalFruit(fruits);

    return 0;
}