#include <iostream>
#define MAX INT_MAX

struct Tree
{
    float val;
    Tree* left;
    Tree* right;
};

Tree* find(Tree* tree, int value)
{
    if (tree == NULL)
        return NULL;
    if (tree->val == value)
        return tree;
    if (tree->val > value)
        return find(tree->left, value);
    else 
        return find(tree->right, value);
}

void insert(Tree* tree, int value)
{
    if (tree == NULL)
    {
        node = new Tree(value);
        return;
    }
    if (tree->val > value)
        insert(tree->left, value);
    else 
        insert(tree->right, value);
}

// Terminal node count
// Terminal nodes are non-null leaves. Given the data in phylogeny, all
// trees should have either 2 null or 2 not-null branches, aka symmetry
int tnodecount(Tree* tree)
{
    if (tree->left == NULL)
        return 1;
    else
        return tnodecount(tree->left) + tnodecount(tree->right);
}

Tree* upgma(Tree* tree, Tree* clusters[], float* distance[][])
{

    while (distance.length() > 1)
    {
        // Find closest clusters
        // Indices are mini and minj, mini < minj
        float min = MAX;
        int mini = -1, minj = -1;
        for (int i = 0; i < distance.length()-1; i++)
        {
            for (int j = i+1; j < distance.length(); j++)
            {
                if (*distance[i][j] < min)
                {
                    min = *distance[i][j];
                    mini = i;
                    minj = j;
                }
            }
        }

        // Merge cluster with index minj into cluster with index mini
        Tree* merged(0f, clusters[mini], clusters[minj]);
        merged->left->val = *distance[mini][minj]/2;
        merged->right->val = *distance[mini][minj]/2;

        Tree* newClusters[clusters.length()-1];

        for (int i = 0; i < newClusters.length(); i++)
        {
            newClusters[i] = clusters[i];
        }
        if (minj != newClusters.length()) // Don't need to replace if last cluster
        {
            newClusters[minj] = clusters[clusters.length()-1];
        }
        newClusters[mini] = merged;
        clusters = newClusters;

        // Merge distance column of index minj into column of index mini
        float* newDistance[distance.length()-1][distance.length()-1];
        
        for (int i = 0; i < newDistance.length()-1; i++)
        {
            for (int j = i; j < newDistance.length(); j++)
            {
                *newDistance[i][j] = *distance[i][j];
            }
        }
        if (minj != newDistance.length()) // Don't need to merge if last column
        {
            for (int i = 0; i < newDistance.length(); i++)
            {
                *newDistance[i][minj] = *distance[i][newDistance.length()];
            }
            *newDistance[minj][minj] = 0;
        }
        for (int i = 0; i < distance.length(); i++)
        {
            for (int j = i+1; j < distance.length(); j++)
            {
                // mini minj distances / 2
                if (i != mini && i != minj)
            }
        }
    }
    return clusters[0];
}

int main(int argc, char* argv[])
{
    // Test distance matrix
    float* d[0f,3f,4f,3f][3f,0f,4f,5f][4f,4f,0f,2f][3f,5f,2f,0f];

    // Test clusters
    Tree* c[new Tree(0,NULL,NULL), new Tree(0,NULL,NULL), 
        new Tree(0,NULL,NULL), new Tree(0,NULL,NULL)];
}
