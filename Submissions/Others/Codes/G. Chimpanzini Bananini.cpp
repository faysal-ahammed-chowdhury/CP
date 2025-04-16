#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int q; cin >> q;
  int n = 0;
  ll ans1 = 0, ans2 = 0, rev = 0;
  list<int> li1, li2;
  ll sum = 0;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      if (!rev) {
        int val = li1.back();
        li1.pop_back();
        li1.insert(li1.begin(), val);

        ans1 -= (1ll * val * n);
        ans1 += sum;

        val = li2.front();
        li2.pop_front();
        li2.insert(li2.end(), val);

        ans2 -= sum;
        ans2 += 1ll * n * val;
        // cout << n << '\n';
      }
      else {
        int val = li2.back();
        li2.pop_back();
        li2.insert(li2.begin(), val);

        ans2 -= (1ll * val * n);
        ans2 += sum;

        val = li1.front();
        li1.pop_front();
        li1.insert(li1.end(), val);

        ans1 -= sum;
        ans1 += 1ll * n * val;
      }
    }
    else if (type == 2) {
      rev++;
      rev %= 2;
    }
    else {
      int k; cin >> k;
      sum += k;
      n++;
      if (!rev) {
        li1.insert(li1.end(), k);
        ans1 += 1ll * n * k;
        li2.insert(li2.begin(), k);
        ans2 += sum;
      }
      else {
        li2.insert(li2.end(), k);
        ans2 += 1ll * n * k;
        li1.insert(li1.begin(), k);
        ans1 += sum;
      }
    }

    // for (auto x : li1) cout << x << ' '; cout << ": " << ans1 << '\n';
    //   for (auto x : li2) cout << x << ' '; cout << ": " << ans2 << '\n';
    //     cout << '\n';

    if (!rev) cout << ans1 << '\n';
    else cout << ans2 << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}