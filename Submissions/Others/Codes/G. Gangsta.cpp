#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int pref[N];

struct ST {
  array<int, 3> tree[4 * (N + N)];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {0, 0, 0}; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n][0] = tree[l][0] + tree[r][0]; 
    tree[n][1] = tree[l][1] + tree[r][1]; 
    tree[n][2] = tree[l][2] + tree[r][2]; 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n][0] += x;
      tree[n][1]++;
      tree[n][2] += b;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n][0] = tree[l][0] + tree[r][0]; 
    tree[n][1] = tree[l][1] + tree[r][1]; 
    tree[n][2] = tree[l][2] + tree[r][2]; 
  }
  array<int, 3> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, 0};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    array<int, 3> L = query(l, b, mid, i, j);
    array<int, 3> R = query(r, mid + 1, e, i, j);
    return {(L[0] + R[0]), (L[1] + R[1]), (L[2] + R[2])}; 
  }
} st;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  int mn = 0;
  pref[0] = 0;
  for (int j = 1; j <= n; j++) {
    pref[j] = pref[j - 1] + (s[j] == '0' ? +1 : -1);
    mn = min(mn, pref[j]);
  }
  for (int j = 0; j <= n; j++) {
    pref[j] += abs(mn) + 1;
  }

  // int ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j < i; j++) {
  //     int x = pref[i], y = pref[j];
  //     if ((x - y) >= 0) {
  //       ans += ((x + i) - (y + j)) / 2;
  //     }
  //     else {
  //       ans += ((y + i) - (x + j)) / 2;
  //     }
  //   }
  // }

  st.build(1, 1, n + n);
  st.upd(1, 1, n + n, pref[0], 0);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = pref[i];
    auto tmp1 = st.query(1, 1, n + n, 1, x);
    auto tmp2 = st.query(1, 1, n + n, x + 1, n + n);

    int cnt = tmp1[1];
    int tmp = cnt * (x + i);
    tmp -= tmp1[2];
    tmp -= tmp1[0];
    tmp /= 2;
    ans += tmp;

    cnt = tmp2[1];
    tmp = (cnt * i) + tmp2[2];
    tmp -= (cnt * x);
    tmp -= tmp2[0];
    tmp /= 2;
    ans += tmp;

    // cout << i << ' ' << tmp << '\n';
    st.upd(1, 1, n + n, x, i);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}