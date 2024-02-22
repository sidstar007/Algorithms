#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        char val;
        unordered_map<char, node*> mp;
        bool last;

        node(char val) {
            this->val = val;
            last = false;
        }

        ~node() {
        for (auto& pair : mp) {
            delete pair.second;
        }
    }
};

class Trie {
    node* start;

    public:
        Trie() {
            start = new node('-');
        }

        ~Trie() {
            delete start;
        }

        void add(string s) {
            node* curr = this->start;

            for (char c: s) {
                if (curr->mp.find(c) == curr->mp.end()) {
                    curr->mp[c] = new node(c);
                }
                curr = curr->mp[c];
            }

            curr->last = true;
        }

        bool search(string s) {
            if (s.empty()) return false;

            node* curr = this->start;
            for (char c: s) {
                if (curr->mp.find(c) == curr->mp.end()) {
                    return false;
                }
                else {
                    curr = curr->mp[c];
                }
            }

            return curr->last;
        }
};

int main() {
    Trie myTrie;

    cout << "--- Trie Menu ---" << endl;
    cout << "Enter:\n1 for adding a word\n2 for searching a word\n3 for exit" << endl;

    int inp;

    while (cin >> inp) {
        if (inp == 1) {
            cout << "Enter a word to add: ";
            string s;
            cin >> s;
            myTrie.add(s);
            cout << "Word Added!\n\n";
        }
        else if (inp == 2) {
            cout << "Enter a word to search: ";
            string s;
            cin >> s;
            if (myTrie.search(s)) cout << "Word found!\n\n";
            else cout << "Word not found.\n\n";
        }
        else {
            return 0;
        }
    }

    return 0;
}
