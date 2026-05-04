# Bash Script: Remove Execute Permission from Regular Files

## Problem Statement
This script (`script1.sh`) takes one or more filenames as command-line arguments.

For each argument, it:
- Checks if the file exists
- Checks if it is a **regular file**
- If yes, it removes the **execute permission**
- If not, it prints an appropriate message

The script also ensures that at least one argument is provided. If no arguments are given, it shows a usage message.

---

## Usage

```bash
bash script1.sh filename1 filename2 ...
