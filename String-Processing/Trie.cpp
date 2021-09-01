class Trie {
private:
  Trie* children[26]; // Pointer = 8 Byte; 8*26 = 208 Byte
  int prefixs, words; // 8 Byte
  bool iseow; // 1 Byte
  char cur_letter; // 1 Byte
  vector <string> lex;
  priority_queue <pair <int, string>, vector <pair <int, string>>, greater <pair <int, string>>> occurrence; // small at top
  
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

private:
  void dfs(Trie* node, string s) { // lex order dfs -> traverse all the strings starting from root
    if(node->iseow) {
      lex.emplace_back(s);
    }

    for(int j = 0; j < 26; ++j)
      if(node->children[j] != nullptr) {
	dfs(node->children[j], s + string(1, node->children[j]->cur_letter));
      }
  }

  void dfs2(Trie* node, string s) { // autocomplete dfs -> traverse all the strings starting from the end of the given prefix
    if(node->iseow) {
      if(occurrence.size() < 10) {
	occurrence.push(make_pair(node->words, s));
      } else {
	if(node->words > occurrence.top().first) {
	  occurrence.pop();
	  occurrence.push(make_pair(node->words, s));
	}
      }
    }

    for(int i = 0; i < 26; ++i) if(node->children[i] != nullptr) {
	dfs2(node->children[i], s + string(1, node->children[i]->cur_letter));
      }    
  }

public:
  vector <string> lex_order() { // all strings in lexicographical order
    lex.clear();
    Trie* cur = this;
    for(int i = 0; i < 26; ++i) if(cur->children[i] != nullptr) {
	dfs(cur->children[i], string(1, cur->children[i]->cur_letter));
      }
    return lex;
  }

  void autocomplete(string &pref) { // suggest top ten words with max frequency
    if(!search_prefix(pref))
      return;

    Trie* cur = this;
    int inx, presz = pref.size();
    for(int i = 0; i < presz; ++i) {
      inx = pref[i] - 'a';
      cur = cur->children[inx];
    }
    
    for(int i = 0; i < 26; ++i) if(cur->children[i] != nullptr) {
	dfs2(cur->children[i], string(1, cur->children[i]->cur_letter));
      }
    
    vector <string> st;
    while(!occurrence.empty()) {
      st.emplace_back(pref + occurrence.top().second);
      occurrence.pop();
    }
    if(cur->iseow) {
      st.emplace_back(pref);
    }
    while(!st.empty()) {
      cout << st.back() << endl;
      st.pop_back();
    }
  }
};

