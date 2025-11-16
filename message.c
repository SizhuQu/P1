/*
 * message.c / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 * Define Message structure and functions for managing messages, handles saving and loading messages from the file.
 *
 */
#include "message.h"
#include <string.h>

// Function to initialize a Message structure
void init_message(Message *msg, int id, const char *content) {
    msg->id = id; // Set message ID
    strncpy(msg->content, content, MSG); // Copy message content, ensuring no overflow
}