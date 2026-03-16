#include <iostream>
using namespace std;
#include <string>
#include <vector>

struct ListNode 
{
    int val;        // 节点存储的值
    ListNode *next; // 指向下一个节点的指针
    
    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* Head=nullptr;//将头尾置为空
        ListNode* Tail=nullptr;
        int carry=0;
        while (l1||l2)
        {
            int n1=l1 ? l1->val:0;//为空为0，不为空取值
            int n2=l2 ? l2->val:0;
            int sum=n1+n2+carry;
            if(!Head)
            {
                Head=Tail=new ListNode(sum%10);
            }
            else
            {
                Tail->next=new ListNode(sum%10);//往后一个创建一个数
                Tail=Tail->next;//Tail指针往后指一位
            }
            carry=sum/10;
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        if(carry>0)
        {
            Tail->next=new ListNode(carry);
        }
        return Head;
    }
};

// 辅助函数：从数组创建链表
ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    
    return head;
}

// 辅助函数：打印链表
void printLinkedList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << " → ";
        head = head->next;
    }
    cout << "]" << endl;
}

// 辅助函数：释放链表内存
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    
    // 测试用例1：342 + 465 = 807
    // 342 用链表表示：2 → 4 → 3
    // 465 用链表表示：5 → 6 → 4
    // 结果应为：7 → 0 → 8 (807)
    cout << "测试用例1：342 + 465 = 807" << endl;
    ListNode* l1 = createLinkedList({2, 4, 3});
    ListNode* l2 = createLinkedList({5, 6, 4});
    
    cout << "l1: ";
    printLinkedList(l1);
    cout << "l2: ";
    printLinkedList(l2);
    
    ListNode* result = solution.addTwoNumbers(l1, l2);
    cout << "结果: ";
    printLinkedList(result);
    
    // 清理内存
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(result);
    
    cout << "\n------------------------\n" << endl;
    
    // 测试用例2：0 + 0 = 0
    cout << "测试用例2：0 + 0 = 0" << endl;
    l1 = createLinkedList({0});
    l2 = createLinkedList({0});
    
    cout << "l1: ";
    printLinkedList(l1);
    cout << "l2: ";
    printLinkedList(l2);
    
    result = solution.addTwoNumbers(l1, l2);
    cout << "结果: ";
    printLinkedList(result);
    
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(result);
    
    cout << "\n------------------------\n" << endl;
    
    // 测试用例3：999 + 1 = 1000
    // 999: 9 → 9 → 9
    // 1: 1
    // 结果应为：0 → 0 → 0 → 1 (1000)
    cout << "测试用例3：999 + 1 = 1000" << endl;
    l1 = createLinkedList({9, 9, 9});
    l2 = createLinkedList({1});
    
    cout << "l1: ";
    printLinkedList(l1);
    cout << "l2: ";
    printLinkedList(l2);
    
    result = solution.addTwoNumbers(l1, l2);
    cout << "结果: ";
    printLinkedList(result);
    
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(result);
    
    cout << "\n------------------------\n" << endl;
    
    // 测试用例4：不同长度的链表
    // 123 + 45 = 168
    // 123: 3 → 2 → 1
    // 45: 5 → 4
    // 结果应为：8 → 6 → 1 (168)
    cout << "测试用例4：123 + 45 = 168" << endl;
    l1 = createLinkedList({3, 2, 1});
    l2 = createLinkedList({5, 4});
    
    cout << "l1: ";
    printLinkedList(l1);
    cout << "l2: ";
    printLinkedList(l2);
    
    result = solution.addTwoNumbers(l1, l2);
    cout << "结果: ";
    printLinkedList(result);
    
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(result);
    
    return 0;
}