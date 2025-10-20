class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int score=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="X++"||operations[i]=="++X")
                score++;
            else
                score--;
        };
        return score;
    }
};
