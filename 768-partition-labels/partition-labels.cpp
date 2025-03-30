class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26, 0);
        for (int i = 0; i < s.size(); ++i) 
        {
            last[s[i] - 'a'] = max(i,last[s[i]-'a']);
        }

        int partend = 0, partstart = 0;
        vector<int> partition;
        for (int i = 0; i < s.size(); ++i) 
        {
            partend = max(partend, last[s[i] - 'a']);
            if (i == partend) 
            {
                partition.push_back(i - partstart + 1);
                partstart = i + 1;
            }
        }
        return partition;
    }
};