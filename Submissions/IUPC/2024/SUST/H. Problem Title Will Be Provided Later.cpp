#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int n, a[N], pref1[N], pref2[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {pref1[b], pref1[b]};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = max(tree[l].first, tree[r].first);
    tree[n].second = min(tree[l].second, tree[r].second);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -1e9, 1e9};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {max(L.first, R.first), min(L.second, R.second)};
  }
} st1;

struct ST2 {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {pref2[b], pref2[b]};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = max(tree[l].first, tree[r].first);
    tree[n].second = min(tree[l].second, tree[r].second);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -1e9, 1e9};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {max(L.first, R.first), min(L.second, R.second)};
  }
} st2;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<pair<int, int>> st;
  int right[n + 1];
  for (int i = 1; i <= n; i++) {
    while (!st.empty() and st.top().first < a[i]) {
      right[st.top().second] = i - 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    right[st.top().second] = n;
    st.pop();
  }

  int left[n + 1];
  for (int i = n; i >= 1; i--) {
    while (!st.empty() and st.top().first < a[i]) {
      left[st.top().second] = i + 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    left[st.top().second] = 1;
    st.pop();
  }

  pref1[0] = 0, pref1[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    pref1[i] = pref1[i - 1] + a[i];
  }

  pref2[0] = 0, pref2[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    pref2[i] = pref2[i + 1] + a[i];
  }

  st1.build(1, 1, n);
  st2.build(1, 1, n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      int l = left[i];
      int r = right[i];
      int mx1 = st2.query(1, 1, n, l, i).first;
      mx1 -= pref2[i];
      int mx2 = st1.query(1, 1, n, i, r).first;
      mx2 -= pref1[i];
      int x = a[i] * (a[i] + mx1 + mx2);
      ans = max(ans, x);
    }
    else if (a[i] < 0) {
      int l = left[i];
      int r = right[i];
      int mx1 = st2.query(1, 1, n, l, i).second;
      mx1 -= pref2[i];
      int mx2 = st1.query(1, 1, n, i, r).second;
      mx2 -= pref1[i];
      int x = a[i] * (a[i] + mx1 + mx2);
      ans = max(ans, x);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}