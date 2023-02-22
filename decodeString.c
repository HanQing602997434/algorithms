// 字符串解码

/*给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。*/

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            else if (isalpha(cur)) {
                res += s[i];
            }
            else if (s[i] == '[') {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; ++j) {
                    strs.top() += res;
                }
                res = strs.top();
            }
        }

        return res;
    }
};