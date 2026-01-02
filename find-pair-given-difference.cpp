 class Solution {
  public:
    bool findPair(vector<int> &arr, int n) {
        
    unordered_map<int,int>freq;
    
    for(int nums:arr){
        freq[nums]++;
        
        if(n==0 && freq[nums]>1){
            return 1;
     }
     }
     
     if(n==0){
         return 0;
     }
     
     for(int i=0;i<arr.size();i++){
         int sum=n+arr[i];
         
        if(freq.find(sum) != freq.end()){
            return 1;
        }

     }
     return 0;
    }
};
