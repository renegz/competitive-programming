#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tail = res;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1!=nullptr) ? l1->val : 0;
            int val2 = (l2!=nullptr) ? l2->val : 0;

            int ans = val1 + val2 + carry;
            carry = ans/10;

            ListNode* t = new ListNode(ans%10);
            tail->next = t;

            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : l1; 
            l2 = (l2 != nullptr) ? l2->next : l2;
        }

        delete(tail);
        return res->next;
        
    }
};

int main(){
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    //[1,9,9,9,9,9,9,9,9,9]
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution s;
    ListNode* ans = s.addTwoNumbers(l1, l2);

    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}