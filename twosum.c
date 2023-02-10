// 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> storeNums;
        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (storeNums.find(another) != storeNums.end()) {
                return {storeNums[another], i};
            }
            else {
                storeNums.insert(std::pair<int, int>(storeNums[i], i));
            }
        }

        return {};
    }

private:

}