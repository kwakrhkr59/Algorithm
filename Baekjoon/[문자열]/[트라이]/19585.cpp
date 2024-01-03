#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct trie{
    char ch;
    bool is_last;
    vector<trie> child;
    trie(char input_ch) {
        ch = input_ch;
        is_last = false;
    }
    trie *insert(char input_ch) {
        child.push_back(trie(input_ch));
        return &child.back();
    }
    trie *find(char target) {
        for (trie &c : child) {
            if (c.ch == target) {
                return &c;
            }
        }
        return NULL;
    }
};
trie *init() {
    trie *root = new trie('\0');
    return root;
}
void insertString(trie *root, string str) {
    trie *p = NULL, *c = root;
    for (char ch : str) {
        p = c;
        c = c->find(ch);
        if (c == NULL) {
            c = p->insert(ch);
        }
    }
    c->is_last = true;
}
bool isLegendary(trie *color_root, trie *name_root, string str) {
    trie *color_p = NULL, *color_c = color_root;
    trie *name_p = NULL, *name_c = name_root;
    vector<bool> valid(str.size(), false);
    int i = 0, j = str.size() - 1;
    while (color_c) {
        color_p = color_c;
        color_c = color_c->find(str[i]);
        if (color_p->is_last) {
            valid[i] = true;
        }
        i++;
    }
    while (name_c) {
        name_p = name_c;
        name_c = name_c->find(str[j]);
        if (name_p->is_last && valid[j + 1]) {
            return true;
        }
        j--;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, n, q;
    string str;
    trie *color_root = init();
    trie *name_root = init();

    cin >> c >> n;
    while (c--) {
        cin >> str;
        insertString(color_root, str);
    }
    while (n--) {
        cin >> str;
        reverse(str.begin(), str.end());
        insertString(name_root, str);
    }

    cin >> q;
    while (q--) {
        cin >> str;
        if (isLegendary(color_root, name_root, str)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}