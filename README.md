# Max Heap Implementation in C++

## Overview
This is an implementation of a Max Heap data structure in C++ with an interactive command-line interface. The implementation includes basic heap operations and additional features such as heap sort and colored terminal output.

## Features
- Interactive menu-driven interface
- Colored terminal output for better readability
- Basic heap operations:
  - Insert value
  - Delete specific value
  - Delete head (root) node
  - Find value (with index locations)
- Additional operations:
  - Heap initialization from user input
  - Heap sort
  - Print current heap state

## Requirements
- C++ compiler with C++11 support or higher
- Terminal with ANSI color support
  - Works on Linux, macOS, and modern Windows Terminal
  - Traditional Windows CMD may need ANSI support enabled

## Installation
1. Clone the repository or download the source code
2. Compile the code using your preferred C++ compiler:
   ```bash
   g++ heap.cpp -o heap
   ```
3. Run the executable:
   ```bash
   ./heap
   ```

## Usage
The program provides an interactive menu with the following options:

1. **Initialize heap**
   - Enter space-separated integers
   - End input with a non-integer character (like a letter)

2. **Insert a value**
   - Add a single integer to the heap
   - Heap property is maintained automatically

3. **Delete a specific value**
   - Remove first occurrence of a value from the heap
   - Heap is reorganized automatically

4. **Delete head**
   - Remove the maximum value (root) from the heap
   - Heap is reorganized automatically

5. **Find a value**
   - Search for a value in the heap
   - Returns all indices where the value is found

6. **Sort heap**
   - Displays heap elements in ascending order
   - Original heap structure is preserved

7. **Print heap**
   - Shows current state of the heap
   - Elements are displayed in array format

8. **Exit**
   - Terminates the program

## Implementation Details

### Class Structure
```cpp
class Heap {
public:
    Heap();                           // Constructor
    void insertValue(int);            // Insert new value
    void deleteValue(int);            // Delete specific value
    void deleteHead();                // Delete root node
    vector<int> findValue(int);       // Find value and return indices
    vector<int> heapSort();           // Sort heap elements
    void printHeap();                 // Display heap
    // ... other public methods

private:
    vector<int> heap;                 // Heap storage
    void heapifyUp(int);              // Maintain heap property upward
    void heapifyDown(int);            // Maintain heap property downward
    void initializeHeap(vector<int>&); // Initialize heap from vector
};
```

### Time Complexities
- Insert: O(log n)
- Delete: O(log n)
- Find: O(n)
- Heap Sort: O(n log n)
- Print: O(n)
- Initialize: O(n)

## Example Usage
```bash
Max Heap Operations:
 1. Initialize heap
 2. Insert a value
 3. Delete a specific value
 4. Delete head
 5. Find a value
 6. Sort heap
 7. Print heap
 8. Exit
Enter your choice: 1
Enter values (space-separated, end with non-integer): 5 3 8 1 2 x
Heap initialized.

Current state of the heap: 8 2 5 1 3
```

## Error Handling
- Input validation for menu choices
- Empty heap checking
- Invalid value handling
- Non-integer input handling

## Notes
This project is open source and available under the MIT License.
This project is authored by Sarah Akhtar.
Version 1.0.0
