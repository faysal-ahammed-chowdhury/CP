  #include <bits/stdc++.h>
  using namespace std;

  int cs = 0;
  void solve() {
    int n; cin >> n;
    int x = 2 * n;
    int a[x + 1];
    for (int i = 1; i <= x; i++) {
      cin >> a[i];
    }
    cout << "Case " << ++cs << ": ";
    cout << 10 << '\n';
    int y = (x / 4);
    y++;
    for (int i = 1; i <= 7; i++) {
      if (i & 1) {
        cout << y << ' ' << (y + (x / 2)) - 1 << '\n';
      }
      else {
        cout << 1 << ' ' << (x / 2) << '\n';
        cout << (x / 2) + 1 << ' ' << x << '\n';
      }
    }
  }

  int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
  }