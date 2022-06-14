class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        // Your code here
        Node *temp = del->next;
        *del = *temp;
        free(temp);
    }
};