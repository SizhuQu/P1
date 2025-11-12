/*
 * cache.h / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 14, 2025
 *
 * Description:
 *  This file defines the cache structure and functions for managing the cache.
 */

#ifndef CACHE_H
#define CACHE_H
#include "message.h"

typedef struct {
    Message* messages[16]; // Array to hold pointers to messages
    int count;            // Current number of messages in the cache
} Cache;

void init_cache();
void add_msg(Message* msg);
Message* lookup_msg(int id);

#endif 
