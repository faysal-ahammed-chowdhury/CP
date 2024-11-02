#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


// policy Based ds
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int> , null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define chotoKoita(s, x) s.order_of_key(x) // return the number of elements in the set that are smaller than x
#define elemat(s ,x) s.find_by_order(x) // return poller to element at index x



typedef   vector<ll>  vl;
typedef   vector<pair<ll, ll>> vll;
typedef   multiset<pair<ll, ll>> msll;
typedef   multiset<ll> msl;
typedef   set<pair<ll, ll>> sll;
typedef   set<ll> sl;
typedef   map<ll, ll> mll;
typedef   pair<ll, ll>pll;

typedef   vector<ll>  vi;
typedef   vector<pair<ll, ll>> vii;
typedef   multiset<pair<ll, ll>> msii;
typedef   multiset<ll> msi;
typedef   set<pair<ll, ll>> sii;
typedef   set<ll> si;
typedef   map<ll, ll> mii;
typedef   pair<ll, ll>pii;


#define recap(i,k,n)  for(ll i = k; i>=n; i--)
#define rep(i,k,n)    for(ll i=k; i<n; i++)
#define boost   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define for1(x, a, b)  for(x=a; x<b; x++)
#define for2(x, a, b)  for(x=a, x>=b; x--)
#define endl  "\n"
#define all(x)  x.begin(), x.end()
#define mp      make_pair
#define read    freopen("input.txt","r",stdin)
#define write   freopen("output.txt","w",stdout)
#define pb      push_back
#define ff      first
#define ss      second
#define bb      begin
#define mem(arr, x) memset(arr, x, sizeof(arr));
#define arr_ub(arr, n, x) upper_bound(arr, arr+n, x)-arr
#define arr_lb(arr, n, x) lower_bound(arr, arr+n, x)-arr
#define u_p(v, x) upper_bound(v.begin(), v.end(), x)-v.begin()
#define l_b(v, x) lower_bound(v.begin(), v.end(), x)-v.begin()


const ll sz = 1e6 + 123;
#define INF 1000000000000000007

#define stringLen 18446744073709551620
//#define pi 3.1415926536
const ll mod = 1000000007;
const ll MM = 1e9;

inline void normal(ll &a, ll MOD) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return (a * b) % MOD; }
inline ll modAdd(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return (a + b) % MOD; }
inline ll modSub(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); a -= b; normal(a, MOD); return a; }
inline ll modPow(ll b, ll p, ll MOD) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b, MOD); b = modMul(b, b, MOD); p >>= 1; } return r; }
inline ll modInverse(ll a, ll MOD) { return modPow(a, MOD - 2, MOD); }
inline ll modDiv(ll a, ll b, ll MOD) { return modMul(a, modInverse(b, MOD), MOD); }

bool isPalindrome(string s) {ll i = 0, j = s.size() - 1; for (i, j; i <= j; i++, j--) {if (s[i] != s[j]) return 0;} return 1;}
ll gcd(ll a, ll  b) {return b == 0 ? a : gcd(b, a % b);}
//// lcm * gcd = a*b
ll lcm(ll a, ll b) {if (a > b)swap(a, b); return a * (b / gcd(a, b));}
//bool isPalindrome(string s){ ll i=0,j=s.size()-1;for(i,j;i<=j;i++,j--){if(s[i]!=s[j]) return 0;} return 1;}
bool isPowerofTwo(ll n) {return (n && !(n & (n - 1)));}
//ll count_one(ll n){ll count=0;while(n){n &= (n-1);count++;}return count;}
//string binRep(ll n){string s="";ll f = 0;while(n>0){if(n%2){f=1;s+='1';}else s+='0';n/=2;}if(s.empty())return "0";else return s;}
//ll ctz(ll n){return __builtin_ctzll(n);}
//ll clz(ll n){return __builtin_clzll(n);}
//ll bitCount(ll n){return __builtin_popcountll(n);}

const int N = 1e4 + 123;

ll hlth[N], dmg[N], n, d;
ll dp[N][2];
ll cal(ll n){
  if(n < 0 ) return 0;
  return ( n + d - 1) / d;
}
ll fi(int pos, int task){

  if(pos > n) return 0;
  if(dp[pos][task] != -1) return dp[pos][task];
  // task == 1 mane prev k mere shamne aschi, amr helth theke prev er dmg minus hobe
  ll health = hlth[pos];
  ll ans = LONG_LONG_MAX;
  if(task == 1){
    health = max(0LL, health - dmg[pos-1]);
    ans = min(ans, fi(pos+1, 1) + cal(health));
    ans = min(ans, fi(pos+1, 0) + cal(health - dmg[pos+1]));
  }
  else {
    ans = min(ans, fi(pos+1, 1) + cal(health));
    ans = min(ans, fi(pos+1, 0) + cal(health - dmg[pos+1]));
  }
  return dp[pos][task]=ans;
}

void solve(){
  cin>>n>>d;
  memset(dp, -1, sizeof dp);
  memset(hlth, 0, sizeof hlth);
  memset(dmg, 0, sizeof dmg);
  for(int i=1; i<=n; i++){
    cin>>hlth[i];
  }
  for(int i=1; i<=n; i++){
    cin>>dmg[i];
  }

  cout << fi(1, 0) << endl;
}

int main() {

  boost;
  int t;
  t=1;
  
  cin>>t;
  while(t--){ solve();}
  return 0;
}

