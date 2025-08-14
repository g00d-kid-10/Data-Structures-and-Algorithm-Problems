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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list = new ListNode();
        ListNode *temp = list;
        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val<=list2->val) {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
                temp = temp->next;
        }

        if(!list1) {
            temp->next = list2;
        }
        else {
            temp->next = list1;
        }
        return list->next;
    }
    
    /*            ListNode* list = new ListNode();
            if(list1==nullptr && list2==nullptr) {
                delete list;
                list = nullptr;
                return list;
            } else if(list2==nullptr) {
                delete list;
                list = list1;
                return list;
            } else if(list1==nullptr){
                delete list;
                list = list2;
                return list;
            }

            ListNode *temp, *temp1, *temp2;
            temp = list, temp1 = list1, temp2 = list2;

            if(temp1->val<=temp2->val) {
                temp->val = temp1->val;
            } else {
                temp->val = temp2->val;
            }
            while(temp1!=nullptr || temp2!=nullptr) {
                if(temp1!=nullptr && temp2!=nullptr) {
                    if(temp1->val<=temp2->val) {
                    cout<<temp1->val<<"*";
                    temp->next = new ListNode(temp1->val);
                    temp1 = temp1->next;
                    } else {
                    cout<<temp2->val<<"#";
                    temp->next = new ListNode(temp2->val);
                    temp2 = temp2->next;
                    }
                } 
                else {
                    if(temp1!=nullptr) {
                        temp->next = new ListNode(temp1->val);
                        temp1 = temp1->next;          
                    }
                    if(temp2!=nullptr) {
                        temp->next = new ListNode(temp2->val);
                        temp2 = temp2->next;
                    }
                }
                    temp = temp->next;
            }
            return list->next;
    */
};

int main() {
    Solution s;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode(23, new ListNode(78)))));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // ListNode *list1 = nullptr;
    // ListNode *list2 = nullptr;
    ListNode *list;
    list = s.mergeTwoLists(list1, list2);
    cout<<list->val;
    cout<<list->next->val;
    cout<<list->next->next->val;
    cout<<list->next->next->next->val;
    cout<<list->next->next->next->next->val;
    cout<<list->next->next->next->next->next->val;
    cout<<list->next->next->next->next->next->next->val;
    cout<<list->next->next->next->next->next->next->next->val;
    // cout<<list->next->next->next->next->next->next->val;
    return 0;
}