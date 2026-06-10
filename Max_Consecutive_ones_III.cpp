#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeros = 0;
        int longest = 0;

        for(int right = 0; right < nums.size(); right++) {

            if(nums[right] == 0) {
                zeros++;
            }

            while(zeros > k) {

                if(nums[left] == 0) {
                    zeros--;
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

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << obj.longestOnes(nums, k);

    return 0;
}