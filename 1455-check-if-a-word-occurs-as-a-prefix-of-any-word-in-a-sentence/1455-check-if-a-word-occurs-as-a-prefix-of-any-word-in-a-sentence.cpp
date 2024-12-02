class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word_ind = 1 ; 

        int pos = 0 ; 

        int n =  sentence.size() ; 

        int pref = searchWord.size() ; 

        while (pos < n ) { 

            int end = pos ; 
            while (end < n && sentence[end] != ' ') end++ ; 

            if (end - pos >= pref && sentence.substr(pos , pref) == searchWord) 
             return word_ind  ; 

             pos = end +1 ; 
             word_ind++ ; 
        }
        return -1; 
    }
};