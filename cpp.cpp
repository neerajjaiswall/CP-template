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

#include <bits/stdc++.h>
using namespace std;

# define    vi             std::vector<ll>
# define    ll             long long 
# define    int            long long 
# define    fast           ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
# define    pb             push_back
# define    fn             for(int i=0;i<n;i++)
# define    rep(i,a,b)      for(ll i=a;i<b;i++)
# define    all(x)         x.begin(), x.end()
# define    allr(a)        a.rbegin(), a.rend()
# define    PI             3.14159265358979323846
# define    MOD            1000000007
# define    endl           "\n"
# define    fi             first
# define    se             second
# define    pii            pair<ll,ll>
# define    deb1(x)        cout<<#x<<" "<<x<<endl;
# define    deb2(x,y)      cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
# define    deb3(x,y,z)    cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

ll max(ll a, ll b);         ll min(ll a, ll b);               void getio(); 
bool prime[1000001];        bool isPrime(ll n);               ll gcd(ll a, ll b);
vi getPrimeFactors(ll n);   ll multiply(ll a,ll b,ll m);      void sieve();  
ll fastpow(ll x, ll n);     ll getDigitSum(ll n);             vi getFactors(ll n);
ll modpow(ll x,ll n,ll m);  ll modinverse(ll x, ll m);	      map<int,int> primeFactorisation(ll a);  
ll eulerfun(ll n);          ll extGCD(ll a,ll b,ll &x,ll &y); vi p;

template<class T> void printVector(const std::vector<T> arr); 
template<class T> void printArray(T arr[], ll n); 
bool func ( pair<int,int> a, pair<int,int> b ) { return a.second>b.second; }

//_____________________________________________________________________________________

void solve()
{
    // Your code goes here:
	
}


int32_t main()
{
    getio();
    // int t; cin>>t; while(t--)
    solve();
}

/*_____________________________________________________________________________________     
################################### Functions #########################################
*/                                  

ll max(ll a, ll b) { if(a>b) return a; else return b;}
ll min(ll a, ll b) { if(a<b) return a; else return b;}

void getio()
{
    fast
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll gcd(ll a, ll b) //O(log min(a,b))
{ while (b) { a %= b; swap(a, b); } return a; }

void sieve()
{
	prime[1]=1;
	prime[0]=1;

	for(int i=2; i*i<1000001; i++)
	{
		if(!prime[i])
		{
			for(int j=i*i; j<1000001; j+=i)
				prime[j]=1;
		}
	}
			for(int i=0; i<=1000000; i++)
				if(!prime[i]) p.push_back(i);	
}

map<int, int> primeFactorisation(int n)
{
	map<int, int> a;
	int siz = p.size();
	for(int i=2; i*i<=n and i<siz; i++)
	{
		while(n%i==0) {a[i]++; n/=i;}
	}
	if(n!=1) a[n]++;
	return a;
}

bool isPrime(ll n)//O(sqrt(n))
{ if(n<2) return false; for (ll i=2;i*i<=n;i++)if(n%i==0) return false; return true; }

std::vector<ll> getPrimeFactors(ll n)
{
    std::vector<ll> prime;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) { prime.pb(i);  while(n % i == 0) n=n/i; }
    if (n != 1) prime.pb(n); return prime;
}

std::vector<ll> getFactors(ll n)
{
    std::vector<ll> fact;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fact.pb(i);
            if (n / i != i)
                fact.pb(n / i);
        }
    }
    if (n != 1)
        fact.pb(n);
    sort(all(fact));
    return fact;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    //produces correct results for negative integers as well
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1, d;
    d = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll modpow(ll x, ll n, ll m) //O(logn)// used for calculating (x^n)%m
{
    if (n == 0)
        return 1;
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = multiply(res, x, m);
        x = multiply(x, x, m);
        n = n >> 1;
    }
    return res%m;
}
ll fastpow(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = res * x;
        x = x * x;
        n = n >> 1;
    }
    return res;
}

ll multiply(ll a, ll b, ll m) { return (((a % m) * (b % m)) % m); }

ll modinverse(ll x, ll m)  { return modpow(x, m - 2, m); } //O(logn)

ll eulerfun(ll n)//O(sqrt(n))
{
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

ll getDigitSum(ll n){ ll co=0; while (n>0) { co+=n%10; n=n/10; } return co;}

template<class T> void printVector(const std::vector<T> arr)
{ for (auto i : arr) cout << i << " "; cout << endl; }

template<class T>
void printArray(T arr[], ll n)
{ for (ll i = 0; i < n; i++) cout << arr[i] << " "; cout << endl; }


