struct Node{
    Node*link[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return (link[ch-'a']!=NULL);
    }
    Node*get(char ch)
    {
        return link[ch-'a'];
    }
    void put(char ch,Node*node)
    {
        link[ch-'a']=node;
    }
    bool getend()
    {
        return flag;
    }
    void setend()
    {
        flag= true;
    }
};
class WordDictionary {
    Node*root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node*node=root;
        return search(root,word);
    }
    bool search(Node*node,string word)
    {
        for(int i=0;i<word.size();i++)
        {
            if(word[i]=='.'){
                for(int j=0;j<26;j++)
                {
                    if(node->link[j])
                    {
                    if(search(node->link[j],word.substr(i+1)))
                    {
                        return true;
                    }
                    }
                }
                return false;
            }
            if(!node->containskey(word[i])) return false;
            else node=node->get(word[i]);
        }
        return node->getend();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */