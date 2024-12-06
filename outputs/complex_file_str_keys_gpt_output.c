```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOAD_FACTOR_THRESHOLD 0.75

typedef struct Entry {
    char *key;
    unsigned int value;
    struct Entry *next;
} Entry;

typedef struct HashTable {
    Entry **buckets;
    size_t capacity;
    size_t size;
} HashTable;

unsigned long hash(const char *key, unsigned long max) {
    unsigned long hash_value = 0x1505;
    for (const char *ptr = key; *ptr; ptr++) {
        hash_value = hash_value * 0x21 + (unsigned int)(*ptr);
    }
    return hash_value % max;
}

HashTable *create_table(size_t initial_capacity) {
    HashTable *table = malloc(sizeof(HashTable));
    table->buckets = calloc(initial_capacity, sizeof(Entry *));
    table->capacity = initial_capacity;
    table->size = 0;
    return table;
}

Entry *create_entry(const char *key, unsigned int value) {
    Entry *entry = malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = NULL;
    return entry;
}

void resize_table(HashTable *table) {
    size_t new_capacity = table->capacity * 2;
    Entry **new_buckets = calloc(new_capacity, sizeof(Entry *));
    
    for (size_t i = 0; i < table->capacity; i++) {
        Entry *entry = table->buckets[i];
        while (entry) {
            unsigned long new_index = hash(entry->key, new_capacity);
            Entry *next_entry = entry->next;
            entry->next = new_buckets[new_index];
            new_buckets[new_index] = entry;
            entry = next_entry;
        }
    }
    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}

void insert(HashTable *table, const char *key, unsigned int value) {
    if ((double)table->size / table->capacity >= LOAD_FACTOR_THRESHOLD) {
        resize_table(table);
    }
    unsigned long index = hash(key, table->capacity);
    Entry *new_entry = create_entry(key, value);
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
    table->size++;
}

unsigned int get(HashTable *table, const char *key) {
    unsigned long index = hash(key, table->capacity);
    Entry *entry = table->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    fprintf(stderr, "Key '%s' not found.\n", key);
    return 0xffffffff;
}

void delete(HashTable *table, const char *key) {
    unsigned long index = hash(key, table->capacity);
    Entry *entry = table->buckets[index];
    Entry *prev_entry = NULL;
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev_entry) {
                prev_entry->next = entry->next;
            } else {
                table->buckets[index] = entry->next;
            }
            free(entry->key);
            free(entry);
            table->size--;
            return;
        }
        prev_entry = entry;
        entry = entry->next;
    }
    fprintf(stderr, "Key '%s' not found for deletion.\n", key);
}

void print_table(HashTable *table) {
    for (size_t i = 0; i < table->capacity; i++) {
        printf("Bucket %zu: ", i);
        Entry *entry = table->buckets[i];
        while (entry) {
            printf("('%s' -> %u) ", entry->key, entry->value);
            entry = entry->next;
        }
        printf("\n");
    }
}

void free_table(HashTable *table) {
    for (size_t i = 0; i < table->capacity; i++) {
        Entry *entry = table->buckets[i];
        while (entry) {
            Entry *next_entry = entry->next;
            free(entry->key);
            free(entry);
            entry = next_entry;
        }
    }
    free(table->buckets);
    free(table);
}

int main() {
    HashTable *table = create_table(16);
    insert(table, "apple", 10);
    insert(table, "banana", 20);
    insert(table, "cherry", 30);
    insert(table, "date", 40);
    insert(table, "elderberry", 50);

    print_table(table);
    unsigned int value = get(table, "cherry");
    printf("Value for key 'cherry': %u\n", value);
    delete(table, "cherry");
    print_table(table);

    free_table(table);
    return 0;
}
```