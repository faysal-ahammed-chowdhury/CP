#include <bits/stdc++.h>
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1];
  unordered_map<int, int, custom_hash> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp1[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    int x = b[i];
    mp2[(i + n) - mp1[x]]++;
    mp2[i - mp1[x]]++;
  }

  int ans = 0;
  for (auto [d, cnt] : mp2) {
    ans = max(ans, cnt);
  }

  cout << ans << '\n';

  return 0;
}