class BrowserHistory {
    stack<string> add;
    stack<string> hist;
public:
    BrowserHistory(string homepage) {
        this->add.push(homepage);
        // this->hist = stack<string>();
    }
    
    void visit(string url) {
        add.push(url);
        hist = stack<string>();
    }
    
    string back(int steps) {
        while(steps-- && add.size() > 1) {
            hist.push(add.top());
            add.pop();
        }
        return add.top();
    }
    
    string forward(int steps) {
        while(steps-- && !hist.empty()) {
            add.push(hist.top());
            hist.pop();
        }
        return add.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */