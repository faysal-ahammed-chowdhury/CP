#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 50009;
int a[N], b[N], Q[N], tree[3 * N * 4];

void build(int n, int b, int e) {
  if(b == e) {
    tree[n] = 0;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  tree[n] = tree[l] + tree[r];
}

void upd(int n, int b, int e, int i, int x) {
  if(b > i or e < i) {
    return;
  }
  if(b == e and b == i) {
    tree[n] += x;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  upd(l, b, mid, i, x);
  upd(r, mid + 1, e, i, x);
  tree[n] = tree[l] + tree[r];
}

int query(int n, int b, int e, int i, int j) {
  if(b > j or e < i) {
    return 0;
  }
  if(b >= i and e <= j) {
    return tree[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = l + 1;
  return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    set<int> se;
    for(int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      se.insert(a[i]);
      se.insert(b[i]);
    }

    for(int i = 1; i <= q; i++) {
      cin >> Q[i];
      se.insert(Q[i]);
    }

    map<int, int> mp;
    int id = 0;
    for(auto i: se) {
      mp[i] = ++id;
    }

    for(int i = 1; i <= n; i++) {
      a[i] = mp[a[i]];
      b[i] = mp[b[i]];
    }

    for(int i = 1; i <= q; i++) {
      Q[i] = mp[Q[i]];
    }

    build(1, 1, id);

    for(int i = 1; i <= n; i++) {
      int l = a[i], r = b[i];
      upd(1, 1, id, l, 1);
      if(r + 1 <= id) {
        upd(1, 1, id, r + 1, -1);
      }
    }
    
    cout << "Case " << ++cs << ":\n"; 
    for(int i = 1; i <= q; i++) {
      cout << query(1, 1, id, 1, Q[i]) << '\n';
    }
  }

  return 0;
}