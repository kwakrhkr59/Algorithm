#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct trie {
    int depth;
    string str;
    vector<trie> child;
    trie(string input_str, int d) {
        depth = d;
        str = input_str;
    }
    bool operator<(const trie &other) const {
        return str < other.str;
    }
    trie *insert(string next_str) {
        // trie *next_child = new trie(next_str, depth + 1);
        // child.push_back(*next_child);
        // return next_child;
        child.push_back(trie(next_str, depth + 1));
        return &child.back();
    }
    trie *find(string str) {
        for (trie &c : child) {
            if (c.str == str) {
                return &c;
            }
        }
        return NULL;
    }
    void print() {
        for (int i = 0; i < depth; i++) {
            cout << "--";
        }
        cout << str << "\n";

        sort(child.begin(), child.end());
        for (trie c : child) {
            c.print();
        }
    }
} trie;


int main() {
    int k, t;
    string input_str;
    trie *root = new trie("", -1);

    cin >> k;
    while (k--) {
        cin >> t;
        trie *p = NULL, *tmp = root;

        while (t--) {
            cin >> input_str;
            p = tmp;
            tmp = tmp->find(input_str);
            if (tmp == NULL) {
                tmp = p->insert(input_str);
            }
        }
    }

    sort(root->child.begin(), root->child.end());
    for (trie c : root->child) {
        c.print();
    }

    return 0;
}