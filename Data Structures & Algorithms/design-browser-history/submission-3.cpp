class BrowsingNode {
public:
    string url;
    BrowsingNode* next;
    BrowsingNode* prev;

    BrowsingNode(string url): url(url), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
private:
    BrowsingNode* head;
    BrowsingNode* curr;
    
public:
    BrowserHistory(string homepage) {
        head = new BrowsingNode(homepage);
        curr = head;
    }
    
    void visit(string url) {
        BrowsingNode* node = new BrowsingNode(url);
        clearForward(curr->next);
        curr->next = node;
        node->prev = curr;
        curr = node;
    }
    
    string back(int steps) {
        while(steps--) {
            if(curr->prev == nullptr) break;
            curr = curr->prev;
        }

        return curr->url;
    }
    
    string forward(int steps) {
        while(steps--) {
            if(curr->next == nullptr) break;
            curr = curr->next;
        }
        return curr->url;
    }

private:
    void clearForward(BrowsingNode* node) {
        if(node == nullptr) return;
        clearForward(node->next);
        delete node;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */