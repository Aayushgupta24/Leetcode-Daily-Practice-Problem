class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mpp; 

        for(char ch : s) 
        mpp[ch]++ ; 

        priority_queue<char>pq ; 

        for (auto& [ch, cnt] : mpp) 
        pq.push(ch) ; 

        string res ; 

        while(!pq.empty()) { 
             char ch = pq.top() ; 
              pq.pop() ; 
              int cnt = mpp[ch] ; 

              int use = min(cnt , repeatLimit) ; 
              res.append(use ,ch) ; 

              mpp[ch]  -= use ; 

              if(mpp[ch] > 0 && !pq.empty()) { 
                 char nextch = pq.top() ; 
                 pq.pop() ; 

                 res.push_back(nextch) ; 
                 mpp[nextch]-- ; 

                 if (mpp[nextch] > 0) 
                 pq.push(nextch) ; 

                 pq.push(ch) ; 
              }
        }
        return res ; 
    }
};