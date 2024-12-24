#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    list<int> queue;
    queue.push_back(1);

    unordered_map<int, list<int>::iterator> positionMap;
    positionMap[1] = queue.begin();

    for (int i = 2; i <= N; ++i) {
        int k, p;
        cin >> k >> p;

        list<int>::iterator it = positionMap[k];
        if (p == 0) {
            it = queue.insert(it, i);
        } else {
            it = queue.insert(next(it), i);
        }
        positionMap[i] = it;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        if (positionMap.find(x) != positionMap.end()) {
            queue.erase(positionMap[x]);
            positionMap.erase(x);
        }
    }

    for (list<int>::iterator it = queue.begin(); it != queue.end(); ++it) {
        if (it != queue.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}
