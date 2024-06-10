#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

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
  int n; cin >> n;
  string s[3];
  for (int i = 1; i <= 2; i++) {
    cin >> s[i];
  }


  string ans = "";
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (s[1][i] == '0') {
      ans += '0';
    }
    else if (i != 0 and s[2][i - 1] == '0') {
      idx = i - 1;
      break;
    }
    else {
      ans += '1';
    }
  }

  if (idx == -1) idx = n - 1;

  for (int i = idx; i < n; i++) {
    ans += s[2][i];
  }

  string s2 = s[2];
  Hashing hs1(ans);
  Hashing hs2(s2);

  int len = 1;
  if (idx == n - 1) {
    idx--;
  }
  for (int i = 0; i <= idx; i++) {
    if (i != n - 1 and s[1][i + 1] == s[2][i]) {
      if (hs1.get_hash(i + 2, n + 1) == hs2.get_hash(i + 1, n)) {
        len++;
      }
    }
  }
  cout << ans << '\n';
  cout << len << '\n';
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