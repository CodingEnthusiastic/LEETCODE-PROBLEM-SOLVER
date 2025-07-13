class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int n=players.size();
        int i=0;
        int j=0;

        int count=0;
        while(i<n&&j<trainers.size())
        {
            if(trainers[j]<players[i])
            {
                j++;
            }
            else
            {
                count++;
                i++;
                j++;
            }
        }


        return count;
    }
};