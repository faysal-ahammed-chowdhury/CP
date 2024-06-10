#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, cs = 0;
  while(cin >> n >> m) {
    vector<bool> bad(10, false);
    while(m--) {
      int x; cin >> x;
      bad[x] = true;
    }

    queue<int> q;
    vector<int> vis(n, false), par(n), digit(n);
    for(int d = 1; d < 10; d++) {
      int x = d % n;
      if(!bad[d] and !vis[x]) {
        q.push(x);
        vis[x] = true;
        digit[x] = d;
        par[x] = -1;
      }
    }

    while(!q.empty()) {
      int x = q.front();
      q.pop();
      for(int d = 0; d < 10; d++) {
        int new_x = (x * 10 + d) % n;
        if(!bad[d] and !vis[new_x]) {
          q.push(new_x);
          vis[new_x] = true;
          digit[new_x] = d;
          par[new_x] = x;
        }
      }
    }

    cout << "Case " << ++cs << ": ";
    if(vis[0]) {
      vector<int> path;
      int cur = 0;
      while(cur != -1) {
        path.push_back(digit[cur]);
        cur = par[cur];
      }
      reverse(path.begin(), path.end());
      for(auto x: path) cout << x;
      cout << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }

  return 0;
}