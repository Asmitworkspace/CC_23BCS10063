#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ull BASE = 911382323ull;

    int n, m;
    cin >> n >> m;

    vector<unordered_set<ull>> st(600001);
    vector<ull> pw(600001);
    pw[0] = 1;
    for (int i = 1; i < (int)pw.size(); i++) pw[i] = pw[i - 1] * BASE;

    auto val = [&](char c) -> ull {
        return (ull)(c - 'a' + 1); // a=1, b=2, c=3
    };

    auto getHash = [&](const string &s) -> ull {
        ull h = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            h += val(s[i]) * pw[i];
        }
        return h;
    };

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st[s.size()].insert(getHash(s));
    }

    while (m--) {
        string s;
        cin >> s;

        int L = (int)s.size();
        ull h = getHash(s);

        bool ok = false;

        for (int i = 0; i < L && !ok; i++) {
            ull cur = val(s[i]) * pw[i];

            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[i]) continue;

                ull nh = h - cur + val(c) * pw[i];
                if (st[L].find(nh) != st[L].end()) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
