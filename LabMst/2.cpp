#include<bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int>&arr){
    int ans = 0;
    for(int i=0;i<32;i++){
        int count =0;
        for(int j=0;j<arr.size();j++){
            if((arr[j]>>i)&1){
                count++;
            }
        }
        if(count%3!=0){
            ans = ans | (1<<i);
        }
    }
    return ans;
}

int main(){
    vector<int>nums={2,2,3,2};
    cout<<uniqueElement(nums);
}
