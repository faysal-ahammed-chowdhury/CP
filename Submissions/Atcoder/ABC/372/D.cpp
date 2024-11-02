#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9, K = 20;
int a[N], tree[N][K];

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

bool ok(int l, int r, int mx) {
  return query(l, r) == mx;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(n);

  int diff[n + 1];
  memset(diff, 0, sizeof diff);
  for (int j = 2; j <= n; j++) {
    int l = 1, r = j, left_i = j - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid, j, a[j])) {
        left_i = mid - 1;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    // cout << j << ' ' << left_i << '\n';
    if (left_i == 0) left_i++;
    diff[left_i]++;
    diff[j]--;
  }

  for (int i = 1; i <= n; i++) {
    diff[i] += diff[i - 1];
    cout << diff[i] << ' ';
  }
  cout << '\n';

  return 0;
}
