#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define arr_size 10

typedef struct {
    char *surname;
    char *name;
    char *middle_name;
    char *num_input;
    char *num_with_plus;
    char *number;
} person;

void printPerson(person person) {
    printf("Found,");
    if (person.surname) {
        printf(" %s", person.surname);
    }
    if (person.name) {
        printf(" %s", person.name);
    }
    if (person.middle_name) {
        printf(" %s", person.middle_name);
    }
    printf(", %s.\n", person.number);
}

int main(void) {
    person persons[arr_size] = {
        { "Ivanov",      "Ivan",         "Ivanovich",    "79818883322",  "+79818883322",  "+7 (981) 888-33-22"},
        { "Kirillov",    "Anton",        "Efimovich",    "79998881100",  "+79998881100",  "+7 (999) 888-11-00"},
        { "Afanasieva",  "Olga",         NULL,           "79813451122",  "+79813451122",  "+7 (981) 345-11-22"},
        { "Lermontov",   "Mikhail",      "Yurievich",    "89008765431",  NULL,            "8 (900) 876-54-31"},
        { "Pushkin",     "Alexander",    "Sergeevich",   "71119876521",  "+71119876521",  "+7 (111) 987-65-21"},
        { "Fet",         "Afanasy",      "Afanasyevich", "80002345434",  NULL,            "8 (000) 234-54-34"},
        { NULL,          "Euclid",       NULL,           "71234567899",  "+71234567899",  "+7 (123) 456-78-99" },
        { "Gusev",       "Kirill",       "Andreevich",   "79818036133",  "+79818036133",  "+7 (981) 803-61-33" },
        { "Osokin",      "Oleg",         "Anatolevich",  "79118310245",  "+79118310245",  "+7 (911) 831-02-45" },
        { "Azarenkov",   "Artur",        "Olegovich",    "79934861374",  "+79934861374",  "+7 (993) 486-13-74" }
    };
    
    char search[10000];
    scanf("%s", search);
    
    person *found_person = NULL;
    
    for (int n = 0; n < arr_size; n++) {
        person person = persons[n];
        
        int result = 0;
        
        if (person.name) {
            result = result | (strcmp(search, persons[n].name) == 0);
        }
        
        if (person.surname) {
            result = result | (strcmp(search, persons[n].surname) == 0);
        }
        
        if (person.middle_name) {
            result = result | (strcmp(search, persons[n].middle_name) == 0);
        }
       
        if (person.num_input) {
            result = result | (strcmp(search, persons[n].num_input) == 0);
        }
        
        if (person.num_with_plus) {
            result = result | (strcmp(search, persons[n].num_with_plus) == 0);
        }
       
        if (result) {
            found_person = &person;
            break;
        }
    }
    
    if (found_person) {
        person person = *found_person;
        printPerson(person);
    } else {
        printf("Not found.\n");
    }
    
    return 0;
}
