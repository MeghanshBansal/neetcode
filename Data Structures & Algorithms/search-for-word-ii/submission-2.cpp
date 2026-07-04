class Solution {
  public: struct Node {
    unordered_map < char, Node * > links;
    bool is_word = false;
    string * word_ptr = nullptr;

    Node() =
      default; // Use default constructor

    ~Node() {
      for (auto
        const & [key, val]: links) {
        delete val;
      }
    }

    bool contains(char ch) {
      return links.count(ch);
    }

    void set_link(char ch, Node * node) {
      links[ch] = node;
    }

    Node * get_link(char ch) {
      return links[ch];
    }
  };

  class Trie {
    public: Node * root;
    Trie() {
      root = new Node();
    }

    ~Trie() {
      delete root; // This will recursively call Node destructors
    }

    void insert(const string & word) {
      Node * curr = root;
      for (char ch: word) {
        if (!curr -> contains(ch)) {
          curr -> set_link(ch, new Node());
        }
        curr = curr -> get_link(ch);
      }
      curr -> is_word = true;
      curr -> word_ptr = new string(word);
    }
  };

  bool visited[12][12];

  void dfs(vector < vector < char >> & board, int r, int c, int ROWS, int COLS, Node * node,
    unordered_set < string > & result_words) {
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c] || !node -> contains(board[r][c])) {
      return;
    }

    char current_char = board[r][c];
    Node * next_node = node -> get_link(current_char);

    if (next_node -> is_word) {
      if (next_node -> word_ptr != nullptr) {
        result_words.insert( * (next_node -> word_ptr));
      }
    }

    visited[r][c] = true;

    dfs(board, r + 1, c, ROWS, COLS, next_node, result_words);
    dfs(board, r - 1, c, ROWS, COLS, next_node, result_words);
    dfs(board, r, c + 1, ROWS, COLS, next_node, result_words);
    dfs(board, r, c - 1, ROWS, COLS, next_node, result_words);

    visited[r][c] = false;
  }
  vector < string > findWords(vector < vector < char >> & board, vector < string > & words) {
    Trie * trie = new Trie();
    for (const string & word: words) {
      trie -> insert(word);
    }

    int ROWS = board.size();
    if (ROWS == 0)
      return {};
    int COLS = board[0].size();
    if (COLS == 0)
      return {};

    for (int i = 0; i < ROWS; ++i) {
      for (int j = 0; j < COLS; ++j) {
        visited[i][j] = false;
      }
    }

    unordered_set < string > result_words_set;

    for (int r = 0; r < ROWS; ++r) {
      for (int c = 0; c < COLS; ++c) {
        if (trie -> root -> contains(board[r][c])) {
          dfs(board, r, c, ROWS, COLS, trie -> root, result_words_set);
        }
      }
    }

    vector < string > final_ans(result_words_set.begin(), result_words_set.end());

    delete trie;

    return final_ans;
  }
};