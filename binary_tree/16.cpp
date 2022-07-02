Node *pree, *succ;
int keyy = -1;
bool inoorder(Node *root);

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pree = NULL;
    succ = NULL;
    keyy = key;
    // Your code goes here
    bool temp = inoorder(root);

    pre = pree;
    suc = succ;
}

bool inoorder(Node *root)
{
    if (root == NULL)
        return false;

    bool o = inoorder(root->left);
    if (o)
        return o;

    if (root->key > keyy)
    {
        succ = root;
        return true;
    }
    else if (root->key < keyy)
    {
        pree = root;
    }
    bool t = inoorder(root->right);
    if (t)
        return t;

    return false;
}