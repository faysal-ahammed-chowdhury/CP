#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9, MAXV = 5e5 + 9, inf = 1e9;
vector<int> divs[MAXV];
int n, a[N], spf[MAXV];

void sieve() {
  for(int i = 2; i < MAXV; i++) {
    spf[i] = i;
  }

  divs[1].push_back(1);
  for (int i = 2; i < MAXV; i++) {
    divs[i].push_back(1);
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

  int x = a[i + 1] / divs[a[i + 1]][last];
  int ans = inf;
  for (int j = 0; j < divs[a[i]].size(); j++) {
    if (a[i] / (divs[a[i]][j]) <= x) {
      ans = min(ans, f(i - 1, j));
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << f(n - 1, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int mx = 1;
  for (int i = 1; i < MAXV; i++) {
    mx = max(mx, (int)divs[i].size());
    cout << spf[i] << '\n';
  }

  cout << mx << '\n';

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}