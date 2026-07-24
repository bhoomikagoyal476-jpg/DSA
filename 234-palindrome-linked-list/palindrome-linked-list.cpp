class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // Fix 1: Correct base condition with || instead of &&
        if (head == NULL || head->next == NULL)
            return true;

        ListNode *slow = head, *fast = head;

        // Fix 2: Move fast by 2 nodes so slow lands in the middle
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next; // Moved 2 steps
        }

        ListNode* second = reverse(slow->next);
        ListNode* copysecond = second;
        ListNode* first = head;
        bool ans = true;

        while (second) {
            if (first->val != second->val) {
                ans = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Restore the original list structure
        slow->next = reverse(copysecond);

        return ans; 
    }
};