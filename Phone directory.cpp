class TrieNode {
    public:
        char data;
        bool isTerminal;
        TrieNode* children[26];

        TrieNode(char d) {
            this->data = d;

            isTerminal = false;

            for(int i=0; i<26; i++) {
                children[i] = NULL;
            } 
        }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertUtil(child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }
    
    void getNames(TrieNode* curr, string prefix, vector<string>& temp){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        
        for(char ch='a'; ch<='z'; ch++){
            TrieNode* next = curr->children[ch-'a'];
            if(next != NULL){
                prefix.push_back(ch);
                getNames(next,prefix,temp);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getAnswer(string word){
        vector<vector<string>> ans;
        TrieNode* curr = root;
        string prefix = "";
        int i;
        for(i=0; i<word.size(); i++){
            char ch = word[i];
            prefix += ch;
            if(curr->children[ch-'a'] != NULL){
                curr = curr->children[ch-'a'];
                vector<string> temp;
                getNames(curr, prefix, temp);
                ans.push_back(temp);
            }
            else{
                break;
            }
        }
        while(i<word.size()){
            ans.push_back({"0"});
            i++;
        }
        return ans;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie* trie = new Trie();
        for(int i=0; i<n; i++){
            trie->insert(contact[i]);
        }
        return trie->getAnswer(s);
    }
};
