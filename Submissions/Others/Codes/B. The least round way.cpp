#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005, inf = 2e9;
int n, a[N][N];
pair<int, int> dp1[N][N], dp2[N][N]; // cnt, direction(0->right, 1->down)

int calc(int n, int x) {
  if (n == 0) return 0;
  int cnt = 0;
  while (n % x == 0) {
    cnt++;
    n /= x;
  }
  return cnt;
}

pair<int, int> f1(int i, int j) {
  if (i == n and j == n) return {calc(a[i][j], 2), -1};
  pair<int, int> &ans = dp1[i][j];
  if (ans.first != -1) return ans;
  ans = {inf, 0};
  // cout << i << ' ' << j << ' ' << cnt << '\n';
  if (i + 1 <= n) {
    ans = f1(i + 1, j);
    ans.second = 1;
  }
  if (j + 1 <= n) {
    auto tmp = f1(i, j + 1);
    if (tmp.first <= ans.first) {
      ans = tmp;
      ans.second = 0;
    }
  }
  ans.first += calc(a[i][j], 2);
  return ans;
}


pair<int, int> f2(int i, int j) {
  if (i == n and j == n) return {calc(a[i][j], 5), -1};
  pair<int, int> &ans = dp2[i][j];
  if (ans.first != -1) return ans;
  ans = {inf, 0};
  if (i + 1 <= n) {
    ans = f2(i + 1, j);
    ans.second = 1;
  }
  if (j + 1 <= n) {
    auto tmp = f2(i, j + 1);
    if (tmp.first <= ans.first) {
      ans = tmp;
      ans.second = 0;
    }
  }
  ans.first += calc(a[i][j], 5);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  pair<int, int> idx = { -1, -1};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        idx = {i, j};
        a[i][j] = 10;
      }
    }
  }

  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  pair<int, int> ans = min(f1(1, 1), f2(1, 1));

  if (idx.first != -1 and ans.first > 0) {
    cout << 1 << '\n';
    int i = 1, j = 1;
    while (i < idx.first) {
      cout << "D";
      i++;
    }
    while (j < n) {
      cout << "R";
      j++;
    }
    while (i < n) {
      cout << "D";
      i++;
    }
    cout << '\n';
    return 0;
  }

  cout << ans.first << '\n';

  auto call = [&](int i, int j) {
    return (ans == f1(1, 1)) ? f1(i, j) : f2(i, j);
  };

  int i = 1, j = 1;
  auto cur = ans;
  while (cur.second != -1) {
    assert(cur.second == 0 or cur.second == 1);
    if (cur.second == 0) {
      cout << 'R';
      cur = call(i, j + 1);
      j++;
    }
    else {
      cout << 'D';
      cur = call(i + 1, j);
      i++;
    }
  }

  cout << '\n';

  return 0;
}