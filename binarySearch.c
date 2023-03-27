// 二分查找
int binarySearch(vector<int> nums) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (target > nums[mid]) {
            start = mid + 1;
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarySearch(vector<int> nums, int target) {
    return searchNums(nums, 0, nums.size() - 1, target);
}

int searchNums(vector<int>& nums, int start, int end, int key) {
    int mid = (start + end) / 2;
    if (start <= end) {
        if (key > nums[mid]) {
            return searchNums(nums, mid + 1, end, key);
        } else if (key < nums[mid]) {
            return searchNums(nums, start, mid - 1, key);
        } else {
            return mid;
        }
    } else {
        return -1;
    }
}