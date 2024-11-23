class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<char>>result(box[0].size(),vector<char>(box.size(),'\0'));
        vector<vector<int>>stores;
        for(int i=0;i<box.size();i++)
        {
            int countbox=0;
            vector<int>temp;
            for(int j=0;j<box[i].size();j++)
            {
                if(box[i][j]=='*')
                {
                    temp.push_back(countbox);
                    countbox=0;
                }
                else if(box[i][j]=='#')
                {
                    box[i][j]='.';
                    countbox++;
                }
                else if(box[i][j]=='.')
                {
                    
                    continue;
                }
            }
            temp.push_back(countbox);
            stores.push_back(temp);
        }

        for(int i=box.size()-1;i>=0;i--)
        {
            int k=stores[i].size()-1;
            for(int j=box[0].size()-1;j>=0;j--)
            {
                if(k<0)
                    break;
                int stone=stores[i][k];
                while((j>=0)&&(stone>0))
                {
                    box[i][j]='#';
                    stone--;
                    j--;
                }
                k--;
                while((j>=0)&&(box[i][j]!='*'))
                {
                    j--;
                }
            }
        }
        for(int i=0;i<box.size();i++)
        {
            for(int j=0;j<box[i].size();j++)
            {
                result[j][i]=box[i][j];
            }
        }
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<((result[i].size())/2);j++)
            {
                char c=result[i][j];
                result[i][j]=result[i][result[i].size()-j-1];
                result[i][result[i].size()-j-1]=c;
            }
        }
        return result;
    }
};