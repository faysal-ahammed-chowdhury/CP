#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];
vector<int> indeg(N, 0);

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while(cin >> n >> m and !(n == 0 and m == 0)) {
    while(m--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      indeg[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
      if(indeg[i] == 0) {
        q.push(i);
      }
    }

    vector<int> ans;
    while(!q.empty()) {
      int top = q.front();
      q.pop();
      ans.push_back(top);
      for(auto v: g[top]) {
        indeg[v]--;
        if(indeg[v] == 0) {
          q.push(v);
        }
      }
    }

    for(auto i: ans) {
      cout << i << ' ';
    }
    cout << '\n';

    for(int i = 1; i <= n; i++) {
      g[i].clear();
      indeg[i] = 0;
    }
  }

  return 0;
}