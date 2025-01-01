#include <bits/stdc++.h>
using namespace std;

int n;
bool done;

bool check(vector<vector<int>> &v) {
  int s1 = 0, s2 = 0;
  for (int ii = 1; ii <= n; ii++) {
    s1 += v[ii][ii];
  }
  for (int ii = 1; ii <= n; ii++) {
    s2 += v[ii][n - ii + 1];
  }
  bool ok = s1 == s2;
  for (int ii = 1; ii < n; ii++) {
    int sum = 0;
    for (int jj = 1; jj <= n; jj++) {
      sum += v[ii][jj] + v[ii + 1][jj];
    }
    ok &= sum == s1 + s2;
  }
  for (int jj = 1; jj < n; jj++) {
    int sum = 0;
    for (int ii = 1; ii <= n; ii++) {
      sum += v[ii][jj] + v[ii][jj + 1];
    }
    ok &= sum == s1 + s2;
  }
  return ok;
}

void f(int i, int j, vector<vector<int>> &v) {
  if (i == n and j == 0) {
    map<int, int> mp;
    for (int ii = 1; ii <= n; ii++) {
      for (int jj = 1; jj <= n; jj++) {
        mp[v[ii][jj]]++;
      }
    }
    bool ok = true;
    for (int ii = 1; ii <= n; ii++) {
      ok &= mp[ii] == n;
    }
    if (ok) {
      if (check(v) and !done) {
        for (int ii = 1; ii <= n; ii++) {
          for (int jj = 1; jj <= n; jj++) {
            cout << v[ii][jj] << ' ';
          }
          cout << '\n';
        }
        cout << '\n';
      }
    }
    return;
  }

  for (int k = 1; k <= n; k++) {
    v[i][j] = k;
    if (i == n and j == n) f(i, 0, v);
    else if (j < n) f(i, j + 1, v);
    else if (i + 1 <= n) f(i + 1, 1, v);
    v[i][j] = -1;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<vector<int>> v(n + 1, vector<int>(n + 1, -1));
  f(1, 1, v);
  // cout << "herer\n";
  v[1] = {0, 2, 3, 1};
  v[2] = {0, 1, 2, 3};
  v[3] = {0, 3, 1, 2};
  cout << check(v) << '\n';

  return 0;
}