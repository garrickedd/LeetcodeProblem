#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // Khởi tạo biến nhớ, ban đầu không có giá trị nào cần nhớ

        ListNode* result = new ListNode(0); // Tạo một node mới với giá trị ban đầu là 0, node này sẽ làm node head cho danh sách kết quả
        ListNode* curr = result; // Con trỏ curr trỏ tới node đầu tiên của danh sách kết quả

        while (l1 || l2 || carry) { // Vòng lặp sẽ tiếp tục cho đến khi cả hai danh sách và biến nhớ đều đã được xử lý hết
            int d1 = l1 ? l1->val : 0; // Lấy giá trị của node hiện tại trong danh sách l1 nếu nó tồn tại, nếu không thì gán 0
            int d2 = l2 ? l2->val : 0; // Lấy giá trị của node hiện tại trong danh sách l2 nếu nó tồn tại, nếu không thì gán 0

            int sum = d1 + d2 + carry; // Tính tổng của hai giá trị và biến nhớ

            curr->next = new ListNode(sum % 10); // Tạo một node mới với giá trị là phần đơn vị của tổng (sum % 10)
            curr = curr->next; // Di chuyển con trỏ curr tới node mới đã tạo

            carry = sum / 10; // Cập nhật giá trị biến nhớ cho lần lặp tiếp theo

            l1 = l1 ? l1->next : nullptr; // Di chuyển con trỏ của danh sách l1 tới node tiếp theo, nếu đã hết danh sách thì gán nullptr
            l2 = l2 ? l2->next : nullptr; // Di chuyển con trỏ của danh sách l2 tới node tiếp theo, nếu đã hết danh sách thì gán nullptr
        }

        return result->next; // Trả về node thực sự đầu tiên của danh sách kết quả, bỏ qua node đầu tiên với giá trị 0
    }
};
