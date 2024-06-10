#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  char a[n][n], b[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
      b[i][j] = a[i][j];
    }
  }

  for(int i = 1; i < n; i++) {
    b[0][i] = a[0][i - 1];
  }

  for(int i = 1; i < n; i++) {
    b[i][n - 1] = a[i - 1][n - 1];
  }

  for(int i = n - 2; i >= 0; i--) {
    b[n - 1][i] = a[n - 1][i + 1];
  }

  for(int i = n - 2; i >= 0; i--) {
    b[i][0] = a[i + 1][0];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << b[i][j];
    }
    cout << '\n';
  }
        
  return 0;
}