//
// File: heap.cpp
// Author: Sarah Akhtar
// Date: October 26, 2024
// Description: This program implements a max heap structure with operations.
//

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#pragma region Color Constants

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

#pragma endregion

class Heap {
public:
    // Description: Initializes an empty heap
    Heap() {}

    // Description: Inserts a value into the heap
    // Parameters: int heapValue - The value to be inserted
    void insertValue(int heapValue) {
        heap.push_back(heapValue);
        heapifyUp(heap.size() - 1);
    }

    // Description: Deletes a specific value from the heap
    // Parameters: int heapValue - The value to be deleted
    void deleteValue(int heapValue) {
        // Find the value in the heap
        auto it = std::find(heap.begin(), heap.end(), heapValue);
        if (it == heap.end()) {
            cout << RED << "Value " << heapValue << " not found in the heap.\n" << RESET;
            return;
        }

        // Replace value with last element and remove last element
        int index = it - heap.begin();
        heap.at(index) = heap.back();
        heap.pop_back();

        // Restore heap property
        if (index < heap.size()) {
            if (index > 0 && heap.at(index) > heap.at((index-1)/2)) {
                heapifyUp(index);
            } else {
                heapifyDown(index);
            }
        }

        cout << GREEN << "Value " << heapValue << " deleted from the heap.\n" << RESET;
    }

    // Description: Deletes the root (maximum value) from the heap
    void deleteHead() {
        if (heap.empty()) {
            cout << RED << "Heap is empty. Cannot delete head.\n" << RESET;
            return;
        }

        // Replace root with last element and remove last element
        int deletedValue = heap.at(0);
        heap.at(0) = heap.back();
        heap.pop_back();

        // Restore heap property
        if (!heap.empty()) {
            heapifyDown(0);
        }

        cout << GREEN << "Head value " << deletedValue;
        cout << " deleted from the heap.\n" << RESET;
    }

    // Description: Finds all occurrences of a value in the heap
    // Parameters: const int heapValue - The value to find
    // Return: vector<int> - Indices of the found values
    vector<int> findValue(const int heapValue) {
        vector<int> indices;
        for (int i = 0; i < heap.size(); i++) {
            if (heap.at(i) == heapValue) {
                indices.push_back(i);
            }
        }
        return indices;
    }

