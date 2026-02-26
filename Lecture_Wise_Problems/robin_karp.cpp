#include<bits/stdc++.h>
using namespace std;

const int base = 10;

int hash_fn(string str){
    int result = 0;
    for(int i=0; i<str.size(); i++){
        result = result*base + (str[i] - 'a' + 1);
    }
    return result;
} 


int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int n = text.size();
    int m = pattern.size();

    int txt_hash = hash_fn(text.substr(0,m));
    int patt_hash = hash_fn(pattern);

    int power = 1;

    for(int i=0; i<m-1; i++){
        power = power*base;
    }

    for(int i=0; i<=n-m; i++){
        if(txt_hash == patt_hash){
            cout<<"String found at index at "<<i<<endl;
        }
        if(i<n-m){
            txt_hash -= (text[i]-'a' + 1)*power;
            txt_hash = txt_hash * base;
            txt_hash += (text[i+m]-'a' + 1);
        }
    }

    return 0;
}