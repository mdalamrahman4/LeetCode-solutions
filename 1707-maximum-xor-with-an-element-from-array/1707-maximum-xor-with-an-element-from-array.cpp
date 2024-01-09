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
                node=node->get(!bit);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>oq;
        int q=queries.size();
        for(int i=0;i<q;i++)
        {
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        vector<int>ans(q,0);
        int ind=0;
        int n=nums.size();
        Trie trie;
        for(int i=0;i<q;i++)
        {
            int mi=oq[i].first;
            int xi=oq[i].second.first;
            int qind=oq[i].second.second;
            while(ind<n && nums[ind]<=mi)
            {
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0) ans[qind]=trie.getmax(xi); 
            else ans[qind]=-1;
        }
        return ans;
    }
};