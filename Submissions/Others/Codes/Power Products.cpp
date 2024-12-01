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

  // for (int i = 1; i <= n; i++) {
  //   cout << i << ":\n";
  //   for (auto [p, pw] : pf[i]) {
  //     cout << p << '^' << pw << '\n';
  //   }
  //   cout << '\n';
  // }

  long long ans = 0, full = 0;
  int one = 0;
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

    long long cur = 0;
    if (pf[i].size() == 0 or need.size() == 0) cur += full + one;
    else if (mp.find(need) != mp.end()) cur += mp[need];
    
    if (pf[i].size() != 0 and need.size() == 0) full++;
    ans += cur;
    mp[tmp]++;
    one += pf[i].size() == 0;
  }
  cout << ans << '\n';

  return 0;
}