class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        int car = 0;

        while(l1 || l2 || car){
            int sum = 0;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += car;
            car = sum/10;
            ListNode* node = new ListNode(sum%10);
            tmp->next = node;
            tmp = tmp->next;
        }
        return ans->next;
    }
};
