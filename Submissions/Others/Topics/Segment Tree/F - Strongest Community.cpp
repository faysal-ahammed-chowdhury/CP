#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
int a[N];

struct node {
  int first_element, first_element_cnt;
  int last_element, last_element_cnt;
  int max_cnt;
};

node merge(node l, node r) {
  if(l.first_element == -1) return r;
  if(r.first_element == -1) return l;
  node ans;
  ans.max_cnt = max(l.max_cnt, r.max_cnt);
  if(l.last_element == r.first_element) {
    ans.max_cnt = max(ans.max_cnt, l.last_element_cnt + r.first_element_cnt);
  }
  ans.first_element = l.first_element;
  ans.first_element_cnt = l.first_element_cnt;
  if(l.first_element == r.first_element) {
    ans.first_element_cnt += r.first_element_cnt;
  }
  ans.last_element = r.last_element;
  ans.last_element_cnt = r.last_element_cnt;
  if(r.last_element == l.last_element) {
    ans.last_element_cnt += l.last_element_cnt;
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n].first_element = a[b];
      tree[n].first_element_cnt = 1;
      tree[n].last_element = a[b];
      tree[n].last_element_cnt = 1;
      tree[n].max_cnt = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {-1, -1, -1, -1, -1};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, c, q; cin >> n >> c >> q;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    st.build(1, 1, n);

    cout << "Case " << ++cs << ":\n";
    while(q--) {
      int l, r; cin >> l >> r;
      node ans = st.query(1, 1, n, l, r);
      cout << ans.max_cnt << '\n';
    }
  }

  return 0;
}