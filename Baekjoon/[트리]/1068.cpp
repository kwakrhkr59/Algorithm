#include <iostream>
#include <vector>
using namespace std;
vector<int> leaves;
int countLeaf(int root, vector<vector<int>> tree) {
    if (leaves[root]) {
        return leaves[root];
    }
    if (tree[root].empty()) {
        return leaves[root] = 1;
    }
    int total = 0;
    for (int child : tree[root]) {
        total += countLeaf(child, tree);
    }
    return leaves[root] = total;
}
int main() {
    int n, root_node, remove_node;
    cin >> n;

    vector<int> parent(n);
    vector<vector<int>> tree(n);
    leaves.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) {
            root_node = i;
        } else {
            tree[parent[i]].push_back(i);
        }
    }
    cin >> remove_node;

    countLeaf(root_node, tree);
    int leaf_count = leaves[root_node] - leaves[remove_node];
    // 지워지는 노드의 형제가 없을 때: 지워지는 노드의 부모 노드가 리프 노드가 됨
    if (leaves[remove_node] == leaves[parent[remove_node]]) {
        leaf_count++;   // 리프 노드 1 추가
    }
    cout << leaf_count;
    return 0;
}