    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<string, string> pss;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<pii> vii;
    typedef vector<ll> vl;
    typedef vector<vl> vvl;
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t; 
        
        ll dp[100005];
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(ll i=2; i<100005; i++)
            dp[i] = ((dp[i-1]% 998244353) + (dp[i-2]% 998244353))% 998244353;
        
        cin >> t;
        while(t--)
        {
            string s;
            cin >> s;
            
            ll n = s.size();
            vl v;
            
            s = s[0] + s + s[s.size()-1];
            
            for(ll i=0; i<s.size()-1; i++){
                if(s[i] == s[i+1])
                    v.push_back(i+1);
            }
            
            ll result = 1;
            
            for(ll i=0; i<v.size()-1; i++){
                ll num = v[i+1] - v[i];
                result = ((result% 998244353) * (dp[num + 1]% 998244353))% 998244353;
            }
            
            cout<<result<<endl;
            
        }
     
        return 0;
    }