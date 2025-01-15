#include<bits/stdc++.h>
using namespace std;

// 修改后的merge函数，返回合并后的有序向量
vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int i = 0;
    int j = 0;
    while (i < a.size() || j < b.size()) {
        int x = i < a.size()? a[i] : INT_MAX;  // 这里改为INT_MAX，确保比较能正确进行，避免出现未定义行为
        int y = j < b.size()? b[j] : INT_MAX;
        if (x <= y) {
            c.push_back(x);
            ++i;
        }
        else {
            c.push_back(y);
            ++j;
        }
    }
    return c;
}

// 修改后的mergeSort函数，实现正确的归并排序逻辑
void mergeSort(vector<int>& v, int left, int right) {
    if (left >= right) return;
    int mid = (right + left) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    // 调用merge函数合并左右子区间，将合并结果赋值回原区间
    vector<int> merged = merge(vector<int>(v.begin() + left, v.begin() + mid + 1),
                               vector<int>(v.begin() + mid + 1, v.begin() + right + 1));
    copy(merged.begin(), merged.end(), v.begin() + left);
}

int main() {
    vector<int> v = { 5, 3, 8, 6, 7, 2 };
    int size = v.size();

    cout << "排序前的数组: ";
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    mergeSort(v, 0, size - 1);

    cout << "排序后的数组: ";
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}