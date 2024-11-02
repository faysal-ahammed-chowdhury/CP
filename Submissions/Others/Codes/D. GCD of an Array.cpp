#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 1e9 + 7;
multiset<int> pw[N];
map<int, int> pf[N];
int spf[N];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

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


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n, q; cin >> n >> q;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ans = __gcd(ans, x);
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      pf[i][p] = ex;
      pw[p].insert(ex);
    }
  }

  while (q--) {
    int i, x; cin >> i >> x;
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      int old_mn_pw = (pw[p].size() == n ? *pw[p].begin() : 0);
      int old_ex = (pf[i].find(p) == pf[i].end() ? 0 : pf[i][p]);
      // cout << old_ex << '\n';
      // for (auto val : pw[p]) cout << val << ' '; cout << '\n';
      if (old_ex > 0) pw[p].erase(pw[p].find(old_ex));
      // for (auto val : pw[p]) cout << val << ' '; cout << '\n';
      pf[i][p] += ex;
      int new_ex = pf[i][p];
      pw[p].insert(new_ex);
      // for (auto val : pw[p]) cout << val << ' '; cout << '\n';
      int new_mn_pw = (pw[p].size() == n ? *pw[p].begin() : 0);
      int d = new_mn_pw - old_mn_pw;
      ans = 1ll * ans * power(p, d, mod) % mod;
    }
    cout << ans << '\n';
  }

  return 0;
}