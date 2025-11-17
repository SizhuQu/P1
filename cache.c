/*
 * cache.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * References: 
 * GeeksforGeeks. (2025, July 11). LIFO (Last-In-First-Out) approach in Programming. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/lifo-last-in-first-out-approach-in-programming/  ￼
 *
 * Description:
 *  This file letting some number of messages are stored in a paged structure in memory. 
 *  The messages must be a fixed size; the choice of size should be a power of 2.
 */

#include "cache.h" // Include cache header
#include <stdlib.h> // Standard library for memory allocation, process control, conversions, etc.
#include <string.h> // Standard library for memory functions
#include <stdio.h> // Standard I/O library

// Use a global cache instance to be accessed by other modules
Cache cache;

int quiet_mode = 0; // Global variable for quiet mode

// Initialize cache to be empty
void init_cache() {
    cache.count = 0; // Set message count to 0
    printf("Cache has been initialized.\n");
}

// Add a message to cache
void add_msg(Message* msg){
    store_msg(msg, "message.txt"); // Save message to file

    // if the cache is not full, add the message, otherwise, print cache is full
    if (cache.count < SIZE) {
        int index = cache.count; // Get the index to add the new message
        cache.messages[index] = msg; // Add message to cache
        cache.count++; // Increment message count
        printf("Message added. Current count: %d\n", cache.count);
    } else {
        int index = rand() % SIZE;  // Randomly select an index to replace
    
        // Print which message was replaced
        if (cache.messages[index] != NULL) { // If there is a message at that index
            printf("Cache is full, Replacing OLD message id=%d at index=%d with NEW id=%d\n",
                cache.messages[index]->id, index, msg->id); // Print replaced message info
        } else {
            printf("Cache is full → Replacing empty slot at index=%d with id=%d\n",
                index, msg->id);
        }
        cache.messages[index] = msg;  // Replace that message
    }
}

// refer: https://www.geeksforgeeks.org/dsa/lifo-last-in-first-out-approach-in-programming/
// Add a message to cache using LIFO policy
void add_msg_lifo(Message* msg){
    store_msg(msg, "message.txt"); // Save message to file

    // if the cache is not full, add the message, otherwise, throw out the last added message
    if (cache.count < SIZE) {
        int index = cache.count;  // Get the index to add the new message
        cache.messages[index] = msg; // Add message to cache
        cache.count++;  // Increment message count by 1
        printf("Message added LIFO. Count: %d\n", cache.count);

    } else { // If cache is full, throw out the last added message
        int index = SIZE - 1; // Index of the last message 
        cache.messages[index] = msg; // Replace the last message
        printf("Cache is full. Replaced last message at index: %d\n", index);
    }
}   
    

// Look up a message in cache by its ID
Message* lookup_msg(int id) {
    // for message in cache, set i as index and start from 0
    // if i < cache.count and not found, increment i, until found or reach the end
    for (int i = 0; i < cache.count; i++) {
        Message *current = cache.messages[i]; // Get the current message pointer
        if (current != NULL && current->id == id) { // if the ID matches the requested ID
            if (!quiet_mode) printf("Message with ID %d found at index %d.\n", id, i);
            return current; // Return the current message pointer
        }
    }
    if (!quiet_mode) printf("Message with ID %d not found in cache.\n", id);

    // If not found in cache, try to load from file 
    Message *from_disk = (Message *)malloc(sizeof(Message)); // Allocate memory for message from disk
    if (from_disk == NULL) { // Check for memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    } 

    // if not found in cache, try to load from file
    if (retrieve_msg(id, "message.txt", from_disk) == 0) { // If message is found in file
        if (!quiet_mode) printf("Message with ID %d loaded from file.\n", id);

        add_msg(from_disk); // Add the loaded message to cache
        return from_disk; // Return the loaded message pointer
    } else {
        if (!quiet_mode) printf("Message with ID %d not found in file.\n", id);
        free(from_disk); // Free allocated memory if not found
        return NULL; // Message not found
    }
}

        


