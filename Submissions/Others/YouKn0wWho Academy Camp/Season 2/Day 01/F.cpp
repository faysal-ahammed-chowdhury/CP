#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int spf[N];

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

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

  int n, m; cin >> n >> m;
  unordered_set<int, custom_hash> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    while (x > 1) {
      se.insert(spf[x]);
      x /= spf[x];
    }
  }
  vector<int> ans;
  for (int i = 1; i <= m; i++) {
    int x = i;
    bool ok = true;
    while (x > 1) {
      if (se.find(spf[x]) != se.end()) {
        ok = false;
        break;
      }
      x /= spf[x];
    }
    if (ok) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << '\n';

  return 0;
}