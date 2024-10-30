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

const int N = 5e5 + 9;
int a[N];
gp_hash_table<int, vector<int>, custom_hash> mp;

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  int get_first(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree[n] >= x) return -1;

    if (b == e) return b;

    int mid = b + (e - b) / 2;
    int left = get_first(2 * n, b, mid, l, r, x);
    if (left != -1) return left;
    return get_first(2 * n + 1, mid + 1, e, l , r, x);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  mp[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
    mp[a[i]].push_back(i);
  }

  st.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    int tmp = st.get_first(1, 1, n, l, r, a[l - 1]);
    r = (tmp > 0 ? tmp : r);
    // cout << r << '\n';

    auto it = --upper_bound(mp[a[l - 1]].begin(), mp[a[l - 1]].end(), r);
    int ans = *(it) - l + 1;
    cout << ans << '\n';
  }

  return 0;
}