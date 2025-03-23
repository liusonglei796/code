#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3;
string s;
int main() {
    cin >> p1 >> p2 >> p3 >> s;
    int n = 0;
    while (s.find("-", n) != string::npos) {
        auto it = s.find("-", n);
        if (it > 0 && it < s.size() - 1 &&
            ((isdigit(s[it - 1]) && isdigit(s[it + 1])) ||
             (islower(s[it - 1]) && islower(s[it + 1])))) {
            if (s[it - 1] + 1 == s[it + 1]) {
                s.erase(it, 1);
            } else if (s[it - 1] < s[it + 1]) {
                string temp = "";
                for (char i = s[it - 1] + 1; i < s[it + 1]; ++i) {
                    if (p1 == 1) {
                        for (int j = 0; j < p2; ++j)
                            temp += tolower(i);
                    } else if (p1 == 2) {
                        for (int j = 0; j < p2; ++j)
                            temp += toupper(i);
                    } else if (p1 == 3) {
                        for (int j = 0; j < p2; ++j)
                            temp += '*';
                    }
                }
                if (p3 == 2) {
                    reverse(temp.begin(), temp.end());
                }
                s.erase(it, 1);
                s.insert(it, temp);
                n = it + temp.size();
            } else {
                n = it + 1;
            }
        } else {
            n = it + 1;
        }
    }
    cout << s;
    return 0;
}