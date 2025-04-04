#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    return a > b;
}

string highPrecisionSub(string a, string b) {
    bool isNegative = false;
    if (!comp(a, b)) {
        swap(a, b);
        isNegative = true;
    }

    string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int borrow = 0;

    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        int sub = x - y - borrow;
        borrow = 0;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        }
        result += to_string(sub);
    }

    reverse(result.begin(), result.end());

    // Remove leading zeros
    auto it = result.find_first_not_of('0');
    if (it == string::npos) {
        return "0";
    }
    result = result.substr(it);
    if (isNegative) {
        result = "-" + result;
    }
    return result;
}
int main() {
    string a, b;
    cin >> a >> b;
    cout << highPrecisionSub(a, b) << endl;
    return 0;
}
