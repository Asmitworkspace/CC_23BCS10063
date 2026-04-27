#include<bits/stdc++.h>
using namespace std;
vector<int> rabinKarp(string text, string pattern) {
    vector<int> result;
    int d = 256; 
    int q = 101;
    int M = pattern.length();
    int N = text.length();
    int p = 0; 
    int t = 0; 
    int h = 1;
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                result.push_back(i);
        }
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t += q;
        }
    }
    return result;
}
int main(){
    string text = "abcab";
    string pattern = "ab";
    vector<int> occurrences = rabinKarp(text, pattern);
    for (int i : occurrences) {
        cout << "Pattern will be found at index: " << i << endl;
    }
    return 0;
}