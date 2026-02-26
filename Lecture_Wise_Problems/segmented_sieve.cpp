#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void createSieve() {
    for (int i = 2; i <= N; i++) {
        sieve[i] = true;
    }
    for (int i = 2; i * i <= N; i++) {
        if (sieve[i] == true) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int N) {
    vector<int> ds;
    for (int i = 2; i <= N; i++) {
        if (sieve[i] == true) {
            ds.push_back(i);
        }
    }
    return ds;
}

int main() {
    createSieve();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        // step 1: generate all primes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));
        
        // step 2: create dummy array of length (r-l+1)
        // mark every element as 1
        int dummy[r-l+1];
        for(int i=0; i<(r-l+1); i++){
            dummy[i] = 1;
        }
        
        //step 3: for all multiples of primes in dummy mark false
        for (auto pr : primes) {
            int firstMultiple = (l / pr) * pr;
            if (firstMultiple < l) firstMultiple += pr;
        
            for (int j = max(firstMultiple, pr * pr); j <= r; j += pr) {
                dummy[j - l] = 0;
            }
        }

        // get all primes
        for(int i=l; i<=r; i++){
            if(dummy[i-l] == 1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

// create sieve
const int N = 1000000;
int sieve[N+1];
void createSieve(){
    for(int i=2; i<=N; i++){
        sieve[i] = true;
    }
    for(int i=2; i*i<=N; i++){
        if(sieve[i] == true){
            for(int j=i*i; j<=N; j+=i){
                sieve[j] = false;
            }
        }
    }
}

// create generatePrimes
vector<int> generatePrimes(int N){
    vector<int> ds;
    for(int i=2; i<=N; i++){
        if(sieve[i] == true){
            ds.push_back(i);
        }
    }
    return ds;
}

int main(){
    createSieve();
    int t;
    cin>>t;

    while(t--){
        int l, r;
        cin>>l>>r;
        // 1. generateprimes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));

        // 2. create dummy arr of size r-l+1, and mark all elems as 1
        int dummy[r-l+1];
        for(int i=0; i<r-l+1; i++){
            dummy[i] = 1;
        }

        // 3. mark all multiples of primes in dummy as 0
        for(auto pr : primes){
            int firstMultiple = (l/pr)*pr;
            if(firstMultiple < l)
                firstMultiple += pr;
            
            for(int j=max(firstMultiple, pr*pr); j<=r; j+=pr){
                dummy[j-l] = 0;
            }
        }

        // 4. get primes in the segment
        for(int i=l; i<=r; i++){
            if(dummy[i-l]==1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
*/