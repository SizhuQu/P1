/*
 * cache.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 14, 2025
 *
 * References: 
 * 
 *
 * Description:
 *  This file letting some number of messages are stored in a paged structure in memory. 
 *  The messages must be a fixed size; the choice of size should be a power of 2.
 */

#include "message.h"
#include "cache.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Define cache size and message size which are powers of 2 
// and can be modified and can determine the cache capacity.
#define SIZE 16
#define MSG 1024

// Use a global cache instance to be accessed by other modules
Cache cache;

// Initialize cache to be empty
void init_cache() {
    cache.count = 0;
    printf("Cache has been initialized.\n");
}

// Add a message to cache
void add_msg(Message* msg){
    save_msg(&msg, "message.txt"); // Save message to file
    // if the cache is not full, add the message, otherwise, print cache is full
    if (cache.count < SIZE) {
        int index = cache.count; // Get the index to add the new message
        cache.messages[index] = msg; // Add message to cache
        cache.count++; // Increment message count
        printf("Message added. Current count: %d\n", cache.count);
    } else {
        int random_number = rand(); // Generate a random number
        int index = random_number % SIZE; // Get a random index in the cache
        cache.messages[index] = msg; // Replace the message at the random index
        printf("Cache is full. Replaced message at index: %d\n", index);
    }
}

// Look up a message in cache by its ID
Message* lookup_msg(int id) {
    // for message in cache, set i as index and start from 0
    // if i < cache.count and not found, increment i, until found or reach the end
    for (int i = 0; i < cache.count; i++) {
        Message *current = cache.messages[i]; // Get the current message pointer
        if (current->id == id) { // if the ID matches the requested ID
            printf("Message with ID %d found at index %d.\n", id, i);
            return current; // Return the current message pointer
        }
    }
    printf("Message with ID %d not found in cache.\n", id);

    // If not found, check if the message is in the cache miss
    // have to use static since to prevent mass up with local variable
    static Message temp; // avoid returning address of local variable so use static temparary variable
    if (load_msg(&temp, "message.txt", id) == 0) { // Load message from file
        printf("Message with ID %d loaded from file.\n", id);
        return &temp; // Return the loaded message pointer
    } else {
        printf("Message with ID %d not found in file.\n", id);
        return NULL; // Message not found
    }
}

        


