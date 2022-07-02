bool isPossible(vector<int> &stalls, int k,int dist,int n){
	
	int cnt=1;
	int firstCow=stalls[0];
	for(int i=1;i<n;i++){
		if(stalls[i]-firstCow >=dist){
			cnt++;
			firstCow=stalls[i];
		}
		if(cnt==k) return true;
	}
	
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
	//sorting the array
	sort(stalls.begin(),stalls.end());
	int s=1;
	
	int e=-1;
	for(int i=0;i<n;i++)  e=max(e,stalls[i]);
	int maxDis=0;
	while(s<=e){
		int mid=s+(e-s)/2;
		
		if(isPossible(stalls,k,mid,n)){
			maxDis=mid;
			s=mid+1;
		}
		else
			e=mid-1;
	}
	return maxDis;
}