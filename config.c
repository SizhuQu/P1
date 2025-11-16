/*
 * cache.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 *  This file contains configuration settings for the size of the cache and messages.
 */

#include "config.h"
#include <stdio.h>

int SIZE = 16;    // Number of messages in cache
int MSG = 1024;  // Size of each message

// Function to initialize configuration settings
void init_config() {
    printf("Configuration: Cache Size = %d, Message Size = %d\n", SIZE, MSG);
}

