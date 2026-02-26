#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

void jobScheduling(vector<Job> v){
    int cnt = 0;
    int maxProfit = 0;
    int n = v.size();

    int maxDeadline = 0;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, v[i].deadline);
    }

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < v.size(); i++){
        auto it = v[i];
        pq.push({it.profit, it.deadline});
    }

    vector<int> hash(maxDeadline, 0);

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        for(int i = it.second - 1; i >= 0; i--){
            if(hash[i] == 0){
                cnt++;
                maxProfit += it.first;
                hash[i] = 1;
                break;
            }
        }
    }

    cout << "Total number of jobs: " << cnt << "\n";
    cout << "MaxProfit: " << maxProfit << "\n";
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobScheduling(jobs);

    return 0;
}