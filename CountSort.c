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

    int index = 0; // 访问原始数组的下标计数器
    int i = 0; // 访问计数数组的下标计数器

    // 访问计数数组，将计数数组中的元素转换后，重新写回原始数组
    while (index < nums.size()) {
        // 只要计数数组中当前下标元素的值不为0，就将计数数组中的元素转换后，重新写回原始数组
        if (countArray[i] != 0) {
            nums[index] = i - bias;
            countArray[i]--;
            index++;
        }
        else {
            i++;
        }
    }
}