#include <iostream>

using namespace std;

#define ll             long long int 
#define ulli           unsigned long long int 
#define li             long int 
#define ff(i,a,b)      for(int i=a;i<=b;i++)
#define fb(i,b,a)      for(int i=b;i>=a;i--)
#define w(t)           while(--t >= 0)
#define l(s)           s.length()
#define ci(n)          cin>>n;
#define fast           ios_base::sync_with_stdio(false);
#define sa(a,n)        sort(a,a+n)
#define sv(v)          sort(v.begin(),v.end())
#define cy             cout<<"YES\n"
#define cn             cout<<"NO\n"
#define nl             cout<<"\n"
#define minus          cout<<"-1\n";
#define vi             vector<int>
#define pb             push_back
#define tc             int t; cin>>t;
#define pp             pair<int,int>
#define input(a,n)     for(int i=0;i<n;i++) cin>>a[i];
#define mod            1000000007
#define co(n)          cout<<n;
#define ret            return 0
#define mi             map<int,int>

ll ncr(ll n, ll k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

ll solution (ll n, ll m, ll t) {
    int ans = 0;

    for (int i = 4; i <= n && i <= t - 1; i++) {
        int j = t - i;
        if (j >= 1 && j <= m)
            ans += (ncr(n, i) * ncr(m, j));
    }

    return ans;
}


int main()
{
    ll n, m, t;
    // cin >> n >> m >> t;
    n = 5, m = 2, t = 5;
    cout << solution(n, m, t);

    // cout << ncr(5, 4);

    return 0;
}