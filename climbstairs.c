// 爬楼梯，有n阶楼梯，每次只能走一阶或者两阶，有多少种走法

class Solution {
public:
    // 解法一
    int climbStairs(int n) {
    if (n == 1 || n == 2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }

    // 解法二
    int climbStairsMap(int n ){
        if (n == 1 || n == 2) return n;
        if (storeMap[n] != 0)
            return storeMap[n];
        else {
            int result = climbStairsMap(n-1) + climbStairsMap(n-2);
            storeMap[n] = result;
            return result;
        }
    }

    // 解法三
    int climbStairsLoop(int n) {
        if (n == 1 || n == 2) return n;
        int result = 0;
        int pre = 2;
        int prePre = 1;
        for (int i = 3; i <= n; i++) {
            result = pre + prePre;
            prePre = pre;
            pre = result;
        }
        return result;
    }

private:
    std::map<int, int> storeMap;
}