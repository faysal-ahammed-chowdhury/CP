#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 250000 + 9;

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
const int p1 = 137, p2 = 277; // change here
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
  int n, q; cin >> n >> q;
  int pref[n + 1];
  memset(pref, 0, sizeof pref);
  string s = "";
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    pref[i] = pref[i - 1] + x;
    if (x == 1) s += '1';
    else s += '0';
  }

  string t1 = "", t2 = "";
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      t1 += "1";
      t2 += "0";
    }
    else {
      t1 += "0";
      t2 += "1";
    }
  }

  Hashing hash1(s);
  Hashing hash2(t1);
  Hashing hash3(t2);

  while (q--) {
    int l, r; cin >> l >> r;
    int sz = r - l + 1;
    int cnt1 = pref[r] - pref[l - 1];
    int cnt0 = sz - cnt1;
    if (cnt0 % 3 != 0 or cnt1 % 3 != 0) {
      cout << "-1\n";
      continue;
    }
    int ans = sz / 3;
    if (hash1.get_hash(l, r) == hash2.get_hash(1, sz) or hash1.get_hash(l, r) == hash3.get_hash(1, sz)) {
      ans++;
    }

    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}