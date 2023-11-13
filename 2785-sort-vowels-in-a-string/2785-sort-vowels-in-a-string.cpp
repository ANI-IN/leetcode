class Solution {
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
        || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
public:
    string sortVowels(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(auto it : s)
        {
            if(isVowel(it))
                m[it]++;
        }
       
        string a="AEIOUaeiou";
        string ans="";
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(!isVowel(s[i]))
                ans.push_back(s[i]);
            else
            {
                while(m[a[j]]==0)
                    j++;
                
                ans+=a[j];
                m[a[j]]--;
            }
        }
        return ans;
        
    }
};