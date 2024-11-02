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

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 9;
int ans[N];

void prec() {
  gp_hash_table<int, int, custom_hash> mp;
  o_set<int> se;
  int n = 1429431;
  for (int i = 1, x = 1; i <= n; i++, x += 2) {
    mp[i] = x;
    se.insert(i);
  }
  ans[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    int x = *se.find_by_order(i - 1);
    ans[i] = mp[x];
    for (int j = mp[x], jj = 0; j <= n; j += mp[x], jj++) {
      int y = *se.find_by_order((j - jj) - 1);
      se.erase(y);
    }
  }

}

int cs;
void solve() {
  int n; cin >> n;
  cout << "Case " << ++cs << ": " << ans[n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}