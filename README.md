# C-Mini-Preprocessor

A modular C-based preprocessor implementing comment removal, file inclusion, and macro substitution.

## Features
- **Comment Removal:** Strips single-line (`//`) and multi-line (`/* ... */`) comments cleanly.
- **File Inclusion:** Processes `#include` directives to merge header files.
- **Macro Substitution:** Expands `#define` macros throughout the source file.

## How to Build and Run

1. **Navigate to the project folder:**
   ```bash
   cd mypreprocessor
   ```

2. **Compile the source files:**
   ```bash
   gcc *.c -o preprocessor
   ```

3. **Run the preprocessor on an input file:**
   ```bash
   ./preprocessor input.c
   ```
