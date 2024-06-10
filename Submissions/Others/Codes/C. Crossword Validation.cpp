#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(pair<int, int> x) const { return x.first ^ x.second ^ RANDOM; }
};

const int N = 1005;

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1ll * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1ll * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1ll * ipw[i - 1].second * ip2 % MOD2;
  }
}

struct Hashing {
  int n;
  string s;
  vector<pair<int, int>> hash_val;
  Hashing() {}
  Hashing(string _s) {
    s = _s;
    n = s.size();
    hash_val.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hash_val[i].first + 1ll * s[i] * pw[i].first % MOD1) % MOD1;
      p.second = (hash_val[i].second + 1ll * s[i] * pw[i].second % MOD2) % MOD2;
      hash_val.push_back(p);
    }
  }

  pair<int, int> get_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
};

void solve() {
  int n, m; cin >> n >> m;
  char a[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  gp_hash_table<pair<int, int>, int, chash> mp;

  while (m--) {
    string s; int k; cin >> s >> k;
    Hashing hs(s);
    mp[hs.get_hash()] = k;
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    string s = "";
    for (int j = 1; j <= n + 1; j++) {
      if ((a[i][j] == '#' or j == n + 1) and s != "") {
        Hashing hs(s);
        if (mp.find(hs.get_hash()) == mp.end()) {
          cout << -1 << '\n';
          return;
        }
        ans += mp[hs.get_hash()];
        s = "";
      }
      else if (a[i][j] != '#') {
        s += a[i][j];
      }
    }
  }

  for (int j = 1; j <= n; j++) {
    string s = "";
    for (int i = 1; i <= n + 1; i++) {
      if ((a[i][j] == '#' or i == n + 1) and s != "") {
        Hashing hs(s);
        if (mp.find(hs.get_hash()) == mp.end()) {
          cout << -1 << '\n';
          return;
        }
        ans += mp[hs.get_hash()];
        s = "";
      }
      else if (a[i][j] != '#') {
        s += a[i][j];
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}