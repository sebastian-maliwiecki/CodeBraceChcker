# CodeBraceChcker

## Overview

This program is a simple command-line tool designed to analyze the block structure of a code file by checking for matching curly braces `{` and `}`. It reads a file containing source code, identifies lines with unmatched opening or closing braces, and outputs matching brace pairs, as well as any mismatches or unbalanced braces.

The program can be useful for debugging the structure of C++ or other similar programming languages with nested blocks.

---

## Features

- Reads a source code file line by line.
- Identifies and matches opening `{` and closing `}` braces.
- Detects and reports:
  - Unmatched opening braces.
  - Unmatched closing braces.
- Skips lines containing both `{` and `}` on the same line, as they are considered balanced.

---

## How It Works

1. The program reads the contents of a file into a vector of strings.
2. It iterates through the file line by line:
   - Pushes the line number of each opening `{` to a stack.
   - Pops and pairs the top stack element with a closing `}` when found.
3. Outputs:
   - Brace pairs (line numbers of matching braces).
   - Errors for unmatched opening or closing braces.

---

## Usage

### Prerequisites

- A C++ compiler (e.g., `g++`).
- A text file containing the source code to be analyzed.

### Compilation

Compile the program using a C++ compiler:

```bash
g++ -o brace_checker brace_checker.cpp