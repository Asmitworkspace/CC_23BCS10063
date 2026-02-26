#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    int lowestPrimeFactor = -1;
    int highestPrimeFactor = -1;

    for(int i = 2; i <= n; i++){
        if(isPrime[i] && n % i == 0){
            lowestPrimeFactor = i;
            break;
        }
    }

    for(int i = n; i >= 2; i--){
        if(isPrime[i] && n % i == 0){
            highestPrimeFactor = i;
            break;
        }
    }

    cout << "n: " << n << endl;
    cout << "Lowest Prime Factor: " << lowestPrimeFactor << endl;
    cout << "Highest Prime Factor: " << highestPrimeFactor << endl;

    return 0;
}
