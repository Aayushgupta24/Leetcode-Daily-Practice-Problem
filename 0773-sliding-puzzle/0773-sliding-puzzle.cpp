class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>dir = {{1,3} , {0,2,4} , {1,5} , {0,4}, {1,3,5} , {2,4}} ; 

        string tar = "123450" ; 

        string startdate ; 

        for ( int i =0 ; i < board.size() ; i++){ 
             for ( int j= 0; j < board[0].size() ; j++) { 
                startdate += to_string(board[i][j]); 
             }
        }
        unordered_set<string>vis ; 

        queue<string>q ; 
        q.push(startdate) ; 
        vis.insert(startdate) ; 

        int moves = 0 ; 

      while (!q.empty()) { 
         int size = q.size() ; 

         while (size-- > 0) { 
             string curr_state = q.front() ; 
             q.pop() ; 

             if (curr_state == tar) 
             return moves ; 

              int zero_pos = curr_state.find('0'); 

              for( int pos : dir[zero_pos]) { 
                 string next_pos = curr_state ; 

                 swap(next_pos[zero_pos] , next_pos[pos]) ; 

                 if (vis.count(next_pos)) 
                 continue ; 
                 vis.insert(next_pos); 
                 q.push(next_pos)  ; 

              }
         }
         moves++ ; 
      }
      return -1 ;
    }
};