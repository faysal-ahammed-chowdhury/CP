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

const int N = 1e6 + 9, QQ = 1e6 + 9;
int a[N], ans[QQ];
vector<pair<int, int>> Q[QQ];

struct ST {
  int tree[4 * N];
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] ^ tree[r]; 
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L ^ R); 
  }
} st;

struct ST2 {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] ^ tree[r]; 
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L ^ R); 
  }
} st2;

int cs;
void solve() {
  int n; cin >> n;
  for (int i = 1; i < QQ; i++) {
    Q[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st2.build(1, 1, n);

  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }

  gp_hash_table<int, int, custom_hash> mp;
  for (int r = 1; r <= n; r++) {
    if (mp.find(a[r]) != mp.end()) {
      st.upd(1, 1, n, mp[a[r]], 0);
    }
    mp[a[r]] = r;
    st.upd(1, 1, n, r, a[r]);

    for (auto i : Q[r]) {
      int l = i.first, id = i.second;
      ans[id] = st.query(1, 1, n, l, r) ^ st2.query(1, 1, n, l, r);
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}