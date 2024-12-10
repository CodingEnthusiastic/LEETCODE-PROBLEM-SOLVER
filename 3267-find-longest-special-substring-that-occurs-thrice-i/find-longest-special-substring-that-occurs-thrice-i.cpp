class Solution {
public:
    int n;
    string s;
    vector<vector<int>> alphabet;
    inline void table(){
        char prev=s[0]; 
        int f=1;
        for(int i=1; i<n; i++){
            if (s[i]==prev)
                f++;
            else{
                alphabet[prev-'a'].push_back(f);
                f=1;
                prev=s[i];  
            }   
        }
        alphabet[s.back()-'a'].push_back(f);
    }

    void print(){
        int i=0;
        for (auto& vect: alphabet){
            i++;
            if (vect.empty()) continue;
            cout<<char('a'+i-1)<<":";
            for(auto& l:vect)
                cout<<l<<", ";
            cout<<endl;
        }
    }
    inline int maxLen3x(vector<int>& v){
        int sz=v.size();
        switch(sz){
            case 1:
                return v[0]-2;
            case 2:
               
                if (v[0]<v[1]) swap(v[0], v[1]);
                return max(v[0]-2, min(v[0]-1, v[1]));
            default:
                nth_element(v.begin(), v.begin()+2, v.end(),greater{});
                if (v[0]<v[1]) swap(v[0], v[1]);
            //    cout<<"sz="<<sz<<","<<v[0]<<","<<v[1]<<","<<v[2]<<endl;
                return max({v[2], min(v[0]-1, v[1]), v[0]-2});
        }
    }
    int maximumLength(string& s) {
        this->s=s;
        n=s.size();
        alphabet.assign(26, vector<int>());
        table();
        int ans=-1;
        for (auto& lens: alphabet){
            if (lens.empty()) continue;
            ans=max(ans,  maxLen3x(lens));
        }
        return ans<=0?-1:ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();