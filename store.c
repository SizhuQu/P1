/*
 * store.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 * Implements functions for storing and retrieving Message objects on disk.
 * 
 * References: 
 * user4287698. (2014, December 15). How to save/retrieve data in C? [Q&A]. Stack Overflow. https://stackoverflow.com/questions/27492606/how-to-save-retrieve-data-in-c
 * UPMobileDev, (2022, September 30). Newline in buffer strcspn not working correctly (C). [Q&A]. Stack Overflow. https://stackoverflow.com/questions/72202228/newline-in-buffer-strcspn-not-working-correctly
 */

#include "store.h"
#include <stdio.h>
#include <string.h>

// Function to save a message to a file
void store_msg(Message *msg, const char *filename) {
    // Open the file and add the message to the end of the file
    FILE *fp = fopen(filename, "a");

    // Check if file is null which means file opening failed
    if (fp == NULL) { // If file opening failed
        printf("Can not open file %s for writing.\n", filename);
        return;
    }

    fprintf(fp, "%d\n", msg->id); // use the format to write message id
    fprintf(fp, "%s\n", msg->content); // create a message content
    fclose(fp); // Close the file after writing
}   

// refer: https://stackoverflow.com/questions/27492606/how-to-save-retrieve-data-in-c
// and https://stackoverflow.com/questions/72202228/newline-in-buffer-strcspn-not-working-correctly
// Function to retrieve a message with ID 
int retrieve_msg(int id, const char* filename, Message* msg_out) {
    FILE* fp = fopen(filename, "r"); // Open the file and read the message

    if (fp == NULL) { // If file opening failed
        printf("Can not open file %s for reading.\n", filename); // Print error message
        return -1; // Return -1 to indicate failure
    }

    int file_id; // temporary variable to hold message id
    char buffer[1024]; // the size of message content

    // while loop to read messages from file, read line by line to find the message with the given ID
    while (fscanf(fp, "%d\n", &file_id) == 1) { // Read message id from file
        fgets(buffer, sizeof(buffer), fp);  // Read message content from file

        buffer[strcspn(buffer, "\n")] = '\0'; //remove newline character from the content   

        // check if the read message id matches the requested id
        if (file_id == id) { 
            msg_out->id = file_id; // found the message, set the output message id
            strcpy(msg_out->content, buffer); // copy the content to output message
            fclose(fp); // Close the file

            return 0; // end function and return 0 to indicate success
        }
    }

    fclose(fp); // Close the file if message not found
    return -1; // Return -1 to indicate message not found
}
