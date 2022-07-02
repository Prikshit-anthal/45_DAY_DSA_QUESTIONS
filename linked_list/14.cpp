/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
            return NULL;

        map<Node *, int> original; // node,idx
        map<int, Node *> neww;     // idx,node

        Node *temp = head;

        // original ka data map pr
        int pos = 0;
        while (temp != NULL)
        {
            original[temp] = pos;
            pos++;

            temp = temp->next;
        }

        original[NULL] = -1;

        // make new list first
        temp = head;
        Node *prev = new Node(temp->val);
        temp = temp->next;

        Node *ans = prev;

        while (temp != NULL)
        {
            // Node obj(temp->val);
            // prev->next=&obj;
            // error up two lines

            prev->next = new Node(temp->val);

            prev = prev->next;

            temp = temp->next;
        }

        // now set data in new map

        temp = ans;
        pos = 0;

        while (temp != NULL)
        {
            neww[pos++] = temp;
            temp = temp->next;
        }

        neww[-1] = NULL;

        // now adding random pointers
        Node *temp1 = head;
        temp = ans;
        pos = 0;

        while (temp != NULL)
        {
            temp->random = neww[original[temp1->random]];
            temp = temp->next;
            temp1 = temp1->next;
        }

        return ans;
    }
};