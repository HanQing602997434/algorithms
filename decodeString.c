// 字符串解码

/*给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。*/

string getDigits(string& s, size_t& ptr) {
    string ret = "";
    while (isdigit(s[ptr])) {
        ret.push_back(s[ptr++]);
    }
    return ret;
}

string getString(vector<string>& v) {
    string ret = "";
    for (const auto& s : v) {
        ret += s;
    }
    return ret;
}

string decodeString(string s) {
    vector<string> stk;
    size_t ptr = 0;

    while (ptr < s.size()) {
        char cur = s[ptr];
        if (isdigit(cur)) {
            // 获取一个数字入栈
            string digits = getDigits(s, ptr);
            stk.push_back(digits);
        }
        else if (isalpha(cur) || cur == '[') {
            // 获取一个字母入栈
            stk.push_back(1, s[ptr++]);
        }
        else {
            ++ptr;
            vector<string> sub;
            while (stk.back() != "[") {
                sub.push_back(stk.back());
                stk.pop_back();
            }
            reverse(sub.begin(), sub.end());
            // 左括号出栈
            stk.pop_back();
            // 此时栈顶为数字
            int repTime = stoi(stk.back());
            stk.pop_back();
            string t, o = getString(sub);
            // 构造字符串
            while (repTime--) t += o;
            stk.push_back(t);
        }
    }

    return getString(stk);
}

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