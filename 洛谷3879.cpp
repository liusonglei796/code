#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    unordered_map<string, set<int>> word_passages;  // word -> set of passage numbers
    
    // Process each passage
    for(int i = 1; i <= n; i++) {
        int L;
        cin >> L;
        while(L--) {
            string word;
            cin >> word;
            word_passages[word].insert(i);
        }
    }
    
    // Process queries
    int m;
    cin >> m;
    while(m--) {
        string word;
        cin >> word;
        auto it = word_passages.find(word);
        if(it != word_passages.end()) {
            bool first = true;
            for(int passage_num : it->second) {
                if(!first) cout << " ";
                cout << passage_num;
                first = false;
            }
        }
        cout << "\n";
    }
    
    return 0;
}