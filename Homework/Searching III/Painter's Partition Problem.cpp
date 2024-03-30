bool ispossible(vector<int> &boards, int k, int mid){
    int paitCount=1;
    int boardsum =0;

    for(int i=0;i<boards.size();i++){
        if(boardsum+boards[i]<=mid){
          boardsum +=boards[i];
        }
        else{
             paitCount++;
            if( paitCount> k||boards[i]>mid){
                return false;
            }
        boardsum =boards[i];
        }
    }
    return true;
}

 

int findLargestMinDistance(vector<int> &boards, int k)

{

   int start=0;
   int sum =0;
   int ans=-1;

   for(int i=0;i<boards.size();i++){
       sum+= boards[i];
   } 
   int end=sum;
   int mid= start+(end-start)/2;

   while(start<=end){
       if (ispossible(boards, k, mid)) {
           ans= mid;
           end = mid - 1;
       }
       else{
           start=mid+1;
       }
       mid = start+(end-start)/2;
   }
   return ans;
}