bool helper(Node *root, int min, int max);

bool isDeadEnd(Node *root)
{
    // Your code here
    // hr node ki limit hai
    return helper(root, 0, INT_MAX);
}

bool helper(Node *root, int min, int max)
{

    if (!root)
        return false;

    // limit check
    if (root->data == min + 1 && root->data == max - 1)
        return true; // see and necessary

    return helper(root->left, min, root->data) || helper(root->right, root->data, max);
}