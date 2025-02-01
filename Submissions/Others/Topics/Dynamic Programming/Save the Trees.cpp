#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 2e5 + 9, inf = 1e18;
int a[N], b[N], n, lft_idx[N], dp[N];
map<int, int> last_pos;

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += lazy[n]; 
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n]; 
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]); 
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] += x; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = min(tree[l], tree[r]); 
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return inf;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st1, st2;

int cs;
void solve() {
  last_pos.clear();

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    if (last_pos.find(a[i]) == last_pos.end()) lft_idx[i] = 1;
    else lft_idx[i] = last_pos[a[i]] + 1;
    lft_idx[i] = max(lft_idx[i], lft_idx[i - 1]);
    last_pos[a[i]] = i;
  }

  st1.build(1, 1, n);
  st2.build(1, 1, n);
  memset(dp, 0, sizeof dp);
  stack<pair<int, int>> stk;
  stk.push({inf, 0});

  for (int i = 1; i <= n; i++) {
    int x = b[i];
    int lft = lft_idx[i];
    // cout << lft << '\n';
    int pos = i;
    // cout << i << '\n';
    while (!stk.empty() and stk.top().second >= lft and stk.top().first <= x) {
      int mx = st2.query(1, 1, n, stk.top().second + 1, pos);
      // cout << stk.top().second + 1 << ' ' << pos << ' ' << mx << '\n';
      st2.upd(1, 1, n, stk.top().second + 1, pos, -mx);
      st2.upd(1, 1, n, stk.top().second + 1, pos, x);
      st1.upd(1, 1, n, stk.top().second + 1, pos, -mx);
      st1.upd(1, 1, n, stk.top().second + 1, pos, x);

      pos = stk.top().second;
      stk.pop();
    }
    int mx = st2.query(1, 1, n, stk.top().second + 1, pos);
    // cout << stk.top().second + 1 << ' ' << pos << ' ' << mx << ' ' << x << '\n';
    st2.upd(1, 1, n, stk.top().second + 1, pos, -mx);
    st2.upd(1, 1, n, stk.top().second + 1, pos, x);
    st1.upd(1, 1, n, stk.top().second + 1, pos, -mx);
    st1.upd(1, 1, n, stk.top().second + 1, pos, x);

    stk.push({x, i});
    dp[i] = st1.query(1, 1, n, lft, i);
    if (i + 1 <= n) st1.upd(1, 1, n, i + 1, i + 1, dp[i]);
  }

  cout << "Case " << ++cs << ": " << dp[n] << '\n';
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