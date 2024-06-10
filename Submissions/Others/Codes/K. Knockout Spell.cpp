#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, k; 

bool is_valid(int x, int y) {
  if(x > 0 && x <= n && y > 0 && y <= n) return true;
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  int a[n + 1][n + 1];
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int corner1i = i, corner1j = j;
      int corner2i = i, corner2j = j + k -1;
      int corner3i = i + k - 1, corner3j = j;
      int corner4i = i + k - 1, corner4j = j + k - 1;
      if(is_valid(corner1i, corner1j) && is_valid(corner2i, corner2j) && is_valid(corner3i, corner3j) && is_valid(corner4i, corner4j)) {
        if(a[corner1i][corner1j] == a[corner2i][corner2j] && a[corner2i][corner2j] == a[corner3i][corner3j] && a[corner3i][corner3j] == a[corner4i][corner4j]) {
          ans++;
        }
      }
    }
  }
  cout << ans << '\n';
        
  return 0;
}