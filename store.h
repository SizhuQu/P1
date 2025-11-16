/*
 * store.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 * This file declares functions for storing and retrieving messages from a file.
 */

#ifndef STORE_H
#define STORE_H
#include "message.h" // Include message header

void store_msg(Message* msg, const char* filename); // Function to save a message to a file
int retrieve_msg(int id, const char* filename, Message* msg_out); // Function to load a message from a file by ID

#endif // STORE_H