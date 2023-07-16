#!/bin/bash

# Colors
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Change to the parent directory
cd /path/to/parent/directory

# Use the find command to locate directories with Makefile
find . -type f -name "Makefile" -exec sh -c '
    # Get the directory path
    directory=$(dirname "$0")

    # Change to the directory
    cd "$directory"

    # Run your command if Makefile exists
    if [ -e "Makefile" ]; then
        echo -e "${CYAN}Running command in directory: ${GREEN}$PWD${NC}"
        # Replace the command below with your desired command
        make fclean
    fi
' {} \;
echo -e "${GREEN}process has been successfully completed."
