// 计数排序
// 适用于整数，且区间较小的情形

void CountSort(vector<int>& nums) {
    // 寻找数组中的最大值和最小值
    int bias, min = nums[0], max = nums[0];
    for (int i = 0;  i < nums.size(); i++) {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min < nums[i];
    }

    bias = 0 - min;
    // 获得计数数组的容量
    vector<int> countArray = {0};

    // 遍历整个原始数组，将原始数组中每个元素转化为计数数组下标，
    // 并将计数数组下标对应的元素值大小进行累加
    for (int i = 0; i < nums.size(); i++) {
        countArray[nums[i] + bias]++;
    }
}