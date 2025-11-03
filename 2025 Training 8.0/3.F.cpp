#include<iostream>
#include<vector>
using namespace std;

int timer = 0;

void dfs(vector<vector<int>>& children, vector<int>& tin, vector<int>& tout, int node) {
    tin[node] = timer++;
    for (int child : children[node]) {
        dfs(children, tin, tout, child);
    }
    tout[node] = timer++;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> children(n + 1);
    int root = 0;
    
    for (int i = 1; i <= n; i++) {
        int parent;
        cin >> parent;
        if (parent == 0) {
            root = i;
        } else {
            children[parent].push_back(i);
        }
    }
    
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    
    dfs(children, tin, tout, root);
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (tin[a] <= tin[b] && tout[a] >= tout[b]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
