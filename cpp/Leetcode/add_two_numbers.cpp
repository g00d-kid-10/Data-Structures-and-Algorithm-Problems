#include <iostream>
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
        ListNode *l3, *t1, *t2, *t3;
        int len1 = 0, len2 = 0, sum = 0, n1, n2, max, check = 0;
        t1 = l1; t2 = l2;
        
        l3 = new ListNode(0);
        t3 = l3;

        while(t1!=nullptr) {   
            len1++;
            t1 = t1->next;
        }

        while(t2!=nullptr) {   
            len2++;
            t2 = t2->next;
        }

        max = (len1>len2)?len1:len2;
        t1 = l1; t2 = l2;
        
        while(max>0) {

            n1 = (t1)?(t1->val):0;
            n2 = (t2)?(t2->val):0;
            sum+=(n1+n2);

            t3->next = new ListNode(sum%10);
            t3 = t3->next;

            if(sum>9) {
                sum = 1;
                if(max==1) {max++;}
            }
            else {
                sum = 0;
            }

            if(len1>0){t1 = t1->next;}
            if(len2>0){t2 = t2->next;}

            max--, len1--, len2--;
        }
        return l3->next;
    }
};

int main() {
    ListNode *list1 = new ListNode(9, new ListNode(9, new ListNode(9)));
    ListNode *list2 = new ListNode(9, new ListNode(9, new ListNode(5, new ListNode(9))));
    Solution s;
    ListNode *list3 = s.addTwoNumbers(list1, list2);
    while(list3!=nullptr) {
        cout<<list3->val<<" ";
        list3=list3->next;
    }
	return 0;
}