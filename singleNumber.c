// 只出现一次的数字
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result = result ^ nums[i];
    }
    return result;
}