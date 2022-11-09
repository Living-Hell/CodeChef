    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
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
        long long int t;        
        cin >> t;
        while(t--)
        {
            ll a, b;
            cin >> a >> b;
            
            int flag=1;
            
            while(b > 1){
                ll c = __gcd(a,b);
                b /= c;
                if(c == 1 && b>1 ){
                    flag=0; 
                    break;
                }
            }
            
            if(!flag) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            
        }
     
        return 0;
    }