#include<iostream>
using namespace std;

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

    void insert(string word){
        insertUtil(root, word);
        cout<<word<<" -> Insert Sucessfully"<<endl;
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode* root, string word){

        if(word.length() == 0){

            if(root->isTerminal){
                root->isTerminal = false;
                return true;
            }
            else{
                return false;
            }
            
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return deleteUtil(child, word.substr(1));
    }

    bool Ddelete(string word){
        return deleteUtil(root, word);
    }

};

int main(){
    Trie* trie = new Trie();

    trie->insert("code");
    trie->insert("coding");
    trie->insert("codemonk");
    trie->insert("coder");
    trie->insert("codee");

    cout << trie->search("code") << endl;
    cout << trie->search("coding") << endl;
    cout << trie->search("codemonk") << endl;
    cout << trie->search("coder") << endl;
    cout << trie->search("codee") << endl;
    cout << trie->search("codi") << endl;
    cout << trie->search("cody") << endl;

    cout << trie->Ddelete("code") << endl;
    cout << trie->search("code") << endl;

    return 0;
}
