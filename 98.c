#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

/* inorder遍历应该从大到小 */

bool isValidBST(struct treeNode* root) {
    struct treeNode *curr = NULL, *rm = NULL, *lm = NULL;
    long prev = (1L << 33) * -1;

    if (root == NULL) {
        return NULL;
    }

    curr = root;
    loop:
    while (curr) {
        if (curr->left) {
            rm = curr->left;
            while (rm->right) {
                if (rm->right == curr) {
                    rm->right = NULL;
                    if (curr->val <= prev)
                        return false;
                    prev = curr->val;
                    curr = curr->right;
                    goto loop;
                }
                rm = rm->right;

            }
            rm->right = curr;
            curr = curr->left;
        } else {
            if (curr->val <= prev)
                return false;
            prev = curr->val;
            curr = curr->right;
        }
    }

    return true;
}

struct treeNode node3 = {3, NULL, NULL};
struct treeNode node2 = {1, &node3, NULL};
struct treeNode node1 = {1, NULL, &node2};

int main(void)
{
    int size;
    printf("%d\n", isValidBST(&node1));

    return 0;
}