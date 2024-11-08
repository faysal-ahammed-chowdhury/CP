#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 9;
int cur_idx;

struct ST {
  pair<int, int> tree[4 * (N)];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].first = 0;
      tree[n].second = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
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
    tree[n].second = tree[l].second + tree[r].second;
  }
  pair<int, int> query(int n, int b, int e, int x) {
    if (b > e) return { -1, -1};
    if (tree[n].second < x) return {tree[n].second, -1};
    if (b == e) {
      cur_idx = b;
      return tree[n];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, x);
    if (L.second != -1) return L;
    pair<int, int> R = query(r, mid + 1, e, x - L.first);
    return R;
  }

  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n].second;
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); 
  }
} st;


int cs;
void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    st.upd(1, 1, n, i, a[i], 1);
  }


  int sz = n;

  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int i, x; cin >> i >> x;
    i++;

    cur_idx = 0;
    st.query(1, 1, n, i);
    int idx2 = cur_idx;

    cur_idx = 0;
    int idx1 = 0;
    st.query(1, 1, n, i - 1);
    if (i - 1 >= 1) idx1 = cur_idx;

    cur_idx = 0;
    int idx3 = 0;
    st.query(1, 1, n, i + 1);
    if (i + 1 <= st.query(1, 1, n, 1, n)) idx3 =  cur_idx;
    
    // cout << idx1 << ' ' << idx2 << ' ' << idx3 << '\n';

    a[idx2] = x;
    if (x == a[idx1] and x == a[idx3] and idx1 != idx2 and idx2 != idx3) {
      st.upd(1, 1, n, idx1, 0, 0);
      st.upd(1, 1, n, idx3, 0, 0);
    }
    else if (x == a[idx1] and idx2 != idx1) {
      st.upd(1, 1, n, idx2, 0, 0);
    }
    else if (x == a[idx3] and idx2 != idx3) {
      st.upd(1, 1, n, idx2, 0, 0);
    }
    cout << st.query(1, 1, n, 1, n) << '\n';
  }
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