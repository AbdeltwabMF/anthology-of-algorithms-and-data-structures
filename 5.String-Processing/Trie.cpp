class Trie {
private:
  Trie* children[26]; // Pointer = 8 Byte; 8*26 = 208 Byte
  int prefixs, words; // 8 Byte
  bool iseow; // 1 Byte
  char cur_letter; // 1 Byte
  vector <string> lex;
  
public:
  Trie(char lett = '\0') {
    memset(children, 0, sizeof(children));
    prefixs = words = 0;
    iseow = false;
    cur_letter = lett;
  }

  void insert(string &str) { // O(l)
    Trie* cur = this;
    int inx, strsz = str.size();
    for(int i = 0; i < strsz; ++i) {
      inx = str[i] - 'a';      
      if(cur->children[inx] == nullptr)
	cur->children[inx] = new Trie(str[i]);

      cur = cur->children[inx];
      cur->prefixs++;
    }
    cur->iseow = true;
    cur->words++;
  }
  
  int search_word(string &str) { // O(l)
    Trie* cur = this; 
    int inx, strsz = str.size();  
    for(int i = 0; i < strsz; ++i) {
      inx = str[i] - 'a';
      if(cur->children[inx] == nullptr) {
	return 0;
      }
      cur = cur->children[inx];
    }
    return cur->words;
  }

  int search_prefix(string &str) { // O(l)
    Trie* cur = this;
    int inx = 0, strsz = str.size();
    for(int i = 0; i < strsz; ++i) {   
      inx = str[i] - 'a';
      if(cur->children[inx] == nullptr) {
	return 0;
      }
      cur = cur->children[inx];
    }
    return cur->prefixs;
  }

  bool erase(string &str) {
    if(!search_word(str))
      return false;

    Trie* cur = this;
    int inx, strsz = str.size();
    for(int i = 0; i < strsz; ++i) {
      inx = str[i] - 'a';
      if(--cur->children[inx]->prefixs == 0) {
	cur->children[inx] = nullptr;
	return true;     
      }
      cur = cur->children[inx];
    }
    if(--cur->words == 0) {
      cur->iseow = false;
    }
    return true;
  }

  void dfs(Trie* node, string s) {
    if(node->iseow) {
      lex.emplace_back(s);
    }

    for(int j = 0; j < 26; ++j)
      if(node->children[j] != nullptr) {
	dfs(node->children[j], s + string(1, node->children[j]->cur_letter));
      }
  }
  
  vector <string> lex_order() {
    lex.clear();
    Trie* cur = this;
    for(int i = 0; i < 26; ++i) if(cur->children[i] != nullptr) {
	dfs(cur->children[i], string(1, cur->children[i]->cur_letter));
      }
    return lex;
  }
};

