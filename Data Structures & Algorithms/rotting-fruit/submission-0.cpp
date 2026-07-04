class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) return -1;
       int rows = grid.size();
       int cols = grid[0].size();

        int count_fresh = 0;
        int time = 0;
       queue<pair<int, int>> q;
       for (int i = 0; i < rows; i++)
       {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                

                if (grid[i][j] == 1)
                    count_fresh +=1 ;
            }
       }

       if (count_fresh == 0) return 0;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!q.empty())
        {
            int s = q.size();
            int fruit_rot_at_this_moment = false; 

            while (s--)
            {
                auto value = q.front();
                q.pop();

                int r = value.first;
                int c = value.second;

                for (int i = 0; i < 4; i++)
                {
                    int new_r = r + dr[i];
                    int new_c = c + dc[i];

                    if (new_r < 0 || new_r >= rows  || new_c < 0 || new_c >= cols) continue;
                    if (grid[new_r][new_c] == 1)
                    {
                        grid[new_r][new_c] = 2;
                        count_fresh -= 1;
                        q.push({new_r, new_c});
                        fruit_rot_at_this_moment = true;
                    }
                }
            }
            if (fruit_rot_at_this_moment && count_fresh >= 0)
                time +=1 ;
        }
        
        if (count_fresh == 0) return time;
        return -1;
    }
};
