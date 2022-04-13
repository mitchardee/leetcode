struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *toRet = NULL;
        ListNode *curr = toRet;
        int smallestIndex;
        
        while(true){
            smallestIndex = -1;
            for(int i=0; i<lists.size();){
                if(lists[i]){
                    if(smallestIndex == -1 || lists[i]->val < lists[smallestIndex]->val)
                        smallestIndex = i;
                    i++;
                }
                else
                    lists.erase(lists.begin() + i);
            }
            if(smallestIndex == -1 ) break;
            if(!toRet){
                curr = lists[smallestIndex];
                toRet = curr;
            }
            else{
                curr->next = lists[smallestIndex];
                curr = curr->next;
            }
            lists[smallestIndex] = lists[smallestIndex]->next;
            if(lists.size() < 2) break;
        }
                
        return toRet;
    }
};