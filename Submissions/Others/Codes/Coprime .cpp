#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

const int N = 1e6 + 9;
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n; cin >> n;
  int a[n + 1], gc = 0;
  gp_hash_table<int, int, custom_hash> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = spf[x];
      while (x % p == 0) {
        x /= p;
      }
      mp[p]++;
    }
    gc = __gcd(gc, a[i]);
  }

  bool ok = true;
  for (auto [p, cnt] : mp) {
    ok &= cnt == 1;
  }

  if (ok) cout << "pairwise coprime\n";
  else if (gc == 1) cout << "setwise coprime\n";
  else cout << "not coprime\n";

  return 0;
}