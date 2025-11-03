#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    long double p;
    cin >> n >> p;
    
    vector<pair<long double, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i + 1;
    }
    
    sort(c.begin(), c.end());
    
    long double min_diff = 1e18;
    int ans_i = -1, ans_j = -1;
    
    for (int j = 0; j < n; j++) {
        long double target = p * c[j].first;
        
        int pos = lower_bound(c.begin(), c.end(), make_pair(target, -1)) - c.begin();
        
        for (int k = max(0, pos - 2); k <= min(n - 1, pos + 2); k++) {
            if (k == j) continue;
            
            long double ratio = c[k].first / c[j].first;
            long double diff = fabsl(ratio - p);
            
            if (diff < min_diff) {
                min_diff = diff;
                ans_i = c[k].second;
                ans_j = c[j].second;
            }
        }
    }
    
    cout << ans_i << " " << ans_j << endl;
    
    return 0;
}
