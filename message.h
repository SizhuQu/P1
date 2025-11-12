/*
 * message.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 14, 2025
 *
 * Description:
 *  This file defines the message structure and functions for managing messages.
 */

#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct {
    int id;                 // Unique identifier for the message
    char content[1024];     // Content of the message
} Message;

void save_msg(Message* msg, const char* filename);
int load_msg(Message* msg, const char* filename, int id);

#endif
