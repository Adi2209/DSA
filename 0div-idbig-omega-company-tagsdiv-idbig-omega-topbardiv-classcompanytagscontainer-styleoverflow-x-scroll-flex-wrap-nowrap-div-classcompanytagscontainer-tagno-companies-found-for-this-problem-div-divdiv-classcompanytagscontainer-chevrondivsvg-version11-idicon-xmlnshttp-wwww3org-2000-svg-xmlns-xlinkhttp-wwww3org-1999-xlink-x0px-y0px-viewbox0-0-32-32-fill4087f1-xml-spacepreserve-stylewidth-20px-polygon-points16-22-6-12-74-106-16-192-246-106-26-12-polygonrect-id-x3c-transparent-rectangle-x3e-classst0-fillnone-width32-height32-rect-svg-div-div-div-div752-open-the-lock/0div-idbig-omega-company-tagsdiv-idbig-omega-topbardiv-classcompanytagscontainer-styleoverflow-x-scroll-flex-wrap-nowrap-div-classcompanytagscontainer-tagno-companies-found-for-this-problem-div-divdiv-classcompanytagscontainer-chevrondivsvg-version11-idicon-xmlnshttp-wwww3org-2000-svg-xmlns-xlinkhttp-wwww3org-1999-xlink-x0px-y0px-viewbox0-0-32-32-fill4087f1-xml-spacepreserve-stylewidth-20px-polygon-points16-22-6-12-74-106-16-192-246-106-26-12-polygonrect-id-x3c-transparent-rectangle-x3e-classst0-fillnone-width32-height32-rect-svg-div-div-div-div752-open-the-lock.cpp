class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> bfs;
        unordered_set<string> hash(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        
        if (hash.find("0000") != hash.end())
            return -1;
        
        int depth = 0;
        bfs.push("0000");
		visited.insert("0000");
        
        while(!bfs.empty())
        {
            int siz=bfs.size();
            
            for(int k=0;k<siz;k++)
            {
                string current_stage = bfs.front();
                bfs.pop();

                if (current_stage == target)
                {
                    return depth;
                }


                for (int i = 0; i < 4; i++)
                {
                    char temp = current_stage[i];
                    current_stage[i] = temp == '9' ? '0' : temp + 1;
                    if (hash.find(current_stage) == hash.end() && visited.find(current_stage)==visited.end())
                    {
                        bfs.push(current_stage);
                        visited.insert(current_stage);
                    }


                    current_stage[i] = temp == '0' ? '9' : temp - 1;
                    if (hash.find(current_stage) == hash.end() && visited.find(current_stage)==visited.end())
                    {
                        bfs.push(current_stage);
                        visited.insert(current_stage);
                    }
                    current_stage[i] = temp;
                }
            }
            
           depth++;
        }
        return -1;
    }
};