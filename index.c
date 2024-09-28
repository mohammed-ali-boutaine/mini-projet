#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>

#include <stddef.h> // Required for size_t


// procedurs
void addLivre();
void searchLivre();
void showLivres();
void updateLivre();
void deleteLivre();
void showTotalStack();

// livre  : titre , auteur , prix , quantite
char titres[100][100] = {
    "livre1",
    "livre2",
    "livre3"
};
char auteurs[100][100] = {
    "ali",
    "med",
    "ahmed"
};
float prix[50] = {
    100,
    150,
    120.50
};
int quantite[50] = {
    100,
    40,
    60
};

// tracking index
int currentIndex = 3;
char t[100], a[100];
float p;
int q;

int main() {

    // variables
    int option;
    char input[100];

    do {

        printf("Choisissez une option:\n");
        printf("1 - Ajouter un livre\n");
        printf("2- search by title\n");
        printf("3 - Afficher tous les livres disponibles\n");
        printf("4 - Modifier les informations d'un livre\n");
        printf("5 - Supprimer un livre\n");
        printf("6 - Afficher le stock total\n");
        printf("0 - Quitter le programme\n");

        printf("Votre option: ");
        scanf("%s", input); // Read input as a string

        // str to int
        char * endptr;
        option = strtol(input, & endptr, 10);

        if ( * endptr != '\0') {
            printf("Input invalide, veuillez entrer un nombre.\n");
            continue;
        }

        switch (option) {
        case 0:
            return 0;
        case 1:
            addLivre();
            break;
        case 2:
            searchLivre();
            break;
        case 3:
            showLivres();
            break;
        case 4:
            updateLivre();
            break;
        case 5:
            deleteLivre();
            break;
        case 6:
            showTotalStack();
            break;
        default:
            printf("Option invalide, veuillez réessayer.\n");
            break;
        }

    } while (1);

    return 0;
}

void addLivre() {
    printf("\n\n");
    // pour titre auteur , prix , quantie
    char t[100], a[100];
    float p;
    int q;

    // demmnder les info 
    printf("Le Titre: ");
    scanf("%s", & t);

    printf("Le Auteur: ");
    scanf("%s", & a);

    printf("Le Prix: ");
    scanf("%f", & p);

    printf("Le Quantite: ");
    scanf("%d", & q);

    // stocker les info
    strcpy(titres[currentIndex], t);
    strcpy(auteurs[currentIndex], a);
    prix[currentIndex] = p;
    quantite[currentIndex] = q;

    currentIndex++;

    printf("\n\n");
}

void showLivres() {
    printf("\n\n");
    for (int i = 0; i < currentIndex; i++) {
        printf("- titre: %s ,auteur: %s ,prix:%.2f ,quantite%d\n", titres[i], auteurs[i], prix[i], quantite[i]);
    }
    printf("\n\n");
}

void updateLivre() {

    char titre[100];
    int newQuantite;
    int livreExist = 0;

    getchar();
    printf("Titre de livre: ");
    fgets(titre, sizeof(titre), stdin); // Reads input, including newline character

    for (int i = 0; i < currentIndex; i++) {
        if (strcmp(titre, titres[i])) {
            // Get quantity
            printf("new quantite: ");
            scanf("%d", & newQuantite);
            quantite[i] = newQuantite;
            livreExist = 1;
            break;
        }
    }
    if (!livreExist) {
        printf("livre not found");
    }

}

void deleteLivre() {

    char t[100];
    int livreExist = 0;

    printf("Titre de livre: ");
    scanf("%s", & t);

    for (int i = 0; i < currentIndex; i++) {

        if (strcmp(t, titres[i]) == 0) {
            for (int index = i; index < currentIndex; index++) {
                strcpy(titres[i], titres[i + 1]);
                strcpy(auteurs[i], auteurs[i + 1]);

                prix[i] = prix[i + 1];
                quantite[i] = quantite[i + 1];
                livreExist = 1;

            }
            break;
        }
    }

    if (!livreExist) {
        printf("livre not found\n");
    }

}

void showTotalStack() {
    int sum = 0;
    for (int i = 0; i < currentIndex; i++) {
        sum += quantite[i];
    }
    printf("total livre in stock est: %d\n", sum);
}

void searchLivre() {

    //   getchar();
    char t[100];
    int livreExist = 0;

    printf("Titre de livre: ");
    scanf("%s", & t);
    // fgets(t, sizeof(t), stdin); // Reads input, including newline character

    // buffer[strcspn(buffer, "\n")] = 0;

    //   size_t len = strlen(t);
    //     if (len > 0 && t[len - 1] == '\n') {
    //         t[len - 1] = '\0'; // Replace newline with null terminator
    //     }

    // printf("%s",t);

    for (int i = 0; i < currentIndex; i++) {

        if (strcmp(t, titres[i]) == 0) {
            printf("- titre: %s ,auteur: %s ,prix:%.2f ,quantite:%d\n", titres[i], auteurs[i], prix[i], quantite[i]);
            livreExist = 1;
        }
    }

    if (!livreExist) {
        printf("livre not found\n");
    }
}