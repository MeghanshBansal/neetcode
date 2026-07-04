struct Node 
{
	Node *links[26];
	bool flag = false;

	bool contains(char ch) 
	{
		return this->links[ch - 'a'] != nullptr; 
	}

	void setNext(char ch, Node *node) 
	{
		this->links[ch - 'a'] = node;
	}

	Node* getNext(char ch) 
	{
		return this->links[ch - 'a'];
	}
	
	void setFlag() 
	{
		this->flag = true; 
	}

	bool isFlag() 
	{
		return this->flag;
	}
};

class WordDictionary 
{
	private: 
		Node *root; 
	public:
		WordDictionary()
		{
			this->root = new Node();
		}

		void addWord(string word) {
        Node *node = this->root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->contains(word[i])) {
                node->setNext(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->setFlag();
    }

    bool search(string word) {
        Node *node = this->root;
        return dfs(0, word, node);
    }

    bool dfs(int index, string word, Node* node) {
        if (node == nullptr) return false; 
        if (index == word.length()) return node->isFlag(); 

        if (word[index] == '.') {  
            for (int i = 0; i < 26; i++) {
                Node *child = node->links[i];
                if (dfs(index + 1, word, child)) {
                    return true;
                }
            }
        } else {
            if (node->contains(word[index])) {
                return dfs(index + 1, word, node->getNext(word[index]));
            }
        }
        return false;
    }
};
