#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int a[N];

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
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] += x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int get_first(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return -1;
    if (tree[n] < x) return -1;


    if (b == e) return b;

    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int left = get_first(l, b, mid, i, j, x);
    if (left != -1) return left;
    return get_first(r, mid + 1, e, i , j, x);
  }
} st;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  for (int i = 1; i <= m; i++) {
    int room; cin >> room;
    int idx = st.get_first(1, 1, n, 1, n, room);
    if (idx == -1) idx = 0;
    else st.upd(1, 1, n, idx, -room);
    cout << idx << ' ';
  }
  cout << '\n';

  return 0;
}