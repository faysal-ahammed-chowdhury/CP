#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N];
int deg[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    deg[i] = 0;
    g[i].clear();
  }
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    s = '.' + s;
    for (int j = i + 1; j <= n; j++) {
      if (s[j] == '1') {
        g[i].push_back(j);
        deg[j]++;
      }
    }
  }

  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) pq.push(i);
  }

  while (!pq.empty()) {
    int x = pq.top();
    pq.pop();
    cout << x << ' ';
    for (auto v : g[x]) {
      deg[v]--;
      if (deg[v] == 0) {
        pq.push(v);
      }
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}