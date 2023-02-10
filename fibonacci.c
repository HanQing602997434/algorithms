// 斐波那契数列
// 与爬楼梯完全一样
class Solution {
public:
    int fibonacci(int n) {
        if (n == 0 || n == 1) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }

    int fibonacciMap(int n) {
        if (n == 0 || n == 1) return n;
        if (storeMap[n] != 0)
            return storeMap[n];
        else {
            int result = fibonacciMap(n-1) + fibonacci(n-2);
            storeMap[n] = result;
            return result;
        }
    }

    int fibonacciMap(int n) {
        if (n == 0 || n == 1) return n;
        int result = 0;
        int pre = 1;
        int prePre = 0;
        for (int i = 0; i <= n; i++) {
            result = pre + prePre;
            prePre = pre;
            pre = result;
        }
        return result;
    }

private:
    std::map<int, int> storeMap;
}