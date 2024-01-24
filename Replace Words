class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char d){
        data = d;
        isTerminal = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.size() == 0){
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

        insertUtil(child, word.substr(1));
    }

    void insert(string word){
        insertUtil(root, word);
    }

    string check(string word){
        TrieNode* curr = root;
        string str = "";
        
        for(char ch:word){
            str += ch;
            if(curr->children[ch-'a'] != NULL){
                curr = curr->children[ch-'a'];
                if(curr->isTerminal){
                    return str;
                }
            }
            else{
                break;
            }
        }
        return word;
    }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for(string i:dictionary){
            trie->insert(i);
        }

        stringstream s(sentence);
        string word = "";
        string ans = "";
        while(s >> word){
            ans += trie->check(word);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
