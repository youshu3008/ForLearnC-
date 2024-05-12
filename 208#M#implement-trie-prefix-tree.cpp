#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end;

    TrieNode() : is_end(false) {}
};

class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == NULL) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return false;
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;
            }
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

int main() {
    Trie trie;
    vector<string> operations = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<string> operands = {"", "apple", "apple", "app", "app", "app", "app"};
    vector<bool> output;

    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "Trie") {
            continue;
        } else if (operations[i] == "insert") {
            trie.insert(operands[i]);
            output.push_back(false);
        } else if (operations[i] == "search") {
            output.push_back(trie.search(operands[i]));
        } else if (operations[i] == "startsWith") {
            output.push_back(trie.startsWith(operands[i]));
        }
    }

    for (auto res : output) {
        cout << boolalpha << res << " ";
    }
    cout << endl;

    return 0;
}
