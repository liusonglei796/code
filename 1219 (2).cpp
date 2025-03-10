#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans;
vector<bool> col, diag1, diag2;
int countSolutions = 0;
int solutionsPrinted = 0;

void printSolution() {
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    solutionsPrinted++;
}

void solve(int row) {
    if (row == n) {
        countSolutions++;
        if (solutionsPrinted < 3) {
            printSolution();
        }
        return;
    }

    for (int colNum = 0; colNum < n; ++colNum) {
        if (!col[colNum] && !diag1[row + colNum] && !diag2[row - colNum + n - 1]) {
            ans[row] = colNum;
            col[colNum] = diag1[row + colNum] = diag2[row - colNum + n - 1] = true;
            solve(row + 1);
            col[colNum] = diag1[row + colNum] = diag2[row - colNum + n - 1] = false;
        }
    }
}

int main() {
    cin >> n;

    ans.resize(n);
    col.resize(n, false);
    diag1.resize(2 * n - 1, false);
    diag2.resize(2 * n - 1, false);

    solve(0);

    cout << countSolutions << endl;

    return 0;
}