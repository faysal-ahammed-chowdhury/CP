#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = (1 << 17) + 9;
int a[N];

bool flag = true;

pair<int, char> merge(pair<int, char> first, pair<int, char> second) {
  if(first.second == 'x' && second.second == 'x') {
    return {first.first | second.first, 'o'};
  }
  else {
    return {first.first ^ second.first, 'x'};
  }
}

pair<int, char> tree[2 * N];
struct ST {
  ST() {
    memset(tree, 0, sizeof(tree));
  }
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], 'x'};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = {x, 'x'};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int two_pow_n = (1 << n);
  for(int i = 1; i <= two_pow_n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, two_pow_n);
  while(m--) {
    int p, b; cin >> p >> b;
    st.upd(1, 1, two_pow_n, p, b);
    cout << tree[1].first << '\n';
  }

  return 0;
}