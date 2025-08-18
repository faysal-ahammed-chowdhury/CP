#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, K = 26;
string s;

int f(char c) {
  return c - 'a';
}

struct node {
  int freq[K];
  bool lazy_on;
  bool is_ascending;
};

node merge(node &l, node &r) {
  node tmp;
  for (int j = 0; j < K; j++) {
    tmp.freq[j] = l.freq[j] + r.freq[j];
  }
  return tmp;
}

struct ST {
  node tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n].lazy_on == false) return;

    // cout << "here: " << n << ' ' << b << ' ' << e << '\n';
    // cout << lazy[n].freq[0] << ' ' << lazy[n].freq[1] << ' ' << lazy[n].freq[2] << '\n';

    tree[n] = lazy[n];
    if (b != e) {
      int mid = (b + e) >> 1, l = n << 1, r = l + 1;
      int len1 = (mid - b + 1);
      int len2 = (e - (mid + 1) + 1);

      for (int j = 0; j < K; j++) {
        lazy[l].freq[j] = 0;
        lazy[r].freq[j] = 0;
      }

      if (lazy[n].is_ascending) {
        lazy[l].is_ascending = true;
        lazy[r].is_ascending = true;

        int cnt = 0;
        for (int j = 0; j < K; j++) {
          if (cnt + lazy[n].freq[j] <= len1) {
            cnt += lazy[n].freq[j];
            lazy[l].freq[j] = lazy[n].freq[j];
          }
          else {
            int need = len1 - cnt;
            lazy[l].freq[j] = need;

            lazy[r].freq[j] = lazy[n].freq[j] - need;
            cnt = lazy[r].freq[j];
            for (int jj = j + 1; jj < K; jj++) {
              cnt += lazy[n].freq[jj];
              lazy[r].freq[jj] = lazy[n].freq[jj];
            }


            break;
          }
        }
      }
      else {
        lazy[l].is_ascending = false;
        lazy[r].is_ascending = false;

        int cnt = 0;
        for (int j = K - 1; j >= 0; j--) {
          if (cnt + lazy[n].freq[j] <= len1) {
            cnt += lazy[n].freq[j];
            lazy[l].freq[j] = lazy[n].freq[j];
          }
          else {
            int need = len1 - cnt;
            lazy[l].freq[j] = need;

            lazy[r].freq[j] = lazy[n].freq[j] - need;
            cnt = lazy[r].freq[j];
            for (int jj = j - 1; jj >= 0; jj--) {
              cnt += lazy[n].freq[jj];
              lazy[r].freq[jj] = lazy[n].freq[jj];
            }

            break;
          }
        }
      }

      lazy[l].lazy_on = true;
      lazy[r].lazy_on = true;
    }

    lazy[n].lazy_on = false;
  }
  void build(int n, int  b, int e) {
    lazy[n].lazy_on = false;
    for (int j = 0; j < K; j++) {
      lazy[n].freq[j] = 0;
    }
    if (b == e) {
      for (int j = 0; j < K; j++) {
        tree[n].freq[j] = 0;
      }
      tree[n].freq[f(s[b])]++;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, node x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      // cout << "ere: " << b << ' ' << e << '\n';
      // cout << x.freq[0] << ' ' << x.freq[1] << ' ' << x.freq[2] << '\n';
      // for (int j = 0; j < K; j++) {
      //   cout << x.freq[j] << ' ';
      // }
      // cout << '\n';

      node tmp = x;
      for (int j = 0; j < K; j++) {
        tmp.freq[j] = 0;
      }

      if (x.is_ascending) {
        tmp.is_ascending = true;
        int cnt = 0, len = e - b + 1;
        for (int j = 0; j < K; j++) {
          if (cnt + x.freq[j] <= (b - i)) {
            cnt += x.freq[j];
          }
          else {
            int nibo = min(len, x.freq[j] - ((b - i) - cnt));
            tmp.freq[j] = nibo;

            for (int jj = j + 1; jj < K; jj++) {
              if (nibo + x.freq[jj] <= len) {
                tmp.freq[jj] = x.freq[jj];
                nibo += x.freq[jj];
              }
              else {
                int need = len - nibo;
                tmp.freq[jj] = need;
                break;
              }
            }

            break;
          }
        }
      }
      else {
        tmp.is_ascending = false;
        int cnt = 0, len = e - b + 1;
        for (int j = K - 1; j >= 0; j--) {
          if (cnt + x.freq[j] <= (b - i)) {
            cnt += x.freq[j];
          }
          else {
            int nibo = min(len, x.freq[j] - ((b - i) - cnt));
            tmp.freq[j] = nibo;

            // cout << ":: " << j << ' ' << nibo << '\n';

            for (int jj = j - 1; jj >= 0; jj--) {
              if (nibo + x.freq[jj] <= len) {
                tmp.freq[jj] = x.freq[jj];
                nibo += x.freq[jj];
              }
              else {
                int need = len - nibo;
                tmp.freq[jj] = need;
                break;
              }
            }

            break;
          }
        }
      }

      // cout << tmp.freq[0] << ' ' << tmp.freq[1] << ' ' << tmp.freq[2] << '\n';
      // for (int j = 0; j < K; j++) {
      //   cout << tmp.freq[j] << ' ';
      // }
      // cout << '\n';

      lazy[n] = tmp;
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
    if (b > j || e < i) {
      node tmp;
      for (int j = 0; j < K; j++) {
        tmp.freq[j] = 0;
      }
      return tmp;
    }
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  cin >> s;
  s = '.' + s;

  st.build(1, 1, n);

  while (m--) {
    int l, r, k; cin >> l >> r >> k;
    node tmp = st.query(1, 1, n, l, r);
    tmp.lazy_on = true;
    if (k == 1) tmp.is_ascending = true;
    else tmp.is_ascending = false;

    // for (int j = 0; j < K; j++) {
    //   cout << tmp.freq[j] << '\n';
    // }

    st.upd(1, 1, n, l, r, tmp);
  }

  for (int i = 1; i <= n; i++) {
    node tmp = st.query(1, 1, n, i, i);
    int cnt = 0;
    for (int j = 0; j < K; j++) {
      if (tmp.freq[j]) cout << char(j + 'a');
      cnt += tmp.freq[j];
    }
    // cout << i << ' ' << cnt << '\n';
    // assert(cnt == 1);
  }
  cout << '\n';

  return 0;
}