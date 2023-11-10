// Enhanced Greeting Program with User Interaction, File Saving, and Viewing
// 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* FILE_NAME = "personalized_greetings.txt";

// Function to generate a random greeting
const char* generateRandomGreeting() {
    const char* greetings[] = {
        "Hello, World!",
        "Hola, Mundo!",
        "Bonjour, le Monde!",
        "Ciao, Mondo!",
        "Hallo, Welt!",
        "Saluton, Mondo!",
        "Hej, Verden!",
        "Konnichiwa, Sekai!",
        "Merhaba, Dünya!",
        "Privet, Mir!"
    };

    int numGreetings = sizeof(greetings) / sizeof(greetings[0]);
    int randomIndex = rand() % numGreetings;

    return greetings[randomIndex];
}

// Function to get a personalized greeting based on user input
const char* getPersonalizedGreeting(const char* name, const char* country) {
    // Customize the greeting based on the user's name and country
    static char greeting[100];
    sprintf(greeting, "Greetings, %s from %s!", name, country);

    return greeting;
}

// Function to save a greeting to a file
void saveGreetingToFile(const char* greeting) {
    FILE* file = fopen(FILE_NAME, "a");
    if (file != NULL) {
        fprintf(file, "%s\n", greeting);
        fclose(file);
        printf("Personalized greeting saved to file.\n");
    } else {
        printf("Error opening the file for saving.\n");
    }
}

// Function to display previously saved personalized greetings
void viewSavedGreetings() {
    FILE* file = fopen(FILE_NAME, "r");
    if (file != NULL) {
        printf("Previously saved personalized greetings:\n");
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("No personalized greetings found.\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // User interaction
    printf("Choose an option:\n");
    printf("1. Get a random greeting\n");
    printf("2. Get a personalized greeting\n");
    printf("3. View saved personalized greetings\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        // Display a random greeting
        printf("%s\n", generateRandomGreeting());
    } else if (choice == 2) {
        // Get a personalized greeting
        printf("Enter your name: ");
        char name[50];
        scanf("%s", name);

        printf("Enter your country: ");
        char country[50];
        scanf("%s", country);

        const char* personalizedGreeting = getPersonalizedGreeting(name, country);
        printf("%s\n", personalizedGreeting);

        // Save the personalized greeting to a file
        saveGreetingToFile(personalizedGreeting);
    } else if (choice == 3) {
        // View saved personalized greetings
        viewSavedGreetings();
    } else {
        // Invalid choice
        printf("Invalid option. Please run the program again.\n");
        return 1;
    }

    // Additional features
    printf("This is an enhanced greeting program with user interaction, file saving, and viewing.\n");
    printf("Feel free to modify and expand it!\n");

    return 0;
}
