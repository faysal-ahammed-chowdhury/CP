#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, MAXV = 1e8 + 9, inf = 1e9; 
int a[N];
vector<int> all_primes;

int count_primes(int n) {
  const int S = 10000;

  vector<int> primes;
  int nsqrt = sqrt(n);
  vector<char> is_prime(nsqrt + 2, true);
  for (int i = 2; i <= nsqrt; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= nsqrt; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int result = 0;
  vector<char> block(S);
  for (int k = 0; k * S <= n; k++) {
    fill(block.begin(), block.end(), true);
    int start = k * S;
    for (int p : primes) {
      int start_idx = (start + p - 1) / p;
      int j = max(start_idx, p) * p - start;
      for (; j < S; j += p) block[j] = false;
    }
    if (k == 0) block[0] = block[1] = false;
    for (int i = 0; i < S && start + i <= n; i++) {
      if (block[i]) {
        all_primes.push_back(start + i);
        result++;
      }
    }
  }
  return result;
}

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], a[b]};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = min(tree[l].first, tree[r].first);
    tree[n].second = max(tree[l].second, tree[r].second);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = {x, x};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n].first = min(tree[l].first, tree[r].first);
    tree[n].second = max(tree[l].second, tree[r].second);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {inf, -inf};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {min(L.first, R.first), max(L.second, R.second)}; 
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  count_primes(MAXV);
  // for (auto x : all_primes) cout << x << '\n'; cout << '\n';

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, x);
    } 
    else {
      int l, r; cin >> l >> r;
      auto [mn, mx] = st.query(1, 1, n, l, r);
      // cout << mn << ' ' << mx << '\n';
      cout << upper_bound(all_primes.begin(), all_primes.end(), mx) - lower_bound(all_primes.begin(), all_primes.end(), mn) << '\n';
    }
  }

  return 0;
}