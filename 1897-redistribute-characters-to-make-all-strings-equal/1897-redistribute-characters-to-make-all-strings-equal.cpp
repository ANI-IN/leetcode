class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        vector<int> arr(26,0);
        int count=0;
        for(int i=0;i<words.size();i++)
        {   
            string str=words[i];
            count++;
            for(int j=0;j<str.size();j++)
            {
                arr[str[j]-'a']++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]%count!=0)
                return false;  
        }
        return true;
    }
};