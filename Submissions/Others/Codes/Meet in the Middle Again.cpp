#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

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

void fun (int i, int a[], int n, vector<ll> &v, ll sum) {
  if (i == n) {
    v.push_back(sum);
    return;
  }
  fun(i + 1, a, n, v, sum);
  fun(i + 1, a, n, v, sum + a[i]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int x = n / 2;
  int y = n - x;

  int a[x], b[y];
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < y; i++) {
    cin >> b[i];
  }

  vector<ll> v1, v2;
  fun(0, a, x, v1, 0);
  fun(0, b, y, v2, 0);

  gp_hash_table<ll, int, custom_hash> mp;
  for (auto val : v1) {
    mp[val]++;
  }

  ll ans = 0;
  for (auto val : v2) {
    ll need = k - val;
    ans += mp[need];
  }

  cout << ans << '\n';

  return 0;
}