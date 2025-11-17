/*
 * main.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 * This is the main file that to actually run the program.
 */

#include <stdio.h>
#include "config.h"
#include "cache.h"
#include "message.h"
#include "store.h"
#include <string.h>
#include <stdlib.h>

// Since test.c is a separate file and this is main.c
// it's better to run the test cases from here.
void run_tests(); // Run the test file

// Main function of the program
int main() {
    init_config(); // Initialize configuration settings
    init_cache();  // Initialize the cache
    printf("Program initialized successfully.\n");

    // define messages which will be added to cache
    Message *msg1 = (Message *)malloc(sizeof(Message)); // Allocate memory for message 1
    msg1->id = 1; // Set message ID 1
    strcpy(msg1->content, "Hello, Message 1!");  // Set message content

    Message *msg2 = (Message *)malloc(sizeof(Message)); // Allocate memory for message 2
    msg2->id = 2; // Set message ID 2
    strcpy(msg2->content, "Hello, Message 2!");  // Set message content

    Message *msg3 = (Message *)malloc(sizeof(Message)); // Allocate memory for message 3
    msg3->id = 3; // Set message ID 3
    strcpy(msg3->content, "Hello, Message 3!");  // Set message content

    // Add messages to cache
    add_msg(msg1); // Add message 1 to cache
    add_msg(msg2); // Add message 2 to cache
    add_msg(msg3); // Add message 3 to cache

    // writing a direct message to file
    Message file_msg; // Define a message variable
    file_msg.id = 4;    // Set message ID 4 and directly store to file                           
    strcpy(file_msg.content, "This is disk message."); // Set message content
    store_msg(&file_msg, "message.txt");   // Store the message to file

    // Retrieve a message existing on cache
    Message *have_msg = lookup_msg(2); // Look up message with ID 2 in cache
    if (have_msg != NULL) { // If message is found
        printf("Message found in cache: ID=%d, Content=%s\n", have_msg->id, have_msg->content);
    }

    // Retrieve a message not in cache but in file
    Message *have_file = lookup_msg(4); // Look up message with ID 4 in cache
    if (have_file != NULL) { // If message is found
        printf("Message found in file: ID=%d, Content=%s\n", have_file->id, have_file->content);
    }   

    // Retrieve a message not existing
    Message *no_msg = lookup_msg(5); // Look up message with ID 5 in cache
    if (no_msg == NULL) { // If message is not found
        printf("Message with ID=5 not found in cache or file.\n");
    }

    // Free allocated memory for messages
    free(msg1);
    free(msg2);
    free(msg3); 

    run_tests(); // Run test cases in the test.c file

    return 0; // execution successful. 
}