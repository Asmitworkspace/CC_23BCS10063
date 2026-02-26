#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string &pat) {
    int m = (int)pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmpSearch(const string &txt, const string &pat) {
    vector<int> res;
    int n = (int)txt.size();
    int m = (int)pat.size();
    if (m == 0) return res;

    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                res.push_back(i - m);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    vector<int> positions = kmpSearch(text, pattern);

    if (positions.empty()) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < (int)positions.size(); i++) {
            if (i) cout << " ";
            cout << positions[i];
        }
        cout << "\n";
    }
    return 0;
}
