#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BL_Node {
    char name[100];
    float cost;
    unsigned int pages;
    char language[3];
    unsigned int weight;
    unsigned int releaseDate;

    struct BL_Node* next;
} BL_Node;

typedef struct BookList {
    BL_Node* first;
    unsigned int length;
} BookList;


void list_append(BookList* list, BL_Node* book_data){

    BL_Node* data = malloc(sizeof(BL_Node));
    *data = *book_data;

    if (list->first == NULL){
        list->first = data;
        list->length++;

        return;
    }

    BL_Node* currentNode = list->first;

    for (int i = 0; i < list->length-1; i++){
        currentNode = currentNode->next;
    }

    currentNode->next = data;
    list->length++;
}

BL_Node* list_get(BookList* list, int index){
    if (index > list->length){
        return NULL;
    }

    BL_Node* currentNode = list->first;

    for (int i = 0; i < index; i++){
        currentNode = currentNode->next;
    }

    return currentNode;
}

void add_book(BookList* list, char name[100], float cost, unsigned int pages, char language[3], unsigned int weight, unsigned int releaseDate){
    BL_Node temp_book = {
    .cost = cost,
    .pages = pages,
    .weight = weight,
    .releaseDate = releaseDate,
    
    .next = NULL};

    strncpy(temp_book.name, name, sizeof(temp_book.name));
    strncpy(temp_book.language, language, sizeof(temp_book.language));

    list_append(list, &temp_book);
}

BookList HarryPotterBooks = {.first = NULL, .length = 0};

int main(){

    add_book(&HarryPotterBooks, "Harry Potter and the Philosopher's Stone", 19.99, 223, "EN", 770, 1997);
    add_book(&HarryPotterBooks, "Harry Potter and the Chamber of Secrets", 20.99, 251, "EN", 800, 1998);
    add_book(&HarryPotterBooks, "Harry Potter and the Prisoner of Azkaban", 22.99, 317, "EN", 880, 1999);
    add_book(&HarryPotterBooks, "Harry Potter and the Goblet of Fire", 24.99, 636, "EN", 1200, 2000);
    add_book(&HarryPotterBooks, "Harry Potter and the Order of the Phoenix", 25.99, 766, "EN", 1400, 2003);
    add_book(&HarryPotterBooks, "Harry Potter and the Half-Blood Prince", 23.99, 607, "EN", 1200, 2005);
    add_book(&HarryPotterBooks, "Harry Potter and the Deathly Hallows", 27.99, 607, "EN", 1300, 2007);

    for (int i = 0; i < HarryPotterBooks.length; i++){
        BL_Node* book = list_get(&HarryPotterBooks, i);
        printf("Book name: %s\n", book->name);
        printf("Cost: %.2f$\n", book->cost);
        printf("Pages: %d\n", book->pages);
        printf("Language: %s\n", book->language);
        printf("Weight: %d\n", book->weight);
        printf("Release date: %d\n", book->releaseDate);
        printf("\n");
    }
    
    return 0;
}
 
