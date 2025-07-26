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

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 16, inf = 1e9;
int n, m, a[N], b[N];
gp_hash_table<int, vector<int>, custom_hash> mp;
int dp[(1 << N) + 5][N];
unordered_set<int, custom_hash> se;

int f(int mask, int i) {
  if (i > m) return 0;
  int &ans = dp[mask][i];
  if (~ans) return ans;
  ans = inf;
  for (auto cur_mask : mp[b[i]]) {
    bool all_ok = true;
    int new_mask = mask | cur_mask;
    if ((mask & cur_mask) == 0) {
      ans = min(ans, int(__builtin_popcount(cur_mask)) + f(new_mask, i + 1));
    }
  }
  return ans;
}

int cs;
void solve() {
  mp.clear();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    se.insert(b[i]);
  }

  for (int mask = 0; mask < (1 << (n)); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (CHECK(mask, i)) {
        sum += a[i];
      }
    }
    if (se.find(sum) != se.end()) mp[sum].push_back(mask);
  }
  
  memset(dp, -1, sizeof dp);
  int ans = f(0, 1);
  if (ans >= inf) ans = -1;
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}