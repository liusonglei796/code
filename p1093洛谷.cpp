#include <iostream>
#include <algorithm>
using namespace std;

// 定义学生结构体
struct Student {
    int id;    // 学号
    int chinese;
    int math;
    int english;
    int total;  // 总分
};

// 自定义比较函数，用于按照题目规则比较两个学生
bool compare(const Student& a, const Student& b) {
    if (a.total!= b.total) {
        return a.total > b.total;
    }
    if (a.chinese!= b.chinese) {
        return a.chinese > b.chinese;
    }
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;
    Student students[n];  // 创建学生结构体数组

    // 读取学生成绩并计算总分，同时赋予学号
    for (int i = 0; i < n; ++i) {
        students[i].id = i + 1;
        cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    // 对学生结构体数组进行排序
    sort(students, students + n, compare);

    // 输出前5名学生的学号和总分
    for (int i = 0; i < 5; ++i) {
        cout << students[i].id << " " << students[i].total << endl;
    }

    return 0;
}