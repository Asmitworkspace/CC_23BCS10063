#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   
    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];   
    }
    long long mod = 1000000007;
    long long ans = 0;
    for (int b = 0; b < 32; b++) {
        long long ones = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] & (1LL << b)) ones++;
        }
        long long zeros = n - ones;
        ans = (ans + ((ones * zeros) % mod * 2) % mod) % mod;
    }
    cout <<"answer is: " << ans << endl;
    return 0;
}
