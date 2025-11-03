#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> data(n);
    for (int i = 0; i < n; i++) cin >> data[i].first;
    for (int i = 0; i < n; i++) cin >> data[i].second;
    sort(data.begin(), data.end());
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + data[i].second;
    }
    ll total_weight = prefix_sum[n];
    int idx = 0;
    while (idx < n && prefix_sum[idx + 1] * 2 < total_weight) {
        idx++;
    }
    ll best_e = data[idx].first;
    if (idx > 0) {
        ll cost1 = 0, cost2 = 0;
        for (int i = 0; i < n; i++) {
            cost1 += abs(best_e - data[i].first) * data[i].second;
            cost2 += abs(data[idx-1].first - data[i].first) * data[i].second;
        }
        if (cost2 <= cost1) {
            best_e = data[idx-1].first;
        }
    }
    ll total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += abs(best_e - data[i].first) * data[i].second;
    }
    
    cout << best_e << " " << total_cost << endl;
    
    return 0;
}
