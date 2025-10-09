#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, MAXV = 5e5 + 9, inf = 1e9;
vector<int> divs[MAXV];
int n, a[N], spf[MAXV], cost[MAXV];
int dp[N][205];

void sieve() {
  divs[1].push_back(1);
  for (int i = 2; i < MAXV; i++) {
    divs[i].push_back(1);
    spf[i] = i;
  }

  for (int i = 2; i < MAXV; i++) {
    for (int j = i; j < MAXV; j += i) {
      divs[j].push_back(i);
      if (spf[i] == i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int f(int i, int last) {
  if (i <= 0) {
    return 0;
  }

  int &ans = dp[i][last];
  if (ans != -1) return ans;

  int x = a[i + 1] / divs[a[i + 1]][last];
  // cout << i << ' ' << x << '\n';
  ans = inf;
  for (int j = 0; j < divs[a[i]].size(); j++) {
    if (a[i] / (divs[a[i]][j]) <= x) {
      ans = min(ans, cost[divs[a[i]][j]] + f(i - 1, j));
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 200; j++) {
      dp[i][j] = -1;
    }
  }
  cout << f(n - 1, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  // int mx = 0;
  // for (int i = 1; i < MAXV; i++) {
    // cout << i << ": ";
    // for (auto x : divs[i]) cout << x << ' '; cout << '\n';
    // mx = max(mx, (int)divs[i].size());
  // }
  // cout << mx << '\n';

  for (int i = 1; i < MAXV; i++) {
    int x = i;
    while (x > 1) {
      int p = spf[x], e = 0;
      while (x % p == 0) {
        e++;
        x /= p;
      }
      cost[i] += e;
    }
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}