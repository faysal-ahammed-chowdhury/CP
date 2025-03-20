#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9; 
int a[N];

struct ST {
  pair<ll, int> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = tree[l].first + tree[r].first; 
    tree[n].second = tree[l].second + tree[r].second; 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n].first += x;
      tree[n].second += 1; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n].first = tree[l].first + tree[r].first; 
    tree[n].second = tree[l].second + tree[r].second; 
  }
  pair<ll, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, 0}; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<ll, int> L = query(l, b, mid, i, j);
    pair<ll, int> R = query(r, mid + 1, e, i, j);
    return {L.first + R.first, L.second + R.second};
  }
} st;

void solve() {
  int n, m; cin >> n >> m;
  int a[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    int need = n - a[i];
    need = max(need, 1);
    auto [sum, cnt] = st.query(1, 1, n, need, n);
    ans += sum - (1ll * cnt * need);
    // cout << sum - (1ll * cnt * need) << '\n';
    st.upd(1, 1, n, a[i], min(n, a[i] + 1));
  }
  ans *= 2;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}