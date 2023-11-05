#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int MAX = 1000;
const int INF = 1e9;
int getMax(int &n, vector<string> &players, map<string, int> &status) {
    int max_score = -INF;
    for (int i = 0; i < n; i++) {
        if (players[i] == "") {
            break;
        }
        max_score = max(max_score, status[players[i]]);
    }
    return max_score;
}
string replay(int &n, vector<string> &players, vector<int> &scores, map<string, int> &status) {
    int max_score = getMax(n, players, status);
    map<string, int> cur_scores;
    
    for (int i = 0; i < n; i++) {
        string p = players[i];
        if (status[p] != max_score) {
            continue;
        }

        cur_scores[p] += scores[i];
        if (cur_scores[p] >= max_score) {
            return p;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<string> players;
    vector<int> scores;
    map<string, int> status;
    
    cin >> n;
    players.assign(n, "");
    scores.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> players[i] >> scores[i];
        status[players[i]] += scores[i];
    }

    cout << replay(n, players, scores, status);

    return 0;
}