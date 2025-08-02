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

const int N = 2e5 + 9, inf = 2e9;
pair<int, pair<int, int>> Q[N];
multiset<int> ms[N];

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int get_first(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree[n] <= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first(2 * n, b, tm, l, r, x);
    if (left != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r, x);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    string type; int x, y; cin >> type >> x >> y;
    int tmp = 2;
    if (type == "add") tmp = 0;
    else if (type == "remove") tmp = 1;
    Q[i] = {tmp, {x, y}};
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  gp_hash_table<int, int, custom_hash> mp;

  for (int i = 1; i <= n; i++) {
    auto &[_, p] = Q[i];
    auto &[x, y] = p;
    mp[lower_bound(v.begin(), v.end(), x) - v.begin() + 1] = x;
    x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  }

  st.build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    auto [type, p] = Q[i];
    auto [x, y] = p;
    if (type == 0) {
      ms[x].insert(y);
      auto it = ms[x].end();
      if (it != ms[x].begin()) {
        --it;
        st.upd(1, 1, n, x, *it);
      }
    }
    else if (type == 1) {
      ms[x].erase(ms[x].find(y));
      auto it = ms[x].end();
      if (it != ms[x].begin()) {
        --it;
        st.upd(1, 1, n, x, *it);
      }
      else {
        st.upd(1, 1, n, x, 0);
      }
    }
    else {
      int ans = st.get_first(1, 1, n, x + 1, n, y);
      if (ans == -1) cout << -1 << '\n';
      else {
        auto it = ms[ans].upper_bound(y);
        if (it == ms[ans].end()) cout << -1 << '\n';
        else cout << mp[ans] << ' ' << *it << '\n';
      }
    }
  }

  return 0;
}