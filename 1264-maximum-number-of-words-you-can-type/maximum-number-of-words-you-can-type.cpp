class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool flag=false;
        int count=0;
        vector<bool>arr(26,false);
        for(int i=0;i<brokenLetters.size();i++)
        {
            arr[brokenLetters[i]-'a']=true;
        }
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
                if(flag==false)
                count++;
                flag=false;
            }
            else
            {
                if(arr[text[i]-'a']==true)
                {
                    flag=true;
                }
            }



        }

        if(flag==false)
        count++;
        return count;
    }
};