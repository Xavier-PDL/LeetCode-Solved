#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    static ListNode* CreateList(vector<int> elements)
    {
        ListNode* head;
        if(!elements.size())
            return nullptr;

        ListNode** node = &head;
        for(auto i : elements)
        {
            *node = new ListNode(i);
            node = &(*node)->next;
        }
        return head;
    }
    void print()
    {
        cout << '{' << val << ", ";
        auto node = next;
        while(node)
        {
            cout << node->val;
            node = node->next;
            if(node)
                cout << ", ";
        }
        cout << '}' << endl;
    }
};

class Solution {
public:
    ListNode* mergeLists(ListNode* a, ListNode* b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        if(!a && !b)
            return nullptr;
            
        ListNode* c = new ListNode();
        ListNode* node = c;
        while(a || b)
        {
            if(a && (!b || a->val < b->val))
            {
                node->val = a->val;
                a = a->next;
            }
            else
            {
                node->val = b->val;
                b = b->next;
            }
            if(a || b)
            {
                node->next = new ListNode();
                node = node->next;
            }
        }

        return c;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k = lists.size(); // number of 
        if (!k)
            return nullptr;
        vector<ListNode*> mergedLists;
        for(int i = 0; i < k; i+=2)
        {
            if(k - i >= 2)
                mergedLists.push_back(mergeLists(lists[i], lists[i+1]));
            else
            {
                mergedLists.push_back(lists[i]);
            }
            
        }
        if(mergedLists.size() > 1)
            return mergeKLists(mergedLists);
        return mergedLists[0];
    }
};



int main()
{
    auto a = ListNode::CreateList({1,4,7});
    auto b = ListNode::CreateList({2,5,8});
    auto c = ListNode::CreateList({3,6});
 
    // a->print();
    // b->print();
    vector<ListNode*> lists = {a,b,c};
    //vector<ListNode*> lists = {{},{}};
    Solution s;
    auto result = s.mergeKLists(lists);
    if(result)
        result->print();
    return 0;
}
