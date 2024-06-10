#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9, INF = 2e9;
int a[N];
pair<int, int> tree[4 * N];

void build(int n, int b, int e) {
  if(b == e) {
    tree[n] = {a[b], 1};
    return;
  }
  int mid = (b + e) >> 1, l = n << 1, r = l + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  if(tree[l].first == tree[r].first) {
    tree[n] = {tree[l].first, tree[l].second + tree[r].second};
  }
  else {
    tree[n] = min(tree[l], tree[r]);
  }
}

void upd(int n, int b, int e, int i, int x) {
  if(b > i || e < i) return;
  if(b == e && b == i) {
    tree[n] = {x, 1};
    return;
  }
  int mid = (b + e) >> 1, l = n << 1, r = l + 1;
  upd(l, b, mid, i, x);
  upd(r, mid + 1, e, i, x);
  if(tree[l].first == tree[r].first) {
    tree[n] = {tree[l].first, tree[l].second + tree[r].second};
  }
  else {
    tree[n] = min(tree[l], tree[r]);
  }
}

pair<int, int> query(int n, int b, int e, int i, int j) {
  if(b > j || e < i) return {INF, 1};
  if(b >= i && e <= j) return tree[n];
  int mid = (b + e) >> 1, l = n << 1, r = l + 1;
  pair<int, int> L = query(l, b, mid, i, j);
  pair<int, int> R = query(r, mid + 1, e, i, j);
  if(L.first == R.first) {
    return {L.first, L.second + R.second};
  }
  else {
    return min(L, R);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, 1, n);

  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int i, x; cin >> i >> x;
      i++;
      upd(1, 1, n, i, x);
    }
    else {
      int l, r; cin >> l >> r;
      l++;
      pair<int, int> ans = query(1, 1, n, l, r);
      cout << ans.first << ' ' << ans.second << '\n';
    }
  }

  return 0;
}