#include <iostream>
#include <vector>
using namespace std;
struct trie {
    char ch;
    vector<trie> child;
    trie(char input_ch) {
        ch = input_ch;
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
int getCnt(int n, vector<string> &dict, trie *root) {
    int cnt = 0;
    trie *p, *tmp;
    for (int i = 0; i < n; i++) {
        p = NULL;
        tmp = root;
        for (auto ch : dict[i]) {
            if (tmp->child.size() != 1) {
                cnt++;
            }
            p = tmp;
            tmp = tmp->find(ch);
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string str;

    cout << fixed;
    cout.precision(2);


    while (cin >> n) {
        vector<string> dict(n);
        trie *root = new trie('\0');
        root->insert('\0');

        for (int i = 0; i < n; i++) {
            cin >> dict[i];
            trie *p = NULL, *tmp = root;

            for (auto ch : dict[i]) {
                p = tmp;
                tmp = tmp->find(ch);
                if (tmp == NULL) {
                    tmp = p->insert(ch);
                }
            }
            tmp->insert('\0');
        }

        cout << getCnt(n, dict, root) / float(n) << "\n";
    }
    return 0;
}