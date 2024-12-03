#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "database.dat"

typedef struct {
    int id;
    char name[50];
    float balance;
} Record;

void add_record() {
    FILE *file = fopen(DB_FILE, "ab");
    if (!file) {
        perror("Could not open database file");
        return;
    }

    Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Balance: ");
    scanf("%f", &record.balance);

    fwrite(&record, sizeof(Record), 1, file);
    fclose(file);
    printf("Record added successfully!\n");
}

void view_records() {
    FILE *file = fopen(DB_FILE, "rb");
    if (!file) {
        perror("Could not open database file");
        return;
    }

    Record record;
    printf("ID\tName\tBalance\n");
    while (fread(&record, sizeof(Record), 1, file)) {
        printf("%d\t%s\t%.2f\n", record.id, record.name, record.balance);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Record\n2. View Records\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

