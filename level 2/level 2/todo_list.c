#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TODO_FILE "todo.txt"

//function prototypes

void add_task(const char *task);
void view_task(void);


int 
main(int argc, char *argv[]){ // argument to handle the input by command line

    if(argc < 2){  // printing error if user does not provide command less than 2
        fprintf(stderr, "Usage:\n %s add \"task\"\n %s view\n", argv[0], argv[0]);
        return 1;
    }
    if(strcmp(argv[1], "add")==0 && argc ==3){
        add_task(argv[2]);
        printf("Task was added.\n");
    }
    else if (strcmp(argv[1], "view")==0){
        view_task();
    }else{
        fprintf(stderr,"Invalid command or missing string.\n");
    }
    return 0;
}
void add_task(const char *task) {
    // Opening the file in append mode ("a")
    // This will add new tasks to the end of the file without erasing old ones
    FILE *fp = fopen(TODO_FILE, "a");

    // Check if the file was opened successfully
    if (!fp) {
        // If opening the file failed, print a system error message
        perror("Could not open the file for writing --- ");
        return; // Exit the function early
    }

    // Write the task to the file in the format: "- task"
    // \n moves the cursor to a new line after writing
    fprintf(fp, "- %s\n", task);

    // Always close the file after you're done to save changes and free resources
    fclose(fp);
}
void view_task(void)
{
    FILE *fp = fopen(TODO_FILE, "r"); // Open file in read mode
    if (!fp)
    {
        printf(" No to-do file found.\n");
        return;
    }

    char line[256]; // Buffer to hold each line
    printf(" Your To-Do List:\n");
    while (fgets(line, sizeof(line), fp)) // Read lines until end of file
    {
        printf("%s", line); // Print each task
    }

    fclose(fp);
}