// 栈实现队列
#include <stack>

class stackQueue{
public:
    stackQueue() {}

private:
    static stack<int> inStack;
    static stack<int> outStack;

    void push(int x) {
        inStack.push(x);
    }

    void pop() {
        outStack.pop();
    }

    void peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top())
            inStack.pop();
        }
    }
};