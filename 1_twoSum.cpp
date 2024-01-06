#include <bits/stdc++.h>
using namespace std;

// Solution 1
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         for(auto x = nums.begin(); x != nums.end(); x++) {
//             auto y = find(x+1, nums.end(), target-*x); // find will point to nums.end() if not found
//             if(y != nums.end()) { // found the number
//                 result.push_back(x - nums.begin());
//                 result.push_back(y - nums.begin());
//                 break;
//             }
//         }
//         return result;
//     }
// };

// Solution 2 - Hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            int x = nums[i];
            int complement = target - x;
            auto y = map.find(complement);
            if(y != map.end()) { //found
                return {y->second, i};
            }
            else {
                map[x] = i;
            }
        }
        return {};
    }
};