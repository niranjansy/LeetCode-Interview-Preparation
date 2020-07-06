// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool Search(vector<vector<char>> board, int i, int j, string word, int k)
    {
        if(k >= word.size())
            return true;
        
        char ch = word[k];
        
        bool res = false;
        
        if((i+1)<board.size() && board[i+1][j]==ch)
        {
            char c = board[i+1][j];
            board[i+1][j] = '.';
            res = Search(board, i+1, j, word, k+1);
            board[i+1][j] = c;
            if(res == true)
                return true;
        }
        
        if((i-1)>=0 && board[i-1][j]==ch)
        {
            char c = board[i-1][j];
            board[i-1][j] = '.';
            res = Search(board, i-1, j, word, k+1);
            board[i-1][j] = c;
            if(res == true)
                return true;
        }
        
        if((j+1)<board[i].size() && board[i][j+1]==ch)
        {
            char c = board[i][j+1];
            board[i][j+1] = '.';
            res = Search(board, i, j+1, word, k+1);
            board[i][j+1] = c;
            if(res == true)
                return true;
        }
        
        if((j-1)>=0 && board[i][j-1]==ch)
        {
            char c = board[i][j-1];
            board[i][j-1] = '.';
            res = Search(board, i, j-1, word, k+1);
            board[i][j-1] = c;
            if(res == true)
                return true;
        }
        
        return false;
            
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = false;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    char c = board[i][j];
                    board[i][j] = '.';
                    flag = Search(board, i, j, word, 1);
                    board[i][j] = c;
                    if(flag == true)
                        return flag;
                }
                    
            }
        }
        return flag;
    }
};