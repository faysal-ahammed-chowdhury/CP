#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, QQ = 2e5 + 9, mod = 1e9 + 7, K = 20;
const ll inf = 1e9;
int n, a[N];
vector<pair<int, int>> Q[QQ];
pair<int, int> ans[QQ];
int tree[N][K];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = max(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]);
}

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = -inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = max(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<int, vector<int>> mp;
  int q; cin >> n >> q;

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
    v.push_back(a[i]);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  build(n);

  for (int i = 1; i <= q; i++) {
    int type; cin >> type;
    if (type == 1) {
      int idx, k; cin >> idx >> k;
      Q[idx].push_back({k, i});
    }
    else {
      int idx; cin >> idx;
      Q[idx].push_back({0, i});
    }
  }

  stack<int> stk;
  int next_greater[n + 1];
  memset(next_greater, -1, sizeof next_greater);
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() and a[stk.top()] < a[i]) {
      next_greater[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << next_greater[i] << '\n';
  // }

  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int com_val = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

    for (auto [k, idx] : Q[i]) {
      bool flag = false;
      if (k == 0) { // type 2
        int mx = st.query(1, 1, n, 1, com_val - 1);
        mx = max(mx, st.query(1, 1, n, com_val + 1, n));
        int first = mp[a[i]][0];
        mx = max(mx, i - first);
        k = mx;
        k = max(1, k);
        flag = true;
      }

      int l = 1, r = i;
      int mx = query(l, r);
      if (mx > a[i]) {
        ans[idx] = {0, flag ? k : -1};
      }
      else {
        int first = mp[a[i]][0];
        l = 1, r = min(first + k, n);
        mx = query(l, r);
        if (mx > a[i]) {
          ans[idx] = {0, flag ? k : -1};
        }
        else {
          int mx = st.query(1, 1, n, 1, com_val - 1);
          mx = max(mx, st.query(1, 1, n, com_val + 1, n));
          int first = mp[a[i]][0];
          mx = max(mx, i - first);
          if (mx > k) {
            ans[idx] = {0, flag ? k : -1};
          }
          else {
            int r = min(n, first + k);
            auto it1 = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), r);
            --it1;
            int cnt = it1 - mp[a[i]].begin();
            auto it2 = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), i);
            --it2;
            int pos = it2 - mp[a[i]].begin();
            cnt++, pos++;

            int upore = (pos == 1) ? 1 : power(2, pos - 2, mod);
            int niche = power(2, cnt - 1, mod);
            int cur = 1ll * upore * power(niche, mod - 2, mod) % mod;
            ans[idx] = {cur, flag ? k : -1};
          }
        }
      }
    }

    int nxt = next_greater[i];
    if (nxt == -1) nxt = n + 1;
    st.upd(1, 1, n, com_val, nxt - i);
  }

  for (int i = 1; i <= q; i++) {
    if (ans[i].second == -1) {
      cout << ans[i].first << '\n';
    }
    else {
      cout << ans[i].second << ' ' << ans[i].first << '\n';
    }
  }

  return 0;
}