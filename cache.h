/*
 * cache.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 *  This file defines the cache structure and functions for managing the cache.
 */


#ifndef CACHE_H // Include guard start
#define CACHE_H // Include guard define
#include "message.h" // Include message header
#include "config.h"

extern Cache cache; // External declaration of the cache instance

// Define the Cache structure that holds messages
typedef struct {
    Message* messages[SIZE]; // Array to hold pointers to messages
    int count;            // Current number of messages in the cache
} Cache;                   // Cache structure definition end

void init_cache(); // Initialize the cache
void add_msg(Message* msg);  // Add a message to cache
void add_msg_lifo(Message* msg); // Add a message to cache using LIFO policy
Message* lookup_msg(int id); // Look up a message in cache by its ID

#endif  // CACHE_H
