/*
Leetcode- https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    class node{
    public:
        bool EndofWord;
        map<char,node*> mp;
    };
    node* root;
    WordDictionary() {
        root = new node();
        root->EndofWord=false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(word=="")return;
        
        node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->mp.find(word[i]) == tmp->mp.end())
                tmp->mp[word[i]] = new node();
            tmp = tmp->mp[word[i]];            
        }
        tmp->EndofWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word=="")return true;
        node* tmp=root;
        return traverse(tmp,word,0);        
    }
    
    bool traverse(node *ptr, string word,int index){
        if(index==word.size())
            return ptr->EndofWord;
        if(word[index]!='.'){
            if(ptr->mp.find(word[index])==ptr->mp.end())
                return false;
            ptr = ptr->mp[word[index]];
            return traverse(ptr,word,index+1);            
        }
        for(auto p: ptr->mp){
            if(traverse(p.second,word,index+1))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
