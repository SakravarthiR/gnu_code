#include <stdio.h>   // For standard input/output functions
#include <string.h>  // For string handling functions like strlen()

int main(int argc, char *argv[]) {
    // Declare a character array (string) with space for 2000 characters
    char input[2000];

    // Prompt the user to enter a string
    printf("Enter the string: ");

    // Use fgets to read a line of input from the user safely
    // fgets reads up to sizeof(input) - 1 characters or until newline is found
    // stdin means we are reading from the keyboard (standard input)
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Get the length of the string entered (including '\n' if present)
        size_t len = strlen(input);

        // Check if the last character is a newline '\n'
        // This happens when the user presses Enter at the end
        if (len > 0 && input[len - 1] == '\n') {
            // Replace the newline with a null terminator '\0' to end the string properly
            input[len - 1] = '\0';
            len--;  // Adjust the length since we removed the newline
        }

        // Loop to print the string in reverse order
        // Start from the last character (len - 1) to the first (index 0)
        for (int i = (int)len - 1; i >= 0; i--) {
            // putchar prints one character at a time
            putchar(input[i]);
        }

        // Print a newline after reversing the string
        putchar('\n');
    }

    // Return 0 from main means the program ran successfully
    return 0;
}
