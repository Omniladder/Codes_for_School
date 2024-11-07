#include "stdio.h"
#include "omp.h"
#include <stdlib.h>
#include <time.h>



struct node {
    float val;  // Randomly assigned value between 0 and 1.
    struct node* l;  // Pointer to the left child node.
    struct node* r;  // Pointer to the right child node.
};


struct node* createTree(struct node* currentNode, int levels)
{
    // Allocate memory for the current node and assign a random value
    currentNode = (struct node*)malloc(sizeof(struct node));
    currentNode->val = (double)rand() / RAND_MAX;
    currentNode->l = currentNode->r = NULL;

    // Recursively create child nodes if more levels remain
    
    if (levels != 1)
    {
        #pragma omp parallel sections
        {
            #pragma omp section
            {currentNode->l = createTree(currentNode->l, levels - 1);}

            #pragma omp section
            {currentNode->r = createTree(currentNode->r, levels - 1);}
        }
    }
    return currentNode;
}


struct node* freeTree(struct node* currentNode)
{
    // Recursively free the left and right child nodes if they exist

     #pragma omp parallel sections
        {
            #pragma omp section
            if (currentNode->l != NULL) {
                freeTree(currentNode->l);
            }

            #pragma omp section
            if (currentNode->l != NULL) {
                freeTree(currentNode->r);
            }

        }
    

    // Free the current node and set it to NULL for safety
    free(currentNode);
    return NULL;
}


int countNodes(struct node* root)
{
    // Base case: if the node is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    int count = 0;

    #pragma omp parallel sections reduction(+:count)
    {
        // Increment the count if the node's value is less than 0.5
        #pragma omp section
        if (root->val < .5) {
            count += 1;
        }

        // Recur for left and right children
        #pragma omp section
        {count += countNodes(root->l);}
        #pragma omp section
        {count += countNodes(root->r);}

    }


    return count;
}


int main()
{
    srand(time(NULL));
    struct node* tree = NULL;

    // Record the start time
    double startTime = (double)clock() / CLOCKS_PER_SEC;

    // Create a binary tree with a depth of 20
    tree = createTree(tree, 20);

    // Count nodes with values less than 0.5
    int count = countNodes(tree);

    // Free all memory allocated for the tree
    freeTree(tree);

    // Record the end time
    double endTime = (double)clock() / CLOCKS_PER_SEC;

    // Display the results
    printf("Node Count: %d \nTotal Time: %f\n", count, endTime - startTime);

    return 0;
}
