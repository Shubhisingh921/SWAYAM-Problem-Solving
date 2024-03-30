bool predicate(int mid,vector<int>& arr,int k){
   int cnt = 1;
   int i = 0;
   int j = 1;
   while(j<arr.size()){
   	if(arr[j]-arr[i] >= mid){
   		if(++cnt==k) 
                return true;
   		i=j;
   	}
   	j++;
   }
   return false;
}
 
void solve(){	
   
   int n,k; 
   cin>>n>>k;
   vector<int> arr(n);
   for(i=0;i<n;i++){
       cin>>arr[i];
    }
   sort(all(arr));
   
 
   int low = 0;
   int high = 1e9;
   int ans = 0;
   while(low<=high){
   	int mid = (low+high)/2;
   	if(predicate(mid,arr,k)){
   		low=mid+1;
   		ans=mid;
   	}
        else{
   		high=mid-1;
   	}
   }
 
   cout<<ans<<endl;
 
}
 