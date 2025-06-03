#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9, B = 400, MAXV = 2097152 + 9;

struct query {
  int l, r, id;
  bool operator < (const query &x) const {
    if (l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];

int cnt[MAXV], a[N], pref[N];
int val, k;

inline void add_left(int i) {
  int x = pref[i];
  int y = pref[i] ^ k;
  if (x > y) swap(x, y);
  if (k == 0 and x == 0 and y == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val -= 1ll * cnt[y] * cnt[x];
  ++cnt[pref[i]];
  if (k == 0 and x == 0 and y == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val += 1ll * cnt[y] * cnt[x];
}
inline void add_right(int i) {
  int x = pref[i];
  int y = pref[i] ^ k;
  if (x > y) swap(x, y);
  if (k == 0 and x == 0 and y == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val -= 1ll * cnt[y] * cnt[x];
  // cout << pref[i] << ' ' << val << ' ';
  ++cnt[pref[i]];
  if (k == 0 and x == 0 and y == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val += 1ll * cnt[y] * cnt[x];
  // cout << val << '\n';
}
inline void rem_left(int i) {
  int x = pref[i];
  int y = pref[i] ^ k;
  if (x > y) swap(x, y);
  if (k == 0 and x == 0 and y == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val -= 1ll * cnt[y] * cnt[x];
  --cnt[pref[i]];
  if (k == 0 and x == 0 and y == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val += 1ll * cnt[y] * cnt[x];
}
inline void rem_right(int i) {
  int x = pref[i];
  int y = pref[i] ^ k;
  if (x > y) swap(x, y);
  if (k == 0 and x == 0 and y == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val -= (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val -= 1ll * cnt[y] * cnt[x];
  --cnt[pref[i]];
  if (k == 0 and x == 0 and y == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else if (k == 0) val += (1ll * cnt[y] * (cnt[x] - 1)) / 2;
  else val += 1ll * cnt[y] * cnt[x];
}
long long ans[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] ^ a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> Q[i].l >> Q[i].r;
    Q[i].l--;
    Q[i].id = i;
  }

  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r;
    if (R < l) {
      while (l > L) add_left(--l);
      while (l < L) rem_left(l++);
      while (r < R) add_right(++r);
      while (r > R) rem_right(r--);
    } else {
      while (r < R) add_right(++r);
      while (r > R) rem_right(r--);
      while (l > L) add_left(--l);
      while (l < L) rem_left(l++);
    }
    ans[Q[i].id] = val;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

  return 0;
}