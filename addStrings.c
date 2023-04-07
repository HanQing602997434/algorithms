// 字符串相加
// 给定两个字符串形式的非负整数num1和num2，计算它们的和并同样以
// 形式返回。

// 你不能使用任何内建的用于处理大整数的库，也不能直接将输入的
// 字符串转换为整数形式。

string addStrings(string num1, string num2) {
    string s;
    int carry = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--) {
        int x = i < 0 ? 0 : num1[i] - '0';
        int y = j < 0 ? 0 : num2[j] - '0';
        s += ((x + y + carry) % 10);
        carry = (x + y + carry) / 10;
    }

    return s;
}