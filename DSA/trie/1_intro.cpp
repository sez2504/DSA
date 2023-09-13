#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode ** children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for (int i=0 ; i<26 ; i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
    
};

class Trie{
    TrieNode * root;

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord (TrieNode * root ,string word){
        if (word.length()==0){
            root->isTerminal=true;
            return;
        }

        //small calculation
        int index = word[0]-'a';
        TrieNode * child;
        if (root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursive call
        insertWord(child , word.substr(1));
    }

    void insertWord(string word){
        insertWord(root , word);
    }

    bool search(TrieNode * root ,string word){
        if (word.length()==0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        if (root->children[index]==NULL){
            return false;
        }
        else{
            return search(root->children[index] , word.substr(1));
        }
    }

    bool search ( string word ){
        return search(root , word);
    }

    void removeWord(TrieNode * root , string word){
        if (word.length()==0){
            root->isTerminal=false;
            return;
        }
        int i = word[0]-'a';
        if (root->children[i]==NULL){
            return;
        }
        else{
            removeWord(root->children[i] , word.substr(1));
        }

        //check if child useless
        TrieNode * child = root->children[i];
        if (child->isTerminal==false){
            for (int i=0 ; i<26 ; i++){
                if (child -> children != NULL){
                    return;
                }
            }
            delete child;
            root->children[i]=NULL;
        }
    }

    void removeWord(string word){
        removeWord(root , word);
    }
};

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("howare");
    t.insertWord("ants");

    cout<<t.search("ants")<<endl;

    t.removeWord("ants");
    cout<<t.search("ants")<<endl;

    return 0;
}