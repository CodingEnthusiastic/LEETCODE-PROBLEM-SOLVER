class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer;
        int j = 0;
        int count = (j < spaces.size()) ? spaces[0] : -1;

        for(int i = 0; i < s.size(); i++) {
            if(count == i) {
                answer += ' ';
                j++;
                if(j < spaces.size()) {
                    count = spaces[j];
                } else {
                    count = -1;  // No more spaces to insert
                }
            }
            answer += s[i];
        }
        return answer;
    }
};
