#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int i;
    cin >> i;
    int num1, num2;

char p='a';
    for (int j = 0; j < i; ++j) {
        string input;
        cin >> input;
        if ( isalpha(input[0])) {
p=input[0];            
cin >> num1 >> num2;
        } else {
            num1 = stoi(input);
            cin >> num2;
        }
    string result;
        int res;
        stringstream ss;
        if (p == 'a') {
            res = num1 + num2;
            ss << num1 << "+" << num2 << "=" << res;
        } else if (p == 'b') {
            res = num1 - num2;
            ss << num1 << "-" << num2 << "=" << res;
        } else if (p == 'c') {
            res = num1 * num2;
            ss << num1 << "*" << num2 << "=" << res;
        }

        result = ss.str();
        cout << result << endl;
        cout << result.length() << endl;
    }

    return 0;
}
