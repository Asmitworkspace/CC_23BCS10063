#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> factors;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    for (int x : factors) {
        cout << x << " ";
    }

    return 0;
}
