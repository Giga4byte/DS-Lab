#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left, *right;
};

struct tree *create() {
    int tdata;
    struct tree *ele;
    ele = (struct tree *) malloc(sizeof(struct tree));
    printf("\nEnter the data: ");
    scanf("%d", &tdata);
    if (tdata == -1) {
        return NULL;
    }
    ele->data = tdata;

    printf("ENTER THE LEFT CHILD OF %d", tdata);
    ele->left = create();

    printf("ENTER THE RIGHT CHILD OF %d", tdata);
    ele->right = create();

    return ele;
}

//inorder -> left middle right
void inorder(struct tree *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

//preorder -> middle left right
void preorder(struct tree *root) {
    if (root == NULL) {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

//postorder -> left right middle
void postorder(struct tree *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

struct tree *insertNode(struct tree *root, int value) {
    if (root == NULL) {
        struct tree *newNode = (struct tree *) malloc(sizeof(struct tree));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = value;
        return newNode;
    }

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

struct tree *deleteNode(struct tree *root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        //checks whether the root node has at most one child
        if (root->left == NULL) {
            struct tree *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct tree *temp = root->left;
            free(root);
            return temp;
        }

        /*traverses to the smallest/leftmost value in the
          subtree to find the successor node*/
        struct tree *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

struct tree *insertion(struct tree *root) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    return insertNode(root, value);
}

struct tree *deletion(struct tree *root) {
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    return deleteNode(root, value);
}

struct tree *search(struct tree *root) {
   int count = 0;
    if (root == NULL)
        return NULL;
   else {
        int value;
        printf("Enter the node to search: ");
        scanf("%d", &value);

       while (root->data != value)
       {
          if (root != NULL)
          {
              if(root->data > value) 
              { root = root->left; }//else go to right tree
               else 
               { root = root->right; }
          }
          count++;
       }
       
       if (root->data == value)
       { 
          printf ("Data %d found at level %d", value, count); 
       }
       
       return root;
    }
}

int main() {
    printf("\nEnter -1 if there is no specific data to be added.");
    int choice = -1, tchoice = -1;
    struct tree *root = NULL;
    root = create();
    printf("MENU:\n1. Insert   2. Delete\n3. Traverse   4. Search node   5. Exit");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = insertion(root);
                break;
            case 2:
                root = deletion(root);
                break;
            case 3:
                printf("TRAVERSAL MENU:\n1. Inorder   2. Preorder   3. Postorder");
                printf("\nEnter choice: ");
                scanf("%d", &tchoice);
                switch (tchoice) {
                    case 1:
                        inorder(root);
                        break;
                    case 2:
                        preorder(root);
                        break;
                    case 3:
                        postorder(root);
                        break;
                    default:
                        printf("Invalid choice, choose again.");
                }
                break;
            case 4:
                if (search(root) == NULL)
                    printf("Data not found");
                break;
            case 5:
                printf("TERMINATING.\n");
                return 0;
            default:
                printf("Invalid choice.");
        } // switch - choice
    } // while loop
    return 0;
}
