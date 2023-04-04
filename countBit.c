// 比特位计数
vector<int> countBits(int num) {
    vector<int> bits;
    bits.resize(num + 1);
    for (int i = 1; i < num; i++) {
        bits[i] = bits[i & (i - 1)] + 1;
    }

    return bits;
}

// 利用奇偶性解决
vector<int> countBits(int num) {
    vector<int> bits;
    bits.resize(num + 1);
    bits[0] = 0;
    for (int i = 1; i <= num; i++) {
        bits[i] = ((i&1) == 1 ? bits[i-1]+1 : bits[i>>1]);
    }
    return bits;
}