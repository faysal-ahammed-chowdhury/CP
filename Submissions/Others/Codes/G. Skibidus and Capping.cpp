#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int spf[N];
int n, a[N];

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
  cin >> n;
  map<int, int> prime_cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (spf[a[i]] == a[i]) prime_cnt[a[i]]++;
  }

  ll ans = 0;
  int x = 0;
  for (auto [p, cnt] : prime_cnt) {
    ans += 1ll * x * cnt;
    x += cnt;
  }

  map<int, int> mp;

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    mp[a[i]]++;
    int x = a[i];
    map<int, int> pf;
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        x /= p;
        ex++;
      }
      pf[x] = ex;
    }
    bool ok = true;
    if (pf.size() == 1) {
      for (auto [p, ex] : pf) {
        ok &= ex == 2;
      }
    }
    else if (pf.size() == 2) {
      for (auto [p, ex] : pf) {
        ok &= ex == 1;
      }
    }
    else ok = false;

    if (!ok) continue;
    x = a[i];
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        ans += mp[j];
        if (j != (x / j)) {
          ans += mp[x/ j];
        }
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}