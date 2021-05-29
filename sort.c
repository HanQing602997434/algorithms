
//插入排序
/*
    基本思想：将待排序的数据插入到前面已经排好序的有序序列中，直到插完所有元素
*/
int insert_sort(int* data, int length) {
    int i = 0, j = 0;

    for (i = 1; i < length; i++) {
        int temp = data[i];
        for (j = i - 1; j >= 0 && temp < data[j]; j--) {
            data[j+1] = data[j];
        }
        data[j+1] = temp;
    } 
}

//希尔排序
/*
    基本思想：对数据进行分组，对分组的数据进行插入排序，当组长为1时，算法终止
*/
int shell_sort(int* data, int length) {
    int gap = 0;
    int i = 0, j = 0;

    for (gap = length/2; gap < length; gap /= 2) {
        for (i = gap; i < length; i++) {
            int temp = data[i];
            for (j = i - gap; j >= 0; j -= gap) {

            }
        }
    }
}

//快速排序
/*
    基本思想：设置一个基准数，将小于基准数的放到左边，大于基准数的放到右边，左右指针相遇则是基准数的位置，然后递归定位所有基准数
*/
int quick_sort(int* data, int begin, int end) {
    if (begin + 1 >= end)
        return -1;
    int first = begin, last = end, temp = data[first];
    while (first < last) {
        while (first < last && data[last] > temp)
            --last;
        data[first] = data[last];
        while (first < last && data[first] < temp)
            ++first;
        data[last] = data[first];
    }
    data[first] = temp;
    quick_sort(data, begin, first - 1);
    quick_sort(data, first + 1, end);
}

//归并排序
/*
    基本思想：将数据二分，直至只有一个数据，合并数据
*/
int merge_sort(int* data, int begin, int end, int* temp) {
    if (begin + 1 >= end)
        return -1;
    int mid = begin + (end - begin) / 2;
    int p = begin, q = mid, i = begin;
    merge_sort(data, begin, mid, temp);
    merge_sort(data, mid, end, temp);
    while (p < mid && q < end) {
        if (q >= end || (p < mid && data[p] < data[q])) {
            temp[i++] = data[p++];
        } else {
            temp[i++] = data[q++];
        }
    }
    
    for (int i = begin; i < end; i++) {
        data[i] = temp[i];
    }
}