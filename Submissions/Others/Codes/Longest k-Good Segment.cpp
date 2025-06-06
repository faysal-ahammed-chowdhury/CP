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

const int N = 5e5 + 9;
int n, k, a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  unordered_map<int, int, custom_hash> mp;
  unordered_set<int, custom_hash> se;
  int ans = 0, l, r;
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n and se.size() <= k) {
      if (se.size() == k and se.find(a[j]) == se.end()) break;
      se.insert(a[j]);
      mp[a[j]]++;
      j++;
    }
    if (j - i > ans) {
      l = i, r = j - 1;
      ans = j - i;
    }
    mp[a[i]]--;
    if (mp[a[i]] == 0) se.erase(a[i]);
  }
  cout << l << ' ' << r << '\n';

  return 0;
}