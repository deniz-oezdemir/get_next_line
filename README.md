# get_next_line
Recreating the `getline` function in C to read and return lines from a file descriptor.

## Custom str_join function
For `get_next_line` a custom `str_join` function that frees the input string has been implemented.

## Diagram of information flow

```mermaid
graph TD
  A[get_next_line] -->|Calls first| B[read_buffer]
  A -->|Calls second| C[extract_excess]
  B -->|Returns line| A[get_next_line]
  C -->|Returns excess| A

  subgraph Do until first newline character is found
    B -->|Reads from file descriptor| D[loop joining lines]
    D -->|Return updated line| B
  end

  subgraph Save excess read with read_buffer but not returned in line and truncate line
    C
  end
```

## Requirements
Please refer to the [subject](./en.subject.pdf) for detailed requirements.
