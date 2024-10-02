#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];
    bool flag = false;

public:
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (const auto ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (const auto ch : word)
        {
            if (!node->get(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (const auto ch : prefix)
        {
            if (!node->get(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   
    cout << trie.search("app") << endl;     
    cout << trie.startsWith("app") << endl; 

    trie.insert("app");
    cout << trie.search("app") << endl; 

    return 0;
}
