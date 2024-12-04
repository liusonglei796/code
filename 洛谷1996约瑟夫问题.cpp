#include <iostream>
#include <unordered_set>
using namespace std;

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {};
} ListNode;

// 在链表尾部插入节点的函数
void tailInsert(ListNode*& head, int val) {
    ListNode* newnode = new ListNode(val);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    ListNode* cur = head;
    while (cur->next!= nullptr) {
        cur = cur->next;
    }
    cur->next = newnode;
}

// 解决约瑟夫问题的函数
int josephus(int n, int m) {
    ListNode* head = nullptr;
    unordered_set<int> alive;  // 存储还在圈中的人员编号

    // 构建包含n个节点的链表，同时将节点值（人员编号）加入到集合中
    for (int i = 1; i <= n; ++i) {
        tailInsert(head, i);
        alive.insert(i);
    }

    // 将链表尾节点与头节点相连，形成循环链表
    ListNode* cur = head;
    while (cur->next!= nullptr) {
        cur = cur->next;
    }
    cur->next = head;

    cur = head;
    ListNode* prev = nullptr;
    while (!alive.empty()) {
        // 按照报数间隔m进行报数，处理指针移动到链表末尾后回到头的情况
        for (int i = 1; i < m; ++i) {
            prev = cur;
            cur = cur->next;
        }

        // 输出出圈人员编号
        cout << cur->val << " ";
        // 从集合中移除出圈人员编号
        alive.erase(cur->val);

        // 处理要出圈的节点是头节点的情况
        if (prev == nullptr) {
            ListNode* nextHead = cur->next;
            delete cur;
            head = nextHead;
         cur=head;
        } else {
            prev->next = cur->next;
            ListNode* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
    }
    cout << endl;
    return head->val;  // 返回最后剩下的人的编号
}

int main() {
    int n, m;
    cin >> n >> m;
    int result = josephus(n, m);
    return 0;
}