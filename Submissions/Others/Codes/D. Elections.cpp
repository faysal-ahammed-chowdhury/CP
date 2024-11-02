#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, K = 20;
int n, c, a[N], tree[N][K], sorted_idx[N];
pair<int, int> sorted[N];
ll psum[N];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = max(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}
int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]);
};

struct ST {
  pair<ll, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  void upd(int n, int b, int e, int i, int x1, int x2) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].first = x1;
      tree[n].second = x2;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x1, x2);
    upd(r, mid + 1, e, i, x1, x2);
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  pair<ll, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<ll, int> L = query(l, b, mid, i, j);
    pair<ll, int> R = query(r, mid + 1, e, i, j);
    return {(L.first + R.first), (L.second + R.second)};
  }
} st;

bool ok(int i, int need) {
  return st.query(1, 1, n, 1, i).first >= need;
}

void solve() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) a[i] += c;
    sorted[i] = {a[i], i};
    psum[i] = psum[i - 1] + a[i];
  }
  build(n);

  sort(sorted + 1, sorted + n + 1);
  for (int i = 1; i <= n; i++) {
    int idx = lower_bound(sorted, sorted + n + 1, make_pair(a[i], i)) - sorted;
    sorted_idx[i] = n - idx + 1;
  }

  st.build(1, 1, n);
  int ans[n + 1];

  for (int i = n; i >= 1; i--) {
    int mx1 = 0, mx2 = 0;
    if (i > 1) mx1 = max(mx1, query(1, i - 1));
    if (i < n) mx2 = max(mx2, query(i + 1, n));
    int mx = max(mx1, mx2);
    if (a[i] > mx1 and a[i] >= mx2) {
      ans[i] = 0;
      st.upd(1, 1, n, sorted_idx[i], a[i], 1);
      continue;
    }

    ll got = psum[i - 1];
    int cur = i - 1;
    ll need = mx - a[i] - got;

    if (need > 0) {
      int l = 1, r = n, x = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid, need)) {
          x = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      cur += st.query(1, 1, n, 1, x).second;
    }
    ans[i] = cur;
    st.upd(1, 1, n, sorted_idx[i], a[i], 1);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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