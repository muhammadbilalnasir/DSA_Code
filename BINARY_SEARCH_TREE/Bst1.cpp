#include <iostream>
using namespace std;
struct bst
{
    int id;
    bst *right = NULL;
    bst *left = NULL;
};

bst *root = NULL;

bst *nodeCreation()
{
    bst *temp = new bst;
    cout << "enter id\n";
    cin >> temp->id;
    return temp;
}
void insertion()
{
    bst *current = nodeCreation();
    if (root == NULL)
    {
        cout << "start null working\n";
        root = current;
    }
    else
    {
        bst *transverse = root;
        bst *prev = NULL;
        while (transverse != NULL)
        {
            cout << "loop working\n";
            prev = transverse;
            if (current->id > transverse->id)
            {
                cout << "if working\n";
                transverse = transverse->right;
            }
            else
            {
                cout << "else working\n";
                transverse = transverse->left;
            }
        }
        if (current->id > prev->id)
        {
            prev->right = current;
        }
        else
        {
            prev->left = current;
        }
    }
}

void display()
{
    bst *p = root;
    int id;
    cout << "enter id to see the pattern\n";
    cin >> id;
    while (p != NULL)
    {
        if (p->id == id)
        {
            cout << p->id << " ";
            break;
        }
        else
        {
            cout << p->id << " ";
            if (id > p->id)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
    }
}

void preorder(bst *temp)
{
    if (temp != NULL)
    {
        cout << temp->id << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(bst *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->id << " ";
    }
}
void inorder(bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->id << " ";
        inorder(temp->right);
    }
}
void deletion_of_nodes()
{
    int id;
    cout << "enter id\n";
    cin >> id;
    bst *prev = NULL;
    bst *p = root;
    while (p != NULL)
    {
        if (p->id == id)
        {
            break;
        }
        prev = p;
        if (id > p->id)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    if (p != NULL)
    {
        //   root node deletion
        if (p == root)
        {
            // no branch on right side of root node
            if (p->right == NULL)
            {
                bst *previous = root;
                bst *p = p->left;
                // if no branch of predeccesor on right side(meaning succesor directly after root node)
                if (p->right == NULL)
                {
                    root->id = p->id;
                    root->left = p->left;
                    delete p;
                }
                else
                {
                    // finding predecessor on the left branch
                    while (p->right != NULL)
                    {
                        previous = p;
                        p = p->right;
                    }
                    root->id = p->id;
                    if (p->right == NULL && p->left == NULL)
                    {
                        previous->right = NULL;
                        delete p;
                    }
                    else
                    {
                        previous->right = p->left;
                        delete p;
                    }
                }
            }
            // branches on both sides for deletion
            else
            {
                bst *previous = root;
                bst *p = root->right;
                // if the successor is immeadiately after the root node(meaning no left branches of p)
                if (p->left == NULL)
                {
                    root->id = p->id;
                    root->left = p->left;
                }
                else
                {

                    previous = p;
                    while (p->left != NULL)
                    {
                        previous = p;
                        p = p->left;
                    }
                    // if the successor is a leaf node
                    if (p->right == NULL && p->left == NULL)
                    {
                        root->id = p->id;
                        previous->left = NULL;
                        delete p;
                    }
                    // if the successor has a branch on the right side
                    else
                    {
                        root->id = p->id;
                        previous->left = p->right;
                        delete p;
                    }
                }
            }
        }
        else
        {
            //  leaf node  deletion
            if (p->right == NULL && p->left == NULL)
            {
                if (prev->left == NULL && prev->right->id == p->id)
                {
                    prev->right = NULL;
                }
                else
                {
                    prev->left = NULL;
                }
                delete p;
            }
            // one branch node deletion
            else if (p->right == NULL || p->left == NULL)
            {
                if (p->right == NULL)
                {
                    if (prev->left->id == p->id)
                    {
                        prev->left = p->left;
                    }
                    else
                    {
                        prev->right = p->left;
                    }
                    delete p;
                }
                else
                {
                    if (prev->left->id == p->id)
                    {
                        prev->left = p->right;
                    }
                    else
                    {
                        prev->right = p->right;
                    }
                    delete p;
                }
            }
            // deletion of two branches
            else
            {
                bst *prev_address1 = p->right;
                bst *ptr = p->right;
                if (ptr->left == NULL)
                {
                    p->id = ptr->id;
                    p->right = ptr->right;
                }
                else
                {
                    while (ptr->left != NULL)
                    {
                        prev_address1 = ptr;
                        ptr = ptr->left;
                    }
                    if (ptr->right == NULL && ptr->left == NULL)
                    {
                        p->id = ptr->id;
                        prev_address1->left = NULL;
                        delete ptr;
                    }
                    else
                    {
                        p->id = ptr->id;
                        prev_address1->left = ptr->right;
                        delete ptr;
                    }
                }
            }
        }
    }
}
void successor()
{

    if (root->right == NULL)
    {
        cout << " no successor\n";
    }
    else
    {
        bst *p = root->right;
        while (p->left != NULL)
        {
            p = p->left;
        }
        cout << "the successor is " << p->id << endl;
    }
}
void predecessor()
{
    if (root->left == NULL)
    {
        cout << "no predecessor\n";
    }
    else
    {
        bst *p = root->left;
        while (p->right != NULL)
        {
            p = p->right;
        }
        cout << "the predecessor is " << p->id << endl;
    }
}
void maximum()
{
    bst *p = root;
    while (p->right != NULL)
    {
        p = p->right;
    }
    cout << "the maximum value is " << p->id << endl;
}
void minimum()
{
    bst *p = root;
    while (p->left != NULL)
    {
        p = p->left;
    }
    cout << "the minimum value is " << p->id << endl;
}
void num_of_leaf(int &count, bst *p)
{
    if (p->left == NULL && p->left == NULL)
    {
        count++;
        return;
    }
    else
    {
        num_of_leaf(count, p->left);
        num_of_leaf(count, p->right);
    }
}
int main()
{
    int opt;
    do
    {
        cout << "press 1 to insert\n2 to display in preorder\n3 to display in inorder\n4 to display in postorder\n6 to delete a node\n";
        cout << "7 for successor\n8 for predecessor\n9 for maximum\n10 for minimum\n11 to count leaf nodes\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insertion();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            display();
            break;
        case 6:
            deletion_of_nodes();
            break;
        case 7:
            successor();
            break;
        case 8:
            predecessor();
            break;
        case 9:
            maximum();
            break;
        case 10:
            minimum();
            break;
        case 11:
            int a = 0;
            num_of_leaf(a, root);
            cout << "the number of leaf node is : " << a << endl;
            break;
        }
    } while (opt != 0);
}