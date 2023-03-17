class Trie {
public:
    
    class TrieNode{
        public:
        TrieNode* child[26];
        bool isTerminal;
    };
    TrieNode* node;
    
    Trie() {
        node=new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* curr=node;
        for(char c: word){
            //if does not exist
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new TrieNode();
            }
             curr=curr->child[c-'a'];
        }
        curr->isTerminal=true;
    }
    
    bool search(string word) {
        TrieNode* curr=node;
        for(char c:word){
            if(curr->child[c-'a']==NULL) return false;
            else curr=curr->child[c-'a'];
        }
         if(curr->isTerminal==true) return true;
        return false;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=node;
    for(char c: prefix){
        if(curr->child[c-'a']==NULL)return false;
        curr=curr->child[c-'a'];
    }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */