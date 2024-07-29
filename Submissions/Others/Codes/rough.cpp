#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];
int col[N], vis[N];


bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (is_prime(i ^ j)) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto u : g[i]) {
      cout << i << ' ' << u << '\n';
    }
  }
  // dfs(1);

  return 0;
}