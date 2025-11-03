#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> events;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});     
        events.push_back({r + 1, -1});
    }
    
    sort(events.begin(), events.end());
    vector<ll> weight(n + 2, 0);
    int event_ptr = 0;
    int active_routes = 0;
    for (int pos = 1; pos <= n; pos++) {
        while (event_ptr < events.size() && events[event_ptr].first == pos) {
            active_routes += events[event_ptr].second;
            event_ptr++;
        }
        weight[pos] = active_routes;
    }
    vector<pair<ll, ll>> segments;
    for (int i = 1; i <= n; i++) {
        segments.push_back({weight[i], a[i]});
    }
    sort(segments.begin(), segments.end(), [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
        return x.first > y.first;
    });
    ll total_discomfort = 0;
    for (int i = 1; i <= n; i++) {
        total_discomfort += a[i] * weight[i];
    }
    for (auto& seg : segments) {
        ll w = seg.first;
        ll bumps = seg.second;
        if (w == 0) break; 
        ll repair = min(bumps, k);
        total_discomfort -= repair * w;
        k -= repair;
        
        if (k == 0) break;
    }
    
    cout << total_discomfort << endl;
    
    return 0;
}
