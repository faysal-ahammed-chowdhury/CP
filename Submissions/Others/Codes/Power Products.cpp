#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int spf[N];

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n, k; cin >> n >> k;
  map<int, int> pf[n + 1];
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    while (x > 1) {
      int p = spf[x], pw = 0;
      while (x % p == 0) {
        x /= p;
        pw++;
      }
      pf[i][p] = pw;
    }
  }

  long long ans = 0;
  int one = 0, full = 0;
  map<map<int, int>, int> mp;
  for (int i = 1; i <= n; i++) {
    map<int, int> need, tmp;
    for (auto [p, pw] : pf[i]) {
      if (pw % k != 0) tmp[p] = pw % k;
      int x = k - (pw % k);
      if (x == k) x = 0;
      if (x == 0) continue;
      need[p] = x;
    }

    if (pf[i].size() == 0 or need.size() == 0) ans += full + one;
    else if (mp.find(need) != mp.end()) ans += mp[need];

    full += pf[i].size() != 0 and need.size() == 0;
    one += pf[i].size() == 0;
    mp[tmp]++;
  }
  cout << ans << '\n';

  return 0;
}