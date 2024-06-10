#include <bits/stdc++.h>
using namespace std;

const int N = 30005, inf = 2e9;
int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

int n; 
bool ok(int i, int len, int val) {
  return st.query(1, 1, n, i, i + len - 1) >= val;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int height = a[i];
    
    int l = 1, r = n - i + 1, right = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(i, mid, height)) {
        right = i + mid - 1;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    l = 1, r = i; int left = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(i - mid + 1, mid, height)) {
        left = i - mid + 1;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    int width = right - left + 1;
    int area = height * width;
    ans = max(ans, area);
  }
  
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}