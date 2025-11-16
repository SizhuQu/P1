/*
 * config.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 14, 2025
 * 
 * Description:
 * This file contains configuration settings for the size of the cache and messages.
 */


#ifndef CONFIG_H
#define CONFIG_H

extern int SIZE; // Number of messages in cache from config.c
extern int MSG;  // Size of each message from config.c

void init_config(); // Function to initialize configuration settings

#endif // CONFIG_H