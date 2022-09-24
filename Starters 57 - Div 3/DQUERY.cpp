#include <bits/stdc++.h> 
using namespace std;

#define int long long
bool notPrime[100001];
vector<int> pfac[100001];

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 2;i<=100000;i++){
            
        if(notPrime[i]) continue;
            
        for(int j = i;j<=1e5;j+=i){
            notPrime[j] = true;
            pfac[j].push_back(i);
        }
	}
    
	int t;
	cin>>t;
	while(t--)
	{   
	    
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    
	    for(int i=0; i<n; i++) cin>>a[i];
	    
	    int pref1[n];
	    pref1[0] = a[0];
	    
	    for(int i=1; i<n; i++) 
	        pref1[i] = pref1[i-1] + a[i];
	    
	    vector<int> pos[100001];
	    
	    for(int i=0; i<n; i++){
	        for(int j: pfac[a[i]]){
	            pos[j].push_back(i);
	        }
	    }
	    
	    vector<int> pfsum[100001], pref2[100001];
	    
	    for(int i=0; i<=100000; i++){
	        if(pos[i].size() == 0) continue;
	        
	        pfsum[i].push_back(a[pos[i][0]]);
	        
	        for(int j=1; j<pos[i].size(); j++){
	            pfsum[i].push_back(a[pos[i][j]] + pfsum[i][j-1]);
	        }
	        
	        vector<int> temp;
	        
	        for(int j: pos[i]) 
	            temp.push_back(a[j]);
	            
	        sort(temp.begin(), temp.end());
	        pref2[i].push_back(temp[temp.size()-1]);
	        
	        for(int j=1; j<temp.size(); j++)
	            pref2[i].push_back(pref2[i][j-1] + temp[temp.size()-1-j]);
	        
	    }
	    
	    int q;
	    cin>>q;
	    while(q--){
	        
	        int p, k;
	        cin>>p>>k;
	        
	        int ans = pref1[k-1];
	        
	        int count = lower_bound(pos[p].begin(), pos[p].end(), k) - pos[p].begin();
	        
	        if(count>0){
	            ans-= pfsum[p][count-1];
	            ans+= pref2[p][count-1];
	        }
	        
	        cout<<ans<<endl;
	    }
	    
	}

}
