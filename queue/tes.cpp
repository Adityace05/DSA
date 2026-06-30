class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *temp = slow;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        slow->next = prev;
        fast = prev;
        slow = head;
        while (fast != NULL)
        {
            if (slow != fast)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true; // Single node or empty list is a palindrome

        // Find middle using slow-fast pointer
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = NULL;
        ListNode *curr = slow;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Compare first and second half
        ListNode *firstHalf = head;
        ListNode *secondHalf = prev;
        while (secondHalf)
        {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};