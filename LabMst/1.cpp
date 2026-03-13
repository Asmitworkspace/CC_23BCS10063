#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &tokens, int power){
    sort(tokens.begin(), tokens.end());

    int score = 0;
    int ans = 0;
    int left = 0, right = tokens.size() - 1;

    while(left <= right){
        if(tokens[left] <= power){
            power -= tokens[left];
            score++;
            left++;
            ans = max(ans, score);
        }
        else if(score > 0){
            power += tokens[right];
            score--;
            right--;
        }
        else{
            break;
        }
    }

    return ans;
}

int main(){
    int power = 150;
    vector<int> tokens = {200,100};

    cout << maxScore(tokens,power) << endl;
}
