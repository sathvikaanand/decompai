#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16
#define LOAD_FACTOR 0.75

// Hash table entry structure
typedef struct Entry {
    int key;
    int value;
    struct Entry* next; // Chaining for collisions
} Entry;

// Hash table structure
typedef struct HashTable {
    Entry** buckets;  // Array of pointers to entries
    size_t capacity;
    size_t size;
} HashTable;

// Hash function
unsigned int hash(int key, size_t capacity) {
    return (unsigned int)(key % capacity);
}

// Create a new hash table
HashTable* create_table(size_t capacity) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->buckets = (Entry**)calloc(capacity, sizeof(Entry*));
    table->capacity = capacity;
    table->size = 0;
    return table;
}

// Create a new entry
Entry* create_entry(int key, int value) {
    Entry* entry = (Entry*)malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// Resize the hash table
void resize_table(HashTable* table) {
    size_t new_capacity = table->capacity * 2;
    Entry** new_buckets = (Entry**)calloc(new_capacity, sizeof(Entry*));

    // Rehash entries into the new bucket array
    for (size_t i = 0; i < table->capacity; i++) {
        Entry* entry = table->buckets[i];
        while (entry) {
            unsigned int new_index = hash(entry->key, new_capacity);
            Entry* next = entry->next;
            entry->next = new_buckets[new_index];
            new_buckets[new_index] = entry;
            entry = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}

// Insert key-value pair into the hash table
void insert(HashTable* table, int key, int value) {
    if ((float)table->size / table->capacity >= LOAD_FACTOR) {
        resize_table(table);
    }

    unsigned int index = hash(key, table->capacity);
    Entry* entry = table->buckets[index];
    while (entry) {
        if (entry->key == key) {
            entry->value = value; // Update existing key
            return;
        }
        entry = entry->next;
    }

    // Add new entry
    Entry* new_entry = create_entry(key, value);
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
    table->size++;
}

// Get value by key
int get(HashTable* table, int key) {
    unsigned int index = hash(key, table->capacity);
    Entry* entry = table->buckets[index];
    while (entry) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    fprintf(stderr, "Key %d not found.\n", key);
    return -1;
}

// Delete key-value pair
void delete(HashTable* table, int key) {
    unsigned int index = hash(key, table->capacity);
    Entry* entry = table->buckets[index];
    Entry* prev = NULL;

    while (entry) {
        if (entry->key == key) {
            if (prev) {
                prev->next = entry->next;
            } else {
                table->buckets[index] = entry->next;
            }
            free(entry);
            table->size--;
            return;
        }
        prev = entry;
        entry = entry->next;
    }
    fprintf(stderr, "Key %d not found for deletion.\n", key);
}

// Print the hash table
void print_table(HashTable* table) {
    for (size_t i = 0; i < table->capacity; i++) {
        printf("Bucket %zu: ", i);
        Entry* entry = table->buckets[i];
        while (entry) {
            printf("(%d -> %d) ", entry->key, entry->value);
            entry = entry->next;
        }
        printf("\n");
    }
}

// Free the hash table
void free_table(HashTable* table) {
    for (size_t i = 0; i < table->capacity; i++) {
        Entry* entry = table->buckets[i];
        while (entry) {
            Entry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// Main function
int main() {
    HashTable* table = create_table(INITIAL_CAPACITY);

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);
    insert(table, 4, 40);
    insert(table, 5, 50);

    printf("Hash table after insertion:\n");
    print_table(table);

    printf("Value for key 3: %d\n", get(table, 3));
    delete(table, 3);
    printf("Hash table after deleting key 3:\n");
    print_table(table);

    free_table(table);
    return 0;
}
