#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
int a[N];

struct node {
  pair<int, int> first; 
  pair<int, int> middle; 
  pair<int, int> last; 
};

node merge(node a, node b) {
  pair<int, int> p1 = a.first;
  pair<int, int> p2 = a.middle;
  pair<int, int> p3 = a.last;
  pair<int, int> p4 = b.first;
  pair<int, int> p5 = b.middle;
  pair<int, int> p6 = b.last;
  pair<int, int> mx = max(p2, p5);
  if(a.last.second == b.first.second) {
    p3.first += p4.first;
    mx = max(mx, p3);
  }
  if(p1.second == mx.second) {
    p1.first = mx.first;
  }
  if(p6.second == mx.second) {
    p6.first = mx.first;
  }
  return {p1, mx, p6};
}


struct ST {
  node tree[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
  }
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {{1, a[b]}, {1, a[b]}, {1, a[b]}};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {{0, 0}, {0, 0}}; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

 
  int n, q;;
  while(cin >> n && n != 0) {
    cin >> q;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    st.build(1, 1, n);

    while(q--) {
      int l, r; cin >> l >> r;
      node ans = st.query(1, 1, n, l, r);
      cout << ans.middle.first << '\n';
    }
  }

  return 0;
}