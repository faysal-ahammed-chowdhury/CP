#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9, inf = 1e9;
vector<int> divs[N];
set<int> se;
int dp[N];

void sieve() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

int f(int x) {
  if (x == 1) return 0;

  int &ans = dp[x];
  if (ans != -1) return ans;
  ans = inf;
  for (auto d : divs[x]) {
    if (se.find(d) != se.end()) {
      ans = min(ans, 1 + f(x / d));
    }
  }

  return ans;
}

void solve() {
  se.clear();
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
    dp[i] = -1;
  }

  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (se.find(1) != se.end()) cout << 1 << ' ';
      else cout << -1 << ' ';
    }
    else {
      int ans = f(i);
      if (ans >= inf) ans = -1;
      cout << ans << ' ';
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}