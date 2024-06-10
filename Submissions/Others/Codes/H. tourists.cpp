#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAX = 2e18;

ll lcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  while(cin >> n && n != 0) {
    ll c1, n1; cin >> c1 >> n1;
    ll c2, n2; cin >> c2 >> n2;

    ll cost1 = MAX, cost2 = MAX, cost3 = MAX, cost4 = MAX;

    bool possible = false;

    if(n % n1 == 0) {
      cost1 = c1 * (n / n1);
      possible = true;
    }
    if(n % n2 == 0) {
      cost2 = c2 * (n / n2);
      possible = true;
    }

    bool possible1 = false;
    ll rem = n;
    ll cnt1 = 0, cnt2 = 0;
    while(rem % n1 > 0) {
      rem -= n2;
      cnt2++;
    }
    if(rem % n1 == 0) {
      possible1 = true;
      cnt1 = (n - (cnt2 * n2)) / n1;
    }

    if(possible1) {
      cost3 = cnt1 * c1 + cnt2 * c2;
    }

    bool possible2 = false;
    rem = n;
    ll cnt3 = 0, cnt4 = 0;
    while(rem % n2 > 0) {
      rem -= n1;
      cnt3++;
    }
    if(rem % n2 == 0) {
      possible2 = true;
      cnt4 = (n - (cnt3 * n1)) / n2;
    }

    if(possible2) {
      cost4 = cnt4 * c2 + cnt3 * c1;
    }

    if(possible == false && (possible1 == false && possible2 == false)) {
      cout << "failed\n";
      continue;
    }

    ll mn = min({cost1, cost2, cost3, cost4});

    if(mn == cost1) {
      cout << (n / n1) << ' ' << 0 << '\n';
    }
    else if(mn == cost2) {
      cout << 0 << ' ' << (n / n2) << '\n';
    }
    else if(mn == cost3) {
      cout << cnt1 << ' ' << cnt2 << '\n';
    }
    else {
      cout << cnt3 << ' ' << cnt4 << '\n';
    }
  }

  return 0;
}