#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 9, B = 440;
 
struct query {
  int l, r, id;
  bool operator < (const query &x) const {
    if (l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];
 
int a[N], cnt[N];
int res;
 
inline void add_left(int i) {
  int x = a[i];
  cnt[x]++;
  if (cnt[x] == 1) res++;
}
inline void add_right(int i) {
  int x = a[i];
  cnt[x]++;
  if (cnt[x] == 1) res++;
}
inline void rem_left(int i) {
  int x = a[i];
  cnt[x]--;
  if (cnt[x] == 0) res--;
}
inline void rem_right(int i) {
  int x = a[i];
  cnt[x]--;
  if (cnt[x] == 0) res--;
}
int ans[N];
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n, q;
  cin >> n >> q;
  vector<int> v;
  
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    v.push_back(a[i]);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  }

  for (int i = 1; i <= q; i++) {
    cin >> Q[i].l >> Q[i].r;
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
    ans[Q[i].id] = res;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
 
  return 0;
}