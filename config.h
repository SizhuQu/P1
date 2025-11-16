/*
 * config.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 * 
 * Description:
 * This file contains configuration settings for the size of the cache and messages.
 */


#ifndef CONFIG_H
#define CONFIG_H

#define SIZE 16   // Number of messages in cache 16 messages (16 = 2^4)
#define MSG 1024  // Size of each message 1024 bytes (1024 = 2^10, a power of 2)

void init_config(); // Function to initialize configuration settings

#endif // CONFIG_H