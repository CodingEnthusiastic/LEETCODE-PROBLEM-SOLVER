class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int N=1;
        int count=0;
        while(N<=n)N<<=1;
        vector<int> seg(N<<1);

        for(int i=0;i<n;i++){
            seg[N+i]=baskets[i];
                 
        }
        for(int i=N-1;i>0;i--){
            seg[i]=max(seg[2*i],seg[2*i+1]);   
        }
       for(int i:fruits){
        int idx=1;
        if(seg[idx]<i){
            count++;
            continue;
        }
        while(idx<N){
            if(seg[2*idx]>=i)idx=2*idx;
            else idx=2*idx+1;
        }
        seg[idx]=-1;
        while(idx>1){
            idx>>=1;
            seg[idx]=max(seg[idx*2],seg[idx*2+1]);
        }
       }
       return count;
    }
};