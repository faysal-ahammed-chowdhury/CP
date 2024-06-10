#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[4][4], b[4][4];

void bosha() {
  a[1][2] = 15 - a[1][1] - a[1][3];
  a[3][2] = 15 - a[3][1] - a[3][3];
  a[2][1] = 15 - a[1][1] - a[3][1];
  a[2][3] = 15 - a[1][3] - a[3][3];
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';

}

int check() {
  int ans = 1e18;
  int ans1 = 0;
  a[1][1] = 2;
  a[1][3] = 4;
  a[3][1] = 6;
  a[3][3] = 8;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);


  ans1 = 0;
  a[1][1] = 2;
  a[1][3] = 6;
  a[3][1] = 4;
  a[3][3] = 8;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  ans1 = 0;
  a[1][1] = 8;
  a[1][3] = 6;
  a[3][1] = 4;
  a[3][3] = 2;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  ans1 = 0;
  a[1][1] = 8;
  a[1][3] = 4;
  a[3][1] = 6;
  a[3][3] = 2;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  ans1 = 0;
  a[1][1] = 4;
  a[1][3] = 2;
  a[3][1] = 8;
  a[3][3] = 6;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  ans1 = 0;
  a[1][1] = 4;
  a[1][3] = 8;
  a[3][1] = 2;
  a[3][3] = 6;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  ans1 = 0;
  a[1][1] = 6;
  a[1][3] = 2;
  a[3][1] = 8;
  a[3][3] = 4;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  ans1 = 0;
  a[1][1] = 6;
  a[1][3] = 8;
  a[3][1] = 2;
  a[3][3] = 4;
  bosha();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans1 += abs(a[i][j] - b[i][j]);
    }
  }
  ans = min(ans, ans1);

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  n = 3;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> b[i][j];
    }
  }
  
  a[2][2] = 5;
  cout << check() << '\n';

  return 0;
}