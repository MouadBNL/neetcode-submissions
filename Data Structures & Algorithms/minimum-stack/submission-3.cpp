class MinStack {
private:
    vector<int> s;
    vector<int> m;
    int mn;
public:
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int val) {
        s.push_back(val);
        if(val < mn) mn = val;
        m.push_back(mn);
    }
    
    void pop() {
        s.pop_back();
        m.pop_back();
        if(m.empty()) mn = INT_MAX; else mn = m.back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return m.back();
    }
};
