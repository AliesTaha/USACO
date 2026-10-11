/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     constructor:
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* get_middle(ListNode* h1){
        if (not h1->next){
            return nullptr;
        }
        ListNode* prev=h1;
        ListNode* si=h1;
        ListNode* fi=h1->next;
        while (fi!=nullptr){
            prev=si;
            si=si->next;
            fi=fi->next;
                if (fi){
                    fi=fi->next;
                }
        }
        prev->next=nullptr;
        return si;
    }

    ListNode* merge(ListNode* h1, ListNode* h2){
        if ((h1->val)>(h2->val)){
            swap(h1,h2);
        }
        ListNode* og=h1;
        if (not (h1->next)){
            h1->next=h2;
            return h1;
        }
        ListNode* nh;
        while (true){
            if ((h1->next) && (h1->next->val)>(h2->val)){
                nh=h1->next;
                h1->next=h2;
                h2=nh;
                h1=h1->next;
            }
            else{
                if (not (h1->next)){
                    h1->next=h2;
                    break;
                }
                h1=h1->next;
            }
        }
        return og;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* h1=head;
        if (not h1){
            return h1;
        }
        if (not h1->next){
            return h1;
        }
        ListNode* h2=get_middle(h1);
        if (h2){
            h1=sortList(h1);
            h2=sortList(h2);
            return merge(h1, h2);
        }
        return head;
    }
};