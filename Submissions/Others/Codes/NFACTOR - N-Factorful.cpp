#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int spf[N];
vector<int> factor_cnt[15];

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void solve() {
  int a, b, n; cin >> a >> b >> n;
  int ans = upper_bound(factor_cnt[n].begin(), factor_cnt[n].end(), b) - lower_bound(factor_cnt[n].begin(), factor_cnt[n].end(), a);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  for (int i = 1; i < N; i++) {
    int x = i, cnt = 0;
    while (x > 1) {
      cnt++;
      int p = spf[x];
      while (x % p == 0) {
        x /= p;
      }
    }

    factor_cnt[cnt].push_back(i);
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}