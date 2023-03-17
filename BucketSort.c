// 桶排序
// 计数排序的升级版，将数据分到若干个桶中，再分别对桶内数据进行排序
// 最后将桶数据合并

void BucketSort(vector<int>& nums, int bucketCap) {
    if (nums.size() < 2) {
        return;
    }
    int max = nums[0], min = nums[0];
    // 找到最大值，最小值
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }

    // 获得桶的数量
    int bucketCount = (max - min) / bucketCap + 1;

    // 桶构建
    vector<vector<int>> bucketArr;
    vector<int> resultArr;
    
    // 将原始数组中的数据分配到桶中
    for (int i = 0; i < nums.size(); i++) {
        bucketArr[(nums[i] - min) / bucketCap].push(nums[i]);
    }

    // 桶内数据进行排序
    for (int i = 0; i < bucketCount; i++) {
        if (bucketCap == 1) {
            for (int j = 0; j < bucketCap[i].size(); j++) {
                resultArr.add(bucketArr[i][j]);
            }
        }
        else {
            if (bucketCount == 1)
                bucketCap--;

            sort(bucketArr[i]);
            for (int j = 0; j < temp.size(); j++) {
                resultArr.add(temp[j]);
            }
        }
    }
}