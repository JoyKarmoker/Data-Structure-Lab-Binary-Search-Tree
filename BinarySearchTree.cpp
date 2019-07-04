#include<bits/stdc++.h>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode *right;

};


BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;


    return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }

    else if(data == root->data)
    {
        printf("Already in the loop\n");
        return root;
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }

    else
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(BstNode* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

void Searcher(BstNode* root)
{
    int number;
    printf("Enter a number to search\n");
    scanf("%d", &number);

    if(Search(root, number) == true)
    {
        printf("\n%d Found in the Tree\n");
    }

    else
    {
        printf("\n%d Not Found in The tree\n", number);
    }

}

BstNode* Inserter(BstNode* root)
{
    BstNode* newroot;
    int data;
    printf("Give The Number you want to add\n");
    scanf("%d", &data);

    newroot = Insert(root, data);

    return newroot;
}


int main()
{
    char s, i;
    BstNode* root;
    root = NULL;

    do
    {
        printf("Press S for search, I For insert And E for escape\n");
        cin >> s;


        if(s == 'I' || s== 'i')
        {
            root = Inserter(root);
        }

        else if(s == 's' || s== 'S')
        {
            Searcher(root);
        }

    }while(s != 'E' && s != 'e');



    return 0;
}
