#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int windowSum = 0;

        // Calculate first window sum
        for(int i = 0; i < k; i++){
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for(int i = k; i < nums.size(); i++){

            // Add next element
            windowSum += nums[i];

            // Remove previous element
            windowSum -= nums[i-k];

            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    double result = obj.findMaxAverage(nums, k);

    cout << "Maximum Average = " << result << endl;

    return 0;
}