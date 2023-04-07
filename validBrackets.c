// 有效的括号

bool validBrackets(string s) {
    Stack<char> stack;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            stack.push(')');
        else if (s[i] == '{')
            stack.push('}');
        else if (s[i] == '[')
            stack.push(']');
        else if (stack.empty() || stack.pop() != s[i])
            return false;
    }
    return stack.empty();
}