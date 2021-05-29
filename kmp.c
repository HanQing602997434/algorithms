
//kmp算法
/*
    基本思想：求得next数组，在字符比较不同时，根据next数组中公共前缀最大长度的值来决定回溯位置
*/

//pattern：模式串
//next数据求法：
void make_next(const char* pattern, int* next) {
    int q = 0, k = 0;
    int m = strlen(pattern);

    next[0] = 0;
    for (q = 1, k = 0; q < m; ++q) {
        while (k > 0 && pattern[q] != pattern[k]) {
            //k回溯到next[k-1]的位置
            k = next[k - 1];
        }

        if (pattern[q] == pattern[k]) {
            ++k;
        }

        next[q] = k;
    }
}

int kmp(const char* text, const char* pattern, int* next) {
    int n = strlen(text);
    int m = strlen(pattern);

    make_next(pattern, next);

    int i = 0, q = 0;
    for (i = 0, q = 0; i < n; ++i) {
        while (q > 0 && next[i] != pattern[q]) {
            q = next[q - 1];
        }

        if (next[i] == pattern[q]) {
            ++q;
        }

        if (q == m) {
            return i - q + 1;
        }
    }
}