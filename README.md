## Practicum I

**Name**: Sizhu Qu
**Course**: CS 5600
**Date**: Nov 17, 2025

## Overview
This project aims to add a configurable-size in-memory cache to a message storage system and implement both Random and Last-In-First-Out (LIFO) page replacement algorithms. The program needs to handle fixed-size messages, build an efficient cache lookup structure, support loading messages from disk into the cache, perform hit/missing message checks, and execute the replacement strategy when the cache is full. The project also requires designing a custom test plan to verify the correctness of the caching mechanism and performing statistical analysis on both algorithms, including hit rate and the number of hits/missing messages per 1000 accesses. The overall code must maintain a clear structure, be well-commented, and easy to read.

## Function
- Cache add / lookup  
- Cache hit and miss detection  
- Disk-backed storage  
- Random replacement  
- LIFO replacement  
- Evaluation of 1000 random accesses per algorithm  
- Metrics:
  - hits  
  - misses  
  - hit ratio  

## Files
- **README.md**        – Project overview and instructions  
- **main.c**           – Main program demonstrating message send/lookup  
- **test.c**           – Full test suite + evaluation metrics  
- **cache.c / cache.h** – Cache structure, lookup, replacement algorithms  
- **store.c / store.h** – Disk read/write, store and retrive
- **message.c / message.h** – Message structure + helper initialization  
- **config.c / config.h** – Cache size & message size configuration  
- **Makefile**         – Build rules for the files

## How to build
make

## How to run
Run the main demo (include test):
- make run
Run the test:
- make test

## Notes:
- A message cannot contain newline characters. The content must be at most 1024 characters; any longer than that will be truncated.
- Cache size (`SIZE`) and message size (`MSG`) configured in `config.h`
- The test suite prints metrics required by the practicum  


## Reference
- GeeksforGeeks. (2025, July 11). LIFO (Last-In-First-Out) approach in Programming. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/lifo-last-in-first-out-approach-in-programming/  ￼
- user4287698. (2014, December 15). How to save/retrieve data in C? [Q&A]. Stack Overflow. https://stackoverflow.com/questions/27492606/how-to-save-retrieve-data-in-c
- UPMobileDev, (2022, September 30). Newline in buffer strcspn not working correctly (C). [Q&A]. Stack Overflow. https://stackoverflow.com/questions/72202228/newline-in-buffer-strcspn-not-working-correctly
- OpenAI. (2025). ChatGPT (Version 5.1) [Large language model]. https://chat.openai.com

## Aknowlegement
Parts of debugging, explanation, and conceptual clarification were assisted by ChatGPT.
All design decisions, code implementation, and test development were done by the author.