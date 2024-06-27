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

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = spf[x];
      while (x % p == 0) x /= p;
      mp[p]++;
    }
  }
  set<int> se;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x > 1) {
      int p = spf[x];
      while (x % p == 0) x /= p;
      mp[p]--;
      if (mp[p] == 0) se.erase(p);
      else se.insert(p);
    }
    if (se.size() == 0) {
      cout << i << '\n';
      return;
    }
  }
  assert(false);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}