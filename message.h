/*
 * message.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 *  This file define message functions and structures.
 */

#ifndef MESSAGE_H // Include guard start
#define MESSAGE_H // Include guard define
#include "config.h"

typedef struct {
    int id;                 // Unique identifier for the message
    char content[MSG];     // Content of the message
} Message; // Message structure definition end

void init_message(Message *msg, int id, const char *content); // Function to initialize a Message structure

#endif
