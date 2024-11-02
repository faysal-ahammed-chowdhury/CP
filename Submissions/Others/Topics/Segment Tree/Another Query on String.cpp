#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
string s;

struct node {
  int freq[26];
  node() {
    memset(freq, 0, sizeof freq);
  }
};

struct ST {
  node tree[4 * N];

  node merge(node a, node b) {
    for (int i = 0; i < 26; i++) {
      a.freq[i] += b.freq[i];
    }
    return a;
  }

  void build(int n, int b, int e) {
    if(b == e) {
      tree[n].freq[s[b] - 'a'] = 1; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, char ch) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n].freq[s[i] - 'a']--; 
      tree[n].freq[ch - 'a']++;
      s[i] = ch; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, ch);
    upd(r, mid + 1, e, i, ch);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {};
    if(b >= i && e <= j) return tree[n];
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
    int type; cin >> type;
    if (type == 1) {
      int i; cin >> i;
      char ch; cin >> ch;
      st.upd(1, 1, n, i, ch);
    }
    else {
      int l, r; cin >> l >> r;
      char ch; cin >> ch;
      node tmp = st.query(1, 1, n, l, r);
      cout << tmp.freq[ch - 'a'] << '\n';
    }
  }

  return 0;
}