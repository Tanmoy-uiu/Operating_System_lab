# Bash Script: Delete Files Based on Pattern in a Specific Line

## Problem Statement
This script (`script2.sh`) takes two inputs:
- A line number `n`
- A string `PATTERN`

It searches all `.txt` files in the current directory and deletes those files where the given `PATTERN` is found in line number `n`.

---

## How it works
- Reads input line number and pattern
- Checks each `.txt` file in the directory
- Extracts the given line from each file
- If the pattern matches that line, the file is deleted

---

## Usage

```bash
bash script2.sh <line_number> <pattern>
