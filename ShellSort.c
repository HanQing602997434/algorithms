// 希尔排序

void ShellSort(vector<int>& nums) {
    int len = nums.size();
    int gap = len / 2;
    while (gap > 0) {
        for (int i = gap; i < len; i++) {
            int currentValue = nums[i];
            int preIndex = i - gap;
            while (preIndex >= 0 && nums[preIndex] > currentValue) {
                nums[preIndex + gap] = nums[preIndex];
                preIndex -= gap;
            }
            nums[preIndex + gap] = currentValue;
        }
        gap /= 2;
    }
}