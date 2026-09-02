
typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    void print() const {
        if(prev ==nullptr) cout << "NULL";
        else cout << prev->val;
        cout << "<" << val << ">";
        if(next ==nullptr) cout << "NULL";
        else cout << next->val;
        cout << ", ";
    }
} ListNode;

class MyLinkedList {
   private:
    ListNode* head;
    ListNode* tail;
    int lenght;

    void dd() {
        ListNode* curr = head;
        while(curr!=nullptr) {
            curr->print();
            curr=curr->next;
        }

        cout << "HEAD: "; head->print();
        cout << ", TAIL: "; tail->print();
        cout << "\n";
    }

   public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        lenght = 0;
    }

    int get(int index) {
        cout << "$get(" << index << "): ";
        dd();
        ListNode* curr = getNodeAtIndex(index);
        if (curr == nullptr) return -1;
        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = val;
        node->next = head;
        node->prev = nullptr;
        if(head == nullptr) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            head = node;
        }
        cout << "$addAtHead(" << val << "):";
        dd();
    }

    void addAtTail(int val) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = val;
        node->next = nullptr;
        node->prev = tail;
        if(tail == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        cout << "$addAtTail(" << val << "):";
        dd();
    }

    void addAtIndex(int index, int val) {
        ListNode* curr = getNodeAtIndex(index-1);
        if (curr == nullptr) return;
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = val;

        node->next = curr->next;
        node->prev = curr;
        
        if(curr->next!=nullptr && curr->next->prev != nullptr)
            curr->next->prev = node;
        else 
            tail = node;
        curr->next = node;
        cout << "$addAtIndex(" << index << ", " << val << "):";
        dd();
    }

    void deleteAtIndex(int index) {
        cout << "$deleteAtIndex: idx=" << index <<". ";
        ListNode* curr = getNodeAtIndex(index);
        if (curr == nullptr) {
            cout << "NOT FOUND!\n";
            return;
        }
        cout << "val=" << curr->val << ". ";
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
            head->prev = nullptr;
        }

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
            tail->next = nullptr;
        }

        dd();
        //free(curr);
    }


    ListNode* getNodeAtIndex(int index) {
        ListNode* curr = head;
        while (index--) {
            if (curr == nullptr) return nullptr;
            curr = curr->next;
        }
        return curr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */