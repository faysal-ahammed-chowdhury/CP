#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int N = 1e5 + 9, B = 30;
pair<pair<int, int>, int> Q[N];

int merge(int l, int r) {
  return l & r;
}

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == -1) return;
    tree[n] |= lazy[n];
    if(b != e) {
      int mid = (b + e) >> 1, l = n << 1, r = l + 1;
      if(lazy[l] == -1) lazy[l] = lazy[n];
      else lazy[l] |= lazy[n];
      if(lazy[r] == -1) lazy[r] = lazy[n];
      else lazy[r] |= lazy[n];
    }
    lazy[n] = -1;
  }
  void build(int n, int b, int e) {
    lazy[n] = -1;
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] = x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) {
      return (1 << 30) - 1;
    }
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change this
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  st.build(1, 1, n);
  for(int i = 1; i <= m; i++) {
    int l, r, q; cin >> l >> r >> q;
    Q[i] = {{l, r}, q};
    st.upd(1, 1, n, l, r, q);
  }

  for(int i = 1; i <= m; i++) {
    int l = Q[i].first.first;
    int r = Q[i].first.second;
    int q = Q[i].second;
    int x = st.query(1, 1, n, l, r);
    if(x != q) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for(int i = 1; i <= n; i++) {
    int x = st.query(1, 1, n, i, i);
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// // @author: faysalahammedchowdhury

// #define int long long
// const int N = 1e5 + 9, B = 30;
// pair<pair<int, int>, int> Q[N];

// struct node {
//   int arr[B];
// };

// node merge(node l, node r) {
//   node ans;
//   for(int k = 0; k < B; k++) {
//     ans.arr[k] = l.arr[k] & r.arr[k];
//   }
//   return ans;
// }

// struct ST {
//   node tree[4 * N];
//   int lazy[4 * N];
//   void push(int n, int b, int e) {
//     if(lazy[n] == -1) return;
//     for(int k = 0; k < B; k++) {
//       if(lazy[n] & (1 << k)) {
//         tree[n].arr[k] = 1;
//       }
//     }
//     if(b != e) {
//       int mid = (b + e) >> 1, l = n << 1, r = l + 1;
//       if(lazy[l] == -1) lazy[l] = lazy[n];
//       else lazy[l] |= lazy[n];
//       if(lazy[r] == -1) lazy[r] = lazy[n];
//       else lazy[r] |= lazy[n];
//     }
//     lazy[n] = -1;
//   }
//   void build(int n, int b, int e) {
//     lazy[n] = -1;
//     if(b == e) {
//       node tmp;
//       for(int k = 0; k < B; k++) {
//         tmp.arr[k] = 0;
//       }
//       return;
//     }
//     int mid = (b + e) >> 1, l = n << 1, r = l + 1;
//     build(l, b, mid);
//     build(r, mid + 1, e);
//     tree[n] = merge(tree[l], tree[r]); // change here
//   }
//   void upd(int n, int b, int e, int i, int j, int x) {
//     push(n, b, e);
//     if(b > j || e < i) return;
//     if(b >= i && e <= j) {
//       lazy[n] = x;
//       push(n, b, e);
//       return;
//     }
//     int mid = (b + e) >> 1, l = n << 1, r = l + 1;
//     upd(l, b, mid, i, j, x);
//     upd(r, mid + 1, e, i, j, x);
//     tree[n] = merge(tree[l], tree[r]); // change here
//   }
//   node query(int n, int b, int e, int i, int j) {
//     push(n, b, e);
//     if(b > j || e < i) {
//       node tmp;
//       for(int k = 0; k < B; k++) {
//         tmp.arr[k] = 1;
//       }
//       return tmp;
//     }
//     if(b >= i && e <= j) return tree[n];
//     int mid = (b + e) >> 1, l = n << 1, r = l + 1;
//     node L = query(l, b, mid, i, j);
//     node R = query(r, mid + 1, e, i, j);
//     return merge(L, R); // change this
//   }
// } st;

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   int n, m; cin >> n >> m;
//   st.build(1, 1, n);
//   for(int i = 1; i <= m; i++) {
//     int l, r, q; cin >> l >> r >> q;
//     Q[i] = {{l, r}, q};
//     st.upd(1, 1, n, l, r, q);
//   }

//   for(int i = 1; i <= m; i++) {
//     int l = Q[i].first.first;
//     int r = Q[i].first.second;
//     int q = Q[i].second;
//     int x = 0;
//     node ans = st.query(1, 1, n, l, r);
//     for(int k = 0; k < B; k++) {
//       if(ans.arr[k]) {
//         x += (1 << k);
//       }
//     }
//     if(x != q) {
//       cout << "NO\n";
//       return 0;
//     }
//   }

//   cout << "YES\n";
//   for(int i = 1; i <= n; i++) {
//     int x = 0;
//     node ans = st.query(1, 1, n, i, i);
//     for(int k = 0; k < B; k++) {
//       if(ans.arr[k]) {
//         x += (1 << k);
//       }
//     }
//     cout << x << ' ';
//   }
//   cout << '\n';

//   return 0;
// }