/*
 * config.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 *  This file contains configuration settings for the size of the cache and messages.
 */

#include "config.h"
#include <stdio.h>

// Function to initialize configuration settings
void init_config() {
    printf("Configuration loaded: SIZE=%d, MSG=%d\n", SIZE, MSG);
}

