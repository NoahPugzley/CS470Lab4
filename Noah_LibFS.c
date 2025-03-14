
#include "Noah_LibFS.h"
#include <string.h>

FILE* fileOpen(const char* filename, const char* mode) {
    return fopen(filename, mode);
}

int fileCreate(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) return -1;
    fclose(file);
    return 0;
}

void fileRead(FILE* file) {
    char ch;
    while (fread(&ch, 1, 1, file) == 1) {
        putchar(ch);
    }
    printf("\n");
}

size_t fileWrite(const char* data, FILE* file) {
    return fwrite(data, 1, strlen(data), file);
}

int fileClose(FILE* file) {
    return fclose(file);
}

int fileDelete(const char* filename) {
    return remove(filename);
}

void menu() {
    printf("1. Create File\n");
    printf("2. Open File\n");
    printf("3. Write to File\n");
    printf("4. Read from File\n");
    printf("5. Close File\n");
    printf("6. Delete File\n");
    printf("7. Exit\n");
}

int main() {
    //Set up the file name
    char filename[] = "Noah_Introduction.txt";
    //create the file variable to be ready for use
    FILE* file = NULL;
    //set up a character buffer
    char buffer[256];
    //set up the menu
    int choice;
    
    //main loop
    while (1) {
        //display the menu
        menu();
        //get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        //process the user's choice
        switch (choice) {
            case 1:
                //create the file
                fileCreate(filename);
                printf("File created.\n");
                break;
            case 2:
                //open the file
                file = fileOpen(filename, "r+");
                printf("File opened.\n");
                break;
            case 3:
                //check if the file is open
                if (!file) {
                    // if not break out
                    printf("File not opened.\n");
                    break;
                } else {
                    // if it is, write to it
                    printf("Enter introduction: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    fileWrite(buffer, file);
                    printf("Data written.\n");
                    break;
                }
            case 4:
                //check if the file is open
                if (!file) {
                    // if not break out
                    printf("File not opened.\n");
                    break;
                }
                // if it is, read from it
                rewind(file);
                fileRead(file);
                break;
            case 5:
                //close the file
                fileClose(file);
                printf("File closed.\n");
                break;
            case 6:
                //delete the file
                fileDelete(filename);
                printf("File deleted.\n");
                break;
            case 7:
                //exit
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}