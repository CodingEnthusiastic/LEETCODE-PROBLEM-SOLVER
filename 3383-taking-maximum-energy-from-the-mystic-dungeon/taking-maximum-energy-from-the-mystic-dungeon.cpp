class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int maxi=energy[n-1];
        for(int i=n-1;i>=n-k;i--)
        {
            maxi=max(maxi,energy[i]);
        }
        for(int i=n-k-1;i>=0;i--)
        {
            energy[i]=energy[i+k]+energy[i];
            maxi=max(maxi,energy[i]);
        }

        return maxi;
    }
};