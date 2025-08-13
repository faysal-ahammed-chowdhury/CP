#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 50, inf = 1e9;
int n, k, a[N], missing_cnt[N];
int freq[N];
vector<int> v;
int sz;

struct ST {
  array<int, 2> tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n][0] = tree[l][0] + tree[r][0];
    tree[n][1] = tree[l][1] + tree[r][1];
  }
  void upd(int n, int b, int e, int i) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n][0] += b;
      tree[n][1]++;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i);
    upd(r, mid + 1, e, i);
    tree[n][0] = tree[l][0] + tree[r][0];
    tree[n][1] = tree[l][1] + tree[r][1];
  }
  array<int, 2> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    array<int, 2> L = query(l, b, mid, i, j);
    array<int, 2> R = query(r, mid + 1, e, i, j);
    return {L[0] + R[0], L[1] + R[1]};
  }
  pair<int, int> get_first(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return {-1, -1};
    if (tree[n][0] <= x) {
      return {tree[n][0], -1};
    }

    if (b == e) return {tree[n][0], b};

    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> left = get_first(l, b, mid, i, j, x);
    if (left.second != -1) return left;
    return get_first(r, mid + 1, e, i , j, x - left.first);
  }
} st;

int f(int mex) {
  if (max(missing_cnt[mex], freq[mex]) > k) return inf;
  int extra = k - freq[mex];

  auto idx = st.get_first(1, 1, sz, 1, sz, extra).second;
  if (idx == -1) return 0;


  auto tmp1 = st.query(1, 1, sz, 1, idx - 1);
  int tot = tmp1[1];
  int baki = extra - tmp1[0];
  // assert(baki >= 0);
  auto tmp2 = st.query(1, 1, sz, idx, idx);
  int val = tmp2[1];
  tot += min(val, baki / idx);

  int ase = st.query(1, 1, sz, 1, sz)[1];
  // assert(ase >= tot);
  // cout << ase << '\n';

  return ase - tot;
}

void solve() {
  v.clear();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] >= n + 5) v.push_back(a[i]);
  }
  sort(a + 1, a + n + 1);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 0; i <= sz; i++) {
    freq[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] >= (n + 5)) {
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + (n + 5);
    }
    freq[a[i]]++;
  }

  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    missing_cnt[i] = cnt;
    if (freq[i] == 0) cnt++;
  }

  sz = n + n + 10;
  st.build(1, 1, sz);
  for (int i = n + n + 10; i > n; i--) {
    st.upd(1, 1, sz, freq[i]);
  }

  int ans = inf;
  for (int mex = n; mex >= 0; mex--) {
    ans = min(ans, f(mex));
    // cout << mex << ' ' << f(mex) << '\n';
    st.upd(1, 1, sz, freq[mex]);
  }

  cout << ans << '\n';
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