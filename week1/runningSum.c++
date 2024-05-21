#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSumArray;
        runningSumArray.reserve(nums.size());
        int sum ;
        int i=0;
        for ( i; i <nums.size() ; i++) {
            sum += nums[i];
            runningSumArray.push_back(sum);
        }
        return runningSumArray;
    }
};


