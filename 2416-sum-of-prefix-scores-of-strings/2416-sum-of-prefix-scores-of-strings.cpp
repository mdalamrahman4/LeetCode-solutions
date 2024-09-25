struct Node{
    Node*links[26]={NULL};
    int count=0;
    bool containskey(char ch){
        return links[ch-'a'];
    }
    Node*get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node*node)
    {
        links[ch-'a']=node;
    }
    void inc(char ch){
        links[ch-'a']->count+=1;
    }
    int retcount(char ch){
        return links[ch-'a']->count;
    }
};
class Solution {
    Node*root;
public:
    Solution(){
        root=new Node();
    }
    void insert(string word){
        Node*node=root;
        for(auto ch:word){
            if(!node->containskey(ch)){
                node->put(ch,new Node);
            }
            node->inc(ch);
            node=node->get(ch);
        }
    }
    int search(string word){
        Node*node=root;
        int pcount=0;
        for(auto ch:word){
            pcount+=node->retcount(ch);
            node=node->get(ch);
        }
        return pcount;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto word:words){
            insert(word);
        }
        vector<int>ans;
        for(auto word:words){
            int pcount=search(word);
            ans.push_back(pcount);
        }
        return ans;
    }
};