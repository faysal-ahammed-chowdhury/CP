#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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

const int N = 1e5 + 9, B = 200;

struct query {
  int l, r, k, id;
  bool operator < (const query &x) const {
    if (l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];
int a[N];

void phi_1_to_n(int n) {
  for (int i = 0; i <= n; i++)
    a[i] = i;

  for (int i = 2; i <= n; i++) {
    if (a[i] == i) {
      for (int j = i; j <= n; j += i)
        a[j] -= a[j] / i;
    }
  }
}

gp_hash_table<int, int, custom_hash> mp;
o_set<int> se;
inline void add_left(int i) {
  mp[a[i]]++;
  se.insert(a[i]);
}
inline void add_right(int i) {
  mp[a[i]]++;
  se.insert(a[i]);
}
inline void rem_left(int i) {
  mp[a[i]]--;
  if (mp[a[i]] == 0) se.erase(a[i]);
}
inline void rem_right(int i) {
  mp[a[i]]--;
  if (mp[a[i]] == 0) se.erase(a[i]);
}

int ans[N];

int cs;
void solve() {
  mp.clear();
  se.clear();

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> Q[i].l >> Q[i].r >> Q[i].k;
    Q[i].id = i;
  }
  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r, K = Q[i].k;
    if (R < l) {
      while (l > L) add_left(--l);
      while (l < L) rem_left(l++);
      while (r < R) add_right(++r);
      while (r > R) rem_right(r--);
    } else {
      while (r < R) add_right(++r);
      while (r > R) rem_right(r--);
      while (l > L) add_left(--l);
      while (l < L) rem_left(l++);
    }
    if (se.size() < K) ans[Q[i].id] = -1;
    else ans[Q[i].id] = *se.find_by_order(K - 1);
  }

  cout << "Case " << ++cs << ":\n";
  for (int i = 1; i <= q; i++) {
    if (ans[i] == -1) cout << "No Distinct Phi Number\n";
    else cout << ans[i] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  phi_1_to_n(N - 2);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}