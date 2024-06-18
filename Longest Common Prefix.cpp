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

    int getChildCount(TrieNode* temp){
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(temp->children[i] != NULL){
                cnt++;
            }
        }
        return cnt;
    }

    void longestCommonPrefix(string input, string& ans){
        TrieNode* temp = root;

        for(int i=0; i<input.size(); i++){
            char ch = input[i];
            if(getChildCount(temp) == 1 && temp->isTerminal == false){
                ans.push_back(ch);
                temp = temp->children[ch-'a'];
            }
            else{
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();
        for(string i:strs){
            trie->insert(i);
        }

        string ans = "";
        trie->longestCommonPrefix(strs[0], ans);
        return ans;
    }
};