    // Description: Sorts the heap in ascending order
    // Return: vector<int> - Sorted array
    vector<int> heapSort() {
        vector<int> sorted = heap;
        vector<int> result;

        while (!sorted.empty()) {
            // Extract max element
            result.push_back(sorted.at(0));
            sorted.at(0) = sorted.back();
            sorted.pop_back();

            // Restore heap property
            if (!sorted.empty()) {
                int index = 0;
                while (true) {
                    int maxIndex = index;
                    int leftChild = 2 * index + 1;
                    int rightChild = 2 * index + 2;

                    if (leftChild < sorted.size() &&
                        sorted.at(leftChild) > sorted.at(maxIndex)) {
                        maxIndex = leftChild;
                    }

                    if (rightChild < sorted.size() &&
                        sorted.at(rightChild) > sorted.at(maxIndex)) {
                        maxIndex = rightChild;
                    }

                    if (index == maxIndex) { break; }
                    swap(sorted.at(index), sorted.at(maxIndex));
                    index = maxIndex;
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // Description: Helps user initialize the heap with multiple values
    void aidHeapInitialization() {
        vector<int> input; int value;
        cout << CYAN << "Enter values (space-separated, end with non-integer): " << RESET;
        while (cin >> value) { input.push_back(value); }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        initializeHeap(input);
        cout << GREEN << "Heap initialized.\n" << RESET;
    }

    // Description: Prints the current state of the heap
    void printHeap() {
        cout << MAGENTA;
        for (int value : heap) { cout << value << " "; }
        cout << RESET << endl;
    }

    // Description: Prints the menu of available operations
    static void printMessages() {
        cout << BOLD << BLUE << "Max Heap Operations:\n" << RESET;
        cout << YELLOW;
        cout << " 1. Initialize heap\n";
        cout << " 2. Insert a value\n";
        cout << " 3. Delete a specific value\n";
        cout << " 4. Delete head\n";
        cout << " 5. Find a value\n";
        cout << " 6. Sort heap\n";
        cout << " 7. Print heap\n";
        cout << " 8. Exit\n";
        cout << CYAN << "Enter your choice: " << RESET;
    }

    // Function: runProgram
    // Description: Main loop for user interaction
    // Parameters: None
    // Return: void
    void runProgram() {
        while (true) {
            printMessages();
            int userInput;
            if (!(cin >> userInput)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "Invalid input. Please enter a number.\n" << RESET << endl;
                continue;
            }

            switch (userInput) {
            case 1: {
                aidHeapInitialization();
                break;
            }
            case 2: {
                int value;
                cout << CYAN << "Enter value to insert: " << RESET;
                cin >> value;
                insertValue(value);
                cout << GREEN << "Value inserted.\n" << RESET;
                break;
            }
            case 3: {
                int value;
                cout << CYAN << "Enter value to delete: " << RESET;
                cin >> value;
                deleteValue(value);
                break;
            }
            case 4: {
                deleteHead();
                break;
            }
            case 5: {
                int value;
                cout << CYAN << "Enter value to find: " << RESET;
                cin >> value;
                vector<int> indices = findValue(value);
                if (!indices.empty()) {
                    cout << GREEN << "Value found at index(es): ";
                    for (int index : indices) {
                        cout << index << " ";
                    }
                    cout << "\n" << RESET;
                } else {
                    cout << RED << "Value not found in the heap.\n" << RESET;
                }
                break;
            }
            case 6: {
                vector<int> sorted = heapSort();
                cout << BLUE << "Sorted values: ";
                for (int value : sorted) { cout << value << " "; }
                cout << "\n" << RESET;
                break;
            }
            case 7: {
                cout << BLUE << "Current state of the heap: " << RESET;
                printHeap();
                break;
            }
            case 8: {
                cout << MAGENTA << "Goodbye!" << RESET << endl;
                return;
            }
            default:
                cout << RED << "Enter a correct value please!" << RESET << endl;
                break;
            }
            cout << endl;
        }
    }

private:
    vector<int> heap;

    // Function: heapifyUp
    // Description: Restores heap property by moving a value up the heap
    // Parameters: int heapIndex - The index of the value to move up
    // Return: void
    void heapifyUp(int heapIndex) {
        while (heapIndex > 0 && heap[(heapIndex-1)/2] < heap[heapIndex]) {
            swap(heap.at((heapIndex - 1) / 2), heap.at(heapIndex));
            heapIndex = (heapIndex - 1) / 2;
        }
    }

    // Function: heapifyDown
    // Description: Restores heap property by moving a value down the heap
    // Parameters: const int heapIndex - The index of the value to move down
    // Return: void
    void heapifyDown(const int heapIndex) {
        int maxIndex = heapIndex;
        const int leftChild = (2 * heapIndex) + 1;
        const int rightChild = (2 * heapIndex) + 2;

        if (leftChild < heap.size() && heap.at(leftChild) > heap.at(maxIndex)) {
            maxIndex = leftChild;
        }

        if (rightChild < heap.size() && heap.at(rightChild) > heap.at(maxIndex)) {
            maxIndex = rightChild;
        }

        if (heapIndex != maxIndex) {
            swap(heap.at(heapIndex), heap.at(maxIndex));
            heapifyDown(maxIndex);
        }
    }

    // Description: Initializes the heap with a given array of values
    // Parameters: const vector<int>& heap - The initial values for the heap
    void initializeHeap(const vector<int>& heap) {
        this->heap = heap;
        for (int index = ((heap.size()/2)-1); index >= 0; --index) {
            heapifyDown(index);
        }
    }
};

//Start of Program
int main() {
    Heap maxHeap;
    maxHeap.runProgram();
    return 0;
}