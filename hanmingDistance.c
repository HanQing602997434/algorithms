// 汉明距离
// 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

int hanmingDistance(int x, int y) {
    int distance = 0;
    for (int xor = x ^ y; xor != 0; xor & (xor - 1)) {
        distance++;
    }
    
    return distance;
}