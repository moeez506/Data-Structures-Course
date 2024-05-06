#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSumArray;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            runningSumArray.push_back(sum);
        }
        return runningSumArray;
    }
};


