#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N], p_sz[N];
int div_cnt[N];

void prec() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      div_cnt[j]++;
    }
  }
}

struct node {
  int sz, l, r;
};

struct ST {
  node tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n].sz == 0) return;
    tree[n].sz = lazy[n].sz;
    tree[n].l = lazy[n].l;
    tree[n].r = lazy[n].r;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n].sz = 0;
  }
  node merge(node L, node R) {
    if (L.sz == -1) return R;
    if (R.sz == -1) return L;
    L.sz = __gcd(L.sz, R.sz);
    L.r = R.r;
    return L;
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = {x, i, j};
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return { -1, -1, -1};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

void solve() {
  int q; cin >> n >> q;
  div_cnt[0] = n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int last = 1, cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      // cout << i << '\n';
      st.upd(1, 1, n, last, i - 1, cnt);
      // cout << last << ' ' << i - 1 << ' ' << cnt << '\n';
      last = i;
      cnt = 1;
    }
    else {
      cnt++;
    }
  }
  st.upd(1, 1, n, last, n, cnt);
  // cout << last << ' ' << n << ' ' << cnt << '\n';

  int last_sz = st.query(1, 1, n, n, n).sz;
  int ans = st.query(1, 1, n, 1, n - last_sz).sz;
  cout << (ans <= 0 ? n : div_cnt[ans]) << '\n';

  // for (int i = 1; i <= n; i++) {
  //   auto [sz, l, r] = st.query(1, 1, n, i, i);
  //   cout << i << ' ' << sz << ' ' << l << ' ' << r << '\n';
  // }
  // cout << '\n';
  // return;

  while (q--) {
    int i, v; cin >> i >> v;
    auto [sz, l, r] = st.query(1, 1, n, i, i);
    auto [szp, lp, rp] = st.query(1, 1, n, i - 1, i - 1);
    auto [szn, ln, rn] = st.query(1, 1, n, i + 1, i + 1);

    // assert(min({l, r, lp, rp, ln, rn, sz, szp, szn}) > 0);

    a[i] = v;
    int val = a[i];
    int val1 = a[i - 1];
    int val2 = a[i + 1];

    if (i == 1) {
      if (sz == 1) {
        if (val <= val2) {
          st.upd(1, 1, n, l, rn, sz + szn);
        }
      }
      else {
        if (val <= val2) {}
        else if (val > val2) {
          st.upd(1, 1, n, i, i, 1);
          st.upd(1, 1, n, i + 1, r, sz - 1);
        }
      }
    }
    else if (i == n) {
      if (sz == 1) {
        if (val >= val1) {
          st.upd(1, 1, n, lp, r, sz + szp);
        }
      }
      else {
        if (val >= val1) {}
        else if (val < val1) {
          st.upd(1, 1, n, l, i - 1, sz - 1);
          st.upd(1, 1, n, i, i, 1);
        }
      }
    }
    else {
      if (sz == 1) {
        if (val >= val1) {
          st.upd(1, 1, n, lp, r, sz + szp);
        }
        else if (val <= val2) {
          st.upd(1, 1, n, l, rn, sz + szn);
        }
      }
      else {
        if (i > l and i < r) {
          if (val >= val1 and val <= val2) {}
          else if (val >= val1 and val > val2) {
            st.upd(1, 1, n, l, i, i - l + 1);
            st.upd(1, 1, n, i + 1, r, r - (i + 1) + 1);
          }
          else if (val < val1 and val <= val2) {
            st.upd(1, 1, n, l, i - 1, (i - 1) - l + 1);
            st.upd(1, 1, n, i, r, r - i + 1);
          }
          else {
            st.upd(1, 1, n, l, i - 1, (i - 1) - l + 1);
            st.upd(1, 1, n, i, i, 1);
            st.upd(1, 1, n, i + 1, r, r - (i + 1) + 1);
          }
        }
        else {
          if (i == l) {
            if (val < val1 and val <= val2) {}
            else if (val >= val1 and val <= val2) {
              st.upd(1, 1, n, lp, r, szp + sz);
            }
            else if (val >= val1 and val > val2) {
              st.upd(1, 1, n, lp, i, szp + 1);
              st.upd(1, 1, n, i + 1, r, sz - 1);
            }
            else {
              st.upd(1, 1, n, i, i, 1);
              st.upd(1, 1, n, i + 1, r, sz - 1);
            }
          }
          else if (i == r) {
            // cout << val1 << ' ' << val << ' ' << val2 << '\n';
            if (val >= val1 and val > val2) {}
            else if (val >= val1 and val <= val2) {
              st.upd(1, 1, n, l, rn, sz + szn);
            }
            else if (val < val1 and val <= val2) {
              st.upd(1, 1, n, l, i - 1, sz - 1);
              st.upd(1, 1, n, i, rn, szn + 1);
            }
            else {
              st.upd(1, 1, n, l, i - 1, sz - 1);
              st.upd(1, 1, n, i, i, 1);
            }
          }
        }
      }
    }

    int last_sz = st.query(1, 1, n, n, n).sz;
    int ans = st.query(1, 1, n, 1, n - last_sz).sz;
    cout << (ans <= 0 ? n : div_cnt[ans]) << '\n';

    // for (int i = 1; i <= n; i++) {
    //   cout << st.query(1, 1, n, i, i).sz << ' ';
    // }
    // cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}