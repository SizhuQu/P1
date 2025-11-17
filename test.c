/*
 * test.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 * This file contains test cases for the message caching and storage system.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "message.h"
#include "store.h"
#include "cache.h"

// Function to run test cases
void run_tests() {
    printf("-------Start to run tests.----------\n");
    init_config(); // Initialize configuration
    init_cache();  // Initialize cache
    printf("Configuration and Cache initialized.\n");

    // Test case 1: Create and store a message to cache
    printf("----------Running Test Case 1: Add message to cache.----------\n");
    Message *msg1 = (Message *)malloc(sizeof(Message)); // Allocate memory for message
    init_message(msg1, 123, "Test message for cache."); // Initialize message
    add_msg(msg1); // Add message to cache
    printf("Message with ID %d added to cache.\n", msg1->id); // Verify addition

    // Test case 2: Retrieve message from cache
    printf("-------------Running Test Case 2: Retrieve message from cache.-------------\n");
    Message *the_msg = lookup_msg(123); // Look up message by ID
    if (the_msg != NULL) {
        printf("Retrieved message from cache: ID=%d, Content=%s\n", the_msg->id, the_msg->content);
    }

    // Test case 3: Store message to file
    printf("----------------Running Test Case 3: Store message to file.----------------\n");
    Message file_msg; // Define a message variable
    init_message(&file_msg, 456, "Test message for file."); // Initialize message
    store_msg(&file_msg, "test_message.txt"); // Store message to file
    printf("Message with ID %d stored to file.\n", file_msg.id); // Verify storage

    // Test case 4: Retrieve message from file
    printf("-----------------Running Test Case 4: Retrieve message from file.-----------------\n");
    Message re_msg; // Variable to hold retrieved message
    int out_msg = retrieve_msg(456, "test_message.txt", &re_msg); // Retrieve message by ID
    if (out_msg == 0) { // Check if retrieval was successful
        printf("Retrieved message from file: ID=%d, Content=%s\n", re_msg.id, re_msg.content);
    }

    // Test case 5: Attempt to retrieve non-existent message
    printf("-----------------Running Test Case 5: Attempt to retrieve non-existent message.-------------------\n");
    Message *no_msg = lookup_msg(999); // Look up non-existent message
    if (no_msg == NULL) {
        printf("Message with ID 999 not found.\n");
    }

    // Test case 6: replace message 
    printf("---------------Running Test Case 6: Test cache replacement policy.---------------\n");
    for (int i = 0; i < SIZE + 1; i++) { // Add SIZE + 1 messages is to trigger replacement
        Message *fill_msg = (Message *)malloc(sizeof(Message)); // Allocate memory for message
        fill_msg->id = 200 + i; // Set message ID
        strcpy(fill_msg->content, "Message for replacement test"); // Set message content
        add_msg(fill_msg); // Add message to cache
    }
    printf("Added %d messages to cache to test replacement.\n", SIZE + 1);

    // Test case 7: LIFO replacement
    printf("------------------Running Test Case 7: Test LIFO cache replacement policy.------------------\n");
    init_cache(); // Re-initialize cache to empty

    for (int i = 0; i < SIZE; i++) { 
        Message *lifo_msg = (Message *)malloc(sizeof(Message)); // Allocate memory for message
        lifo_msg->id = 300 + i; // Set message ID
        strcpy(lifo_msg->content, "Message for LIFO replacement test"); // Set message content
        add_msg_lifo(lifo_msg); // Add message to cache using LIFO
    }

    int before_id = cache.messages[SIZE - 1]->id; // Get the last message in cache before replacement
    printf("Before LIFO replace: last slot ID = %d\n", before_id); // Look up the last message added before replacement

    // adding one more message to trigger LIFO replacement
    Message *msg_extra = (Message *)malloc(sizeof(Message)); // Allocate memory for extra message
    msg_extra->id = 400; // Set message ID
    strcpy(msg_extra->content, "Extra message for LIFO replacement test"); // Set message content
    add_msg_lifo(msg_extra); // Add extra message to cache using LIFO

    Message *after = cache.messages[SIZE - 1]; // Get the last message in cache after replacement
    int after_id = (after != NULL) ? after->id : -1; // Get the ID of the last message after replacement
    printf("After LIFO replace: last ID = %d\n", after_id); // Look up the last message added after replacement

    if (after != NULL && after_id == 400) { // Check if the last message is the new one with ID 400
        printf("LIFO replacement SUCCESS. Last slot replaced by ID 400.\n");
    } else {
        printf("LIFO replacement FAILED. Last slot ID is %d (expected 400).\n", after_id);
    }

    //----------- Evaluation: 1000 random accesses ---------------
    printf("----------------Starting Evaluation: 1000 random accesses.----------------\n");
    quiet_mode = 1;   // turn off prints during evaluation
    init_cache(); // Re-initialize cache to empty
    // Fill the cache initially again
    for (int i = 0; i < SIZE; i++) { // Fill the cache initially
        Message *Ev_msg = malloc(sizeof(Message)); // Allocate memory for message
        Ev_msg->id = i; // Set message ID
        snprintf(Ev_msg->content, MSG, "Test content %d", i); // Set message content
        add_msg(Ev_msg); // Add message to cache
    }

    int hits = 0; // Initialize hit counter
    int miss = 0; // Initialize miss counter
    int totals = 1000; // Total number of accesses

    // 1000 random replacement accesses
    for (int i = 0; i < totals; i++) { // Loop for 1000 accesses
        int random_id = rand() % (SIZE * 2); // Generate random ID between 0 and SIZE*2
        Message *random_msg = lookup_msg(random_id); // Look up message by random ID
        // Count hits and misses
        if (random_id < SIZE && random_msg != NULL) { // If message is found
            hits++; // Increment hit counter if message is found
        } else {
            miss++; // Increment miss counter if message is not found
        }
    }

    // Print evaluation results
    printf("Evaluation Result for 1000 random accesses is Hits  : %d\n", hits);
    printf("Misses: %d\n", miss);
    printf("Hit Ratio: %.2f%%\n", (hits * 100.0) / totals);


    //----------- Evaluation: 1000 LIFO accesses ---------------
    printf("------------------Starting Evaluation: 1000 LIFO accesses.------------------\n");
    quiet_mode = 1;   // turn off prints during evaluation
    init_cache(); // Re-initialize cache to empty

    // Fill the cache initially again
    for (int i = 0; i < SIZE; i++) { // Fill the cache initially
        Message *Ev_LIFO_msg = malloc(sizeof(Message)); // Allocate memory for message
        Ev_LIFO_msg->id = i; // Set message ID
        snprintf(Ev_LIFO_msg->content, MSG, "Test content %d", i); // Set message content
        add_msg_lifo(Ev_LIFO_msg); // Add message to cache using LIFO
    }

    int lifo_hits = 0; // Initialize LIFO hit counter
    int lifo_miss = 0; // Initialize LIFO miss counter

    // 1000 LIFO replacement accesses for evaluation 
    for (int i = 0; i < totals; i++) { // Loop for 1000 accesses
        int random_id = rand() % (SIZE * 2); // Generate random ID between 1000 and 1000 + SIZE*2

        Message *found = lookup_msg(random_id); // Look up message by random ID

        if (random_id < SIZE && found != NULL) { // If message is found
            lifo_hits++; // Increment LIFO hit counter
        } else {
            lifo_miss++; // Increment LIFO miss counter
        }
    }

    // Print LIFO evaluation results
    printf("LIFO Evaluation Result for 1000 accesses is Hits  : %d\n", lifo_hits);
    printf("Misses: %d\n", lifo_miss);
    printf("Hit Ratio: %.2f%%\n", (lifo_hits * 100.0) / totals);    


    printf("-------------All tests completed.-------------\n");
}