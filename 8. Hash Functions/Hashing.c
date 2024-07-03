#include <stdio.h>

// Linear probing collision resolution
int linearProbing(int key, int i, int tab_size) {
    return (key + i) % tab_size;
}

// Quadratic probing collision resolution
int quadraticProbing(int key, int i, int tab_size) {
    return (key + i * i) % tab_size;
}

// Insert using linear probing
void insertLinear(int table[], int key, int tab_size) {
    int i = 0;
    int index;
    do {
        index = linearProbing(key, i, tab_size);
        if (table[index] == -1) {
            table[index] = key;
            printf("Key %d inserted at index %d (Linear Probing)\n", key, index);
            break;
        }
        i++;
    } while (i < tab_size);
}

// Insert using quadratic probing
void insertQuadratic(int table[], int key, int tab_size) {
    int i = 0;
    int index;
    do {
        index = quadraticProbing(key, i, tab_size);
        if (table[index] == -1) {
            table[index] = key;
            printf("Key %d inserted at index %d (Quadratic Probing)\n", key, index);
            break;
        }
        i++;
    } while (i < tab_size);
}

// Display the hash table
void displayHashTable(int table[], int tab_size) {
    printf("\nHash Table:\n");
    for (int i = 0; i < tab_size; i++) {
        printf("| %d ", table[i]);
    }
    printf("|\n");
}


int main() {
    int tab_size, key, option;
    
    // Get hash table size from the user
    printf("Enter the size of the hash table: ");
    scanf("%d", &tab_size);

    int hash_table[tab_size];

    // Initialize hash table
    for (int i = 0; i < tab_size; i++) {
        hash_table[i] = -1;  // -1 indicates an empty slot
    }
    
        printf("\nMenu:\n");
        printf("1. Insert with Linear Probing\n");
        printf("2. Insert with Quadratic Probing\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");

    while (1) {
        // Display menu
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Get key from the user
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insertLinear(hash_table, key, tab_size);
                break;
            case 2:
                // Get key from the user
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insertQuadratic(hash_table, key, tab_size);
                break;
            case 3:
                displayHashTable(hash_table, tab_size);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
