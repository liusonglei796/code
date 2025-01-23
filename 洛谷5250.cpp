#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    // 使用 set 存储木材长度，set 会自动对元素进行排序且不允许重复元素
    set<int> woods;

    for (int i = 0; i < n; ++i) {
        int operation, length;
        cin >> operation >> length;
        if (operation == 1) {
            // 进货操作
            if (woods.count(length) > 0) {
                cout << "Already Exist" << endl;
            } else {
                woods.insert(length);
            }
        } else if (operation == 2) {
            // 出货操作
            if (woods.empty()) {
                cout << "Empty" << endl;
            } else {
                auto it = woods.lower_bound(length);
                if (it == woods.begin()) {
                    // 如果 lower_bound 指向第一个元素，说明这是最接近的元素
                    cout << *it << endl;
                    woods.erase(it);
                } else if (it == woods.end()) {
                    // 如果 lower_bound 指向 end()，说明没有大于等于 length 的元素，取最后一个元素
                    --it;
                    cout << *it << endl;
                    woods.erase(it);
                } else {
                    int val1 = *it;
                    --it;
                    int val2 = *it;
                    if (val1 - length < length - val2) {
                        cout << val1 << endl;
                        woods.erase(woods.find(val1));
                    } else {
                        cout << val2 << endl;
                        woods.erase(woods.find(val2));
                    }
                }
            }
        }
    }
    return 0;
}