```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable {
    Entry **buckets;
    size_t size;
    size_t count;
} HashTable;

unsigned long hash(int key, unsigned long size) {
    return (unsigned long)key % size;
}

HashTable* create_table(size_t initial_size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->buckets = calloc(initial_size, sizeof(Entry*));
    table->size = initial_size;
    table->count = 0;
    return table;
}

Entry* create_entry(int key, int value) {
    Entry *entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

void resize_table(HashTable *table) {
    size_t new_size = table->size * 2;
    Entry **new_buckets = calloc(new_size, sizeof(Entry*));

    for (size_t i = 0; i < table->size; i++) {
        Entry *entry = table->buckets[i];
        while (entry) {
            int new_index = hash(entry->key, new_size);
            Entry *next_entry = entry->next;

            entry->next = new_buckets[new_index];
            new_buckets[new_index] = entry;

            entry = next_entry;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->size = new_size;
}

void insert(HashTable *table, int key, int value) {
    if ((double)table->count / table->size >= 0.75) {
        resize_table(table);
    }
    unsigned long index = hash(key, table->size);
    Entry *entry = table->buckets[index];

    while (entry) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    Entry *new_entry = create_entry(key, value);
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
    table->count++;
}

int get(HashTable *table, int key) {
    unsigned long index = hash(key, table->size);
    Entry *entry = table->buckets[index];

    while (entry) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }

    fprintf(stderr, "Key %d not found.\n", key);
    return -1; // Return -1 to indicate not found
}

void delete(HashTable *table, int key) {
    unsigned long index = hash(key, table->size);
    Entry *entry = table->buckets[index];
    Entry *prev = NULL;

    while (entry) {
        if (entry->key == key) {
            if (prev) {
                prev->next = entry->next;
            } else {
                table->buckets[index] = entry->next;
            }
            free(entry);
            table->count--;
            return;
        }
        prev = entry;
        entry = entry->next;
    }

    fprintf(stderr, "Key %d not found for deletion.\n", key);
}

void print_table(HashTable *table) {
    for (size_t i = 0; i < table->size; i++) {
        printf("Bucket %zu: ", i);
        Entry *entry = table->buckets[i];
        while (entry) {
            printf("(%d -> %d) ", entry->key, entry->value);
            entry = entry->next;
        }
        printf("\n");
    }
}

void free_table(HashTable *table) {
    for (size_t i = 0; i < table->size; i++) {
        Entry *entry = table->buckets[i];
        while (entry) {
            Entry *next_entry = entry->next;
            free(entry);
            entry = next_entry;
        }
    }
    free(table->buckets);
    free(table);
}

int main() {
    HashTable *table = create_table(16);
    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);
    insert(table, 4, 40);
    insert(table, 5, 50);

    printf("Hash table after insertion:\n");
    print_table(table);

    int value = get(table, 3);
    printf("Value for key 3: %d\n", value);

    delete(table, 3);
    printf("Hash table after deleting key 3:\n");
    print_table(table);

    free_table(table);
    return 0;
}
```