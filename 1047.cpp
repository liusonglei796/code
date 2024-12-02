#include <iostream>
#include <set>

int main() {
    int l, m;
    std::cin >> l >> m;
    std::set<int> removed_trees;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        for (int j = u; j <= v; ++j) {
            removed_trees.insert(j);
        }
    }

    int count = l + 1 - removed_trees.size();
    std::cout << count << std::endl;
    return 0;
}