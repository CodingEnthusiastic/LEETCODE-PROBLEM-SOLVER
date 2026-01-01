class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int index=digits.size()-1;
        while(index>=0&&carry==1)
        {
            digits[index]=digits[index]+1;
            if(digits[index]>9)
            {
                carry=1;
                digits[index]=digits[index]%10;
            }
            else
                carry=0;
            index--;
        }
        if(carry==1)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(carry);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};
