#include "main.h"

#define MAX_ALIASES 10
#define MAX_ALIAS_NAME 20
#define MAX_ALIAS_VALUE 50

/* Structure to hold alias name and value */
typedef struct {
    char name[MAX_ALIAS_NAME];
    char value[MAX_ALIAS_VALUE];
} Alias;

Alias aliases[MAX_ALIASES];
int aliasCount = 0;

/**
 * print_aliases - Print all aliases
 */
void print_aliases(void)
{
    for (int i = 0; i < aliasCount; i++) {
        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

/**
 * print_alias - Print a specific alias
 * @name: The name of the alias
 */
void print_alias(const char *name)
{
    for (int i = 0; i < aliasCount; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
            return;
        }
    }
}

/**
 * define_alias - Define or replace an alias
 * @name: The name of the alias
 * @value: The value of the alias
 */
void define_alias(const char *name, const char *value)
{
    for (int i = 0; i < aliasCount; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            strcpy(aliases[i].value, value);
            return;
        }
    }

    if (aliasCount < MAX_ALIASES) {
        strcpy(aliases[aliasCount].name, name);
        strcpy(aliases[aliasCount].value, value);
        aliasCount++;
    } else {
        printf("Maximum number of aliases reached.\n");
    }
}

int main(void)
{
    char command[100];
    while (1) {
        printf("shell> ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "alias", 5) == 0) {
            char *args = command + 5; // Skip "alias"
            char *name = strtok(args, " \t\n");
            
            if (name == NULL) {
                print_aliases();
            } else {
                char *value = strtok(NULL, " \t\n");
                if (value == NULL) {
                    print_alias(name);
                } else {
                    define_alias(name, value);
                }
            }
        }
    }
    
    return 0;
}
