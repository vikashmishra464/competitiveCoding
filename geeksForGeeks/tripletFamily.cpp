class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               int sum=arr[i]+arr[j];
               for(int k=j+1;k<n;k++){
                   if(arr[k]==sum){
                       return true;
                   }
               }
           }
       }
       return false;
    }
};