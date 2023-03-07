// 插入排序

void InsertSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int preIndex = i;
        int currentValue = nums[preIndex];
        while (preIndex >= 0 && currentValue < nums[preIndex]) {
            nums[preIndex + 1] = nums[preIndex];
            preIndex--;
        }

        nums[preIndex + 1] = currentValue;
    }
}