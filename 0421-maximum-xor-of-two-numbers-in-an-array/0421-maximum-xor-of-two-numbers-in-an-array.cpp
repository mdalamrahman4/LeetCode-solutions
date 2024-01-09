class Node{
    Node*links[2];
    public:
    bool containskey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node*get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node*node)
    {
        links[bit]=node;
    }
};
class Trie{
    Node*root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node*node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containskey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getmax(int num)
    {
        Node*node=root;
        int mxno=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containskey(1-bit))
            {
                mxno=mxno|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return mxno;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie=new Trie();
        for(int &it:nums)
        {
            trie->insert(it);
        }
        int mx=0;
        for(int i=1;i<nums.size();i++)
        {
            mx=max(mx,trie->getmax(nums[i]));
        }
        return mx;
    }
};