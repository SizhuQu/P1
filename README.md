## Practicum I

**Name**: Sizhu Qu
**Course**: CS 5600
**Date**: Nov 14, 2025


## Overview




## Files

- main.c                    — main program that tests message creation, storage, and retrieval  
- cache.c / cache.h         - Th
- message.c / message.h     — message structure and related functions  
- Makefile                  — for compiling and running the project  
- README                    — documentation explaining how to build and run the simulation


## How to Run

```bash
make
./main

## Notes:
A message cannot contain newline characters. The content must be at most 1023 characters; any longer than that will be truncated.


## Reference

- user4287698. (2014, December 15). How to save/retrieve data in C? [Q&A]. Stack Overflow. https://stackoverflow.com/questions/27492606/how-to-save-retrieve-data-in-c
- UPMobileDev, (2022, September 30). Newline in buffer strcspn not working correctly (C). [Q&A]. Stack Overflow. https://stackoverflow.com/questions/72202228/newline-in-buffer-strcspn-not-working-correctly
