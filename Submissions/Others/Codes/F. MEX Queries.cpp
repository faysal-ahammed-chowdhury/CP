#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 4e5 + 9, QQ = 1e5 + 9;
array<ll, 3> Q[QQ];

struct node {
  int cnt0, cnt1;
};

node merge(node &l, node &r) {
  if (l.cnt0 == -1) return r;
  if (r.cnt0 == -1) return l;

  node ans;
  ans.cnt0 = l.cnt0 + r.cnt0;
  ans.cnt1 = l.cnt1 + r.cnt1;
  return ans;
}

struct ST {
  node tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    if (lazy[n] == 1) {
      tree[n].cnt0 = 0;
      tree[n].cnt1 = e - b + 1;

      if (b != e) {
        int mid = (b + e) >> 1, l = n << 1, r = l + 1;
        lazy[l] = 1;
        lazy[r] = 1;
      }
    }
    else if (lazy[n] == 2) {
      tree[n].cnt1 = 0;
      tree[n].cnt0 = e - b + 1;

      if (b != e) {
        int mid = (b + e) >> 1, l = n << 1, r = l + 1;
        lazy[l] = 2;
        lazy[r] = 2;
      }
    }
    else {
      swap(tree[n].cnt0, tree[n].cnt1);

      if (b != e) {
        int mid = (b + e) >> 1, l = n << 1, r = l + 1;
        if (lazy[l] == 0) lazy[l] = 3;
        else if (lazy[l] == 1) lazy[l] = 2;
        else if (lazy[l] == 2) lazy[l] = 1;
        else if (lazy[l] == 3) lazy[l] = 0;

        if (lazy[r] == 0) lazy[r] = 3;
        else if (lazy[r] == 1) lazy[r] = 2;
        else if (lazy[r] == 2) lazy[r] = 1;
        else if (lazy[r] == 3) lazy[r] = 0;
      }
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n].cnt0 = 1;
      tree[n].cnt1 = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int type) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = type;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, type);
    upd(r, mid + 1, e, i, j, type);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return { -1, -1};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

vector<ll> v;
int f(ll x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

bool ok(int mid, int mx) {
  auto tmp = st.query(1, 1, mx, 1, mid);
  if (tmp.cnt0 >= 1) return true;
  return false;
}

map<int, ll> mp;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
    v.push_back(Q[i][1]);
    v.push_back(Q[i][1] + 1);
    v.push_back(Q[i][2]);
    v.push_back(Q[i][2] + 1);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 1; i <= q; i++) {
    mp[f(Q[i][1])] = Q[i][1];
    mp[f(Q[i][1] + 1)] = Q[i][1] + 1;
    mp[f(Q[i][2])] = Q[i][2];
    mp[f(Q[i][2] + 1)] = Q[i][2] + 1;
  }

  int mx = v.size();

  st.build(1, 1, mx);
  for (int i = 1; i <= q; i++) {
    auto [type, l, r] = Q[i];
    l = f(l);
    r = f(r);
    // cout << l << ' '  << r << '\n';
    st.upd(1, 1, mx, l, r, type);

    if (v[0] > 1) cout << 1 << '\n';
    else {
      int l = 1, r = mx, ans = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid, mx)) {
          ans = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      assert(ans != -1);
      cout << mp[ans] << '\n';
    }
  }

  return 0;
}