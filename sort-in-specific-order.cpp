class Solution {
  public:
    static bool compare(int &a, int &b) 
    {
        if(a & 1) 
        {
            if((b & 1) && a < b) 
            return false;
            return true;
        } 
        else 
        {
            if(b & 1) 
            return false;
            return a < b;
        }
    }
    void sortIt(vector<int>& arr) {
        // code here
         sort(arr.begin(), arr.end(), compare);
    }
};
