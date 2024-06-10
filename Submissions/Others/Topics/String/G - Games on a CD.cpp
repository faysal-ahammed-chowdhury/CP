#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;

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
  int ip1 = power(p1, MOD1 - 2, MOD1);
  int ip2 = power(p2, MOD2 - 2, MOD2);
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
    assert(1 <= l && l <= r && r <= n);
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  int tot_string, k; cin >> tot_string >> k;
  string s; cin >> s;
  s += s.substr(0, k);
  int n = s.size();
  Hashing hs(s);

  int g; cin >> g;
  map<pair<int, int>, int> id;
  for (int i = 1; i <= g; i++) {
    string x; cin >> x;
    id[Hashing(x).get_hash()] = i;
  }

  for (int start = 1; start <= k; start++) {
    int cnt = 0;
    map<pair<int, int>, int> vis;
    vector<int> ans;
    for (int i = start; i + k - 1 <= n; i += k) {
      pair<int, int> cur = hs.get_hash(i, i + k - 1);
      if (id.find(cur) != id.end() and !vis[cur]) {
        vis[cur] = true;
        cnt++;
        ans.push_back(id[cur]);
      }
    }
    if (cnt == tot_string) {
      cout << "YES\n";
      for (auto x : ans) {
        cout << x << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}