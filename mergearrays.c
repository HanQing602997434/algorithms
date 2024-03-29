// 合并两个有序数组

void MergeArrays(int[] nums_1, int m, int[] nums_2, int n) {
    int k = m + n;
    int temp[k];

    for (int index = 0, index_1 = 0, index_2 = 0; i < k; i++) {
        if (index_1 >= m) {
            temp[index] = nums_2[index_2++];
        }
        else if (index_2 >= n) {
            temp[index] = nums_1[index_1++];
        }
        else if (nums_1[index_1] < nums_2[index_2]) {
            temp[index] = nums_1[index_1++];
        }
        else {
            temp[index] = nums_2[index_2++];
        }
    }

    for (int i = 0; i < k; i++) {
        nums_1[i] = temp[i];
    }
}

void merge(int[] nums_1, int m, int[] nums_2, int n) {
    int k = m + n;
    for (int index = k - 1, index_1 = m-1, index_2 = n-1; index >= 0; i--) {
        if (index_1 < 0) {
            nums_1[index] = nums_2[index_2--];
        }
        else if (index_2 < 0) {
            break;
        }
        else if (nums_1[index_1] < nums_2[index_2]) {
            nums_1[index] = nums_2[index_2--];
        }
        else {
            nums_1[index] = nums_1[index_1--];
        }
    }
}