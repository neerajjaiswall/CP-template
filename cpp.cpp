/*  
  
|| author/ solution || :               
  _                     _   _   ______   ______    ____      
 | |              _    | \ | | |  ____| |  __  |  / __ \ 
 | |__   _   _   (_)   |  \| | | (___   | |  | | | |  | |     
 |  _ \ | | | |        |     | |  ___|  | |_/_/  | |  | |    
 | |_) || |_| |   _    | |\  | | (____  | |  | | | |__| | 
 |_ __/  \__, |  (_)   |_| \_| |______| |_|  |_|  \____/
          __/ |                                                   
         |___/    
*/       

#include<bits/stdc++.h>
using namespace std;

typedef   long long int ll;
typedef   unsigned long long int ull ;
typedef   long double dll ;

#define  uset unordered_set
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define  mp make_pair
#define  pb push_back
#define  ff first 
#define  ss second
#define  fn for(int y=0;y<n;y++)
#define  f(i,k,n) for(int i=k;i<n;i++)
#define  fe(i,k,n) for(int i=k;i<=n;i++)
#define  fo(i,k,n) for(int i=n-1;i>=k;i--)
#define  all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7); 

//functions :
ull power(ull x, ull y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 

ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

void solve()
{
  // write your code here 
  cout<<12;
}

int main()
{
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    // cin>>t;
    // while(t--)
    // solve();
    int a,b;
    cin>>a;
    cout<<a<<endl;
        
    
    
    return 0;
}

