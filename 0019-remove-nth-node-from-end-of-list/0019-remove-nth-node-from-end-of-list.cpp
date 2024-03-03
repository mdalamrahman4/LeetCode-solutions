class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* copy = head;
        while (copy) {
            count++;
            copy = copy->next;
        }
        if (count == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        copy = head;
        int i = 0;
        while (i++ < count - n - 1) { 
            copy = copy->next;
        }
        ListNode* temp = copy->next;
        copy->next = temp->next;
        delete temp;
        return head;
    }
};
