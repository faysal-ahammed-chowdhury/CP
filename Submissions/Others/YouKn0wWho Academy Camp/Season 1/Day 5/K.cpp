#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9, K = 1e4 + 9;
int spf[K];

void spf_sieve() {
  for (int i = 2; i < K; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < K; i++) {
    if (spf[i] == i) {
      for (int j = i; j < K; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

vector<int> get_fact(int n) {
  vector<int> v;
  while (n > 1) {
    v.push_back(spf[n]);
    n /= spf[n];
  }
  return v;
}

bitset<K> fact;
void add(int n) {
  vector<int> v = get_fact(n);
  for (auto x : v) {
    fact[x].flip();
  }
}

void erase(int n) {
  vector<int> v = get_fact(n);
  for (auto x : v) {
    fact[x].flip();
  }
}

bool check() {
  return fact.none();
}

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
const int p1 = 1e5 + 3, p2 = 1e6 + 3;
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
  vector<int> s;
  vector<pair<int, int>> hash_val;
  Hashing() {}
  Hashing(vector<int> _s) {
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();
  prec();

  int n, k; cin >> n >> k;
  int a[n + 1];
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vec.push_back(a[i]);
  }

  Hashing hash(vec);

  set<pair<int, int>> se;
  for (int i = 1; i <= n; i++) {
    add(a[i]);
    if (i > k) {
      erase(a[i - k]);
    }
    if (i >= k) {
      if (check()) {
        int l = i - k + 1, r = i;
        se.insert(hash.get_hash(l, r));
      } 
    }
  }

  cout << se.size() << '\n';

  return 0;
}