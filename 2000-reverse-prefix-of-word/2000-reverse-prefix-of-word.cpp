class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int index=-1;
        
        for(int i=0;i<word.size();i++)
        {
            if(ch==word[i])
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
        reverse(word.begin(),word.begin()+index+1);
        return word;    
    }
};