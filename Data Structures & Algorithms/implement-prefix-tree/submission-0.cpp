struct Node {
    Node *links[26];
    bool flag = false;

    bool contains(char ch) {
        return this->links[ch-'a'] != nullptr;
    }

    void setNode(char ch, Node *node){
        this->links[ch - 'a'] = node;
    }

    Node* getNext(char ch) {
        return this->links[ch -'a'];
    }

    void setFlag(){
        this->flag = true;
    }

    bool isFlag() {
        return this->flag;
    }
};

class PrefixTree {
private: Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = this->root;
        for(int i = 0; i < word.length(); i++)
        {
            if (!node->contains(word[i])){
                node->setNode(word[i], new Node());
            }

            node = node->getNext(word[i]);
        }

        node->setFlag();
    }
    
    bool search(string word) {
        Node *node = this->root;        
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->contains(word[i])) return false; 
            node = node->getNext(word[i]);
        }

        return node->isFlag();
    }
    
    bool startsWith(string prefix) {
        Node *node = this->root; 
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->contains(prefix[i])) return false; 
            node = node->getNext(prefix[i]);
        }        

        return true; 
    }
};
