#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 链表节点结构体定义
typedef struct Node {
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
} Node;

// 创建节点并添加到链表末尾的函数
void createNode(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val);
        return;
    }
    Node* cur = head;
    while (cur->next!= nullptr) {
        cur = cur->next;
    }
    cur->next = new Node(val);
}

// 创建循环链表的函数，返回类型改为void，更符合逻辑
void loop(Node*& head, vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
        createNode(head, v[i]);
    }
    if (head!= nullptr) {
        Node* cur = head;
        while (cur->next!= nullptr) {
            cur = cur->next;
        }
        cur->next = head;
    }
}

int main() {
    Node* list1 = nullptr;  // 初始化链表头指针
    Node* list2 = nullptr;
    int n;
    int a;
    int b;
    cin >> n >> a >> b;
    vector<int> v1(a);
    vector<int> v2(b);

    loop(list1, v1);
    loop(list2, v2);

    int count1 = 0;
    int count2 = 0;
    Node* cur1 = list1;
    Node* cur2 = list2;
    for (int i = 0; i < n; ++i) {
        // 简化后的条件判断逻辑，清晰地根据规则统计count1和count2
        if ((cur1->val == 0 && (cur2->val == 2 || cur2->val == 3)) ||
            (cur1->val == 1 && (cur2->val == 0 || cur2->val == 3)) ||
            (cur1->val == 2 && (cur2->val == 1 || cur2->val == 4)) ||
            (cur1->val == 3 && (cur2->val == 2 || cur2->val == 4)) ||
            (cur1->val == 4 && (cur2->val == 0 || cur2->val == 1))) {
            count1++;
        } else if (cur1->val!= cur2->val) {
            count2++;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    cout << count1 << " " << count2 << endl;

    return 0;
}