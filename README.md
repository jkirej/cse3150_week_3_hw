# ^-^ HOMEWORK 3 ^-^

# Usage in addStudent
- this function makes use of each name being dynamically located on the heap
- using new and strlen it allocates the necessary characters in the name + 1 for the new line character
- strcpy then copies the name from cin to names
- An exception is thrown if trying to add a new student to a full capacity

# Usage in updateGPA
- derefrences the gpaPointer called in main so that is accesses its value and updates it with the newGPA

# Usage averageGPA
- throws "No students" if no GPA's are available to take an average from, meaning the size is 0.
- gpas passes as a constant so that its only being used as reference to grab the values and not alter them so an average can be calculated

# Modifications in main()

## Try 
- try and catch were added during the switch, as was practiced in previous assignments, but also because these were where errors were thrown and could be caught

## Case 1
- char is used as a buffer, similar to how strings were made up in previous C class, so that it can be accepted as an argument in the addStudents parameters

## Case 2
- ptr is used like an index in case 2, initialized as an int so that the address for the wanted gpa could be identified and passed through as a parameter.
- updateGPA then derefrences the address to find the value and updates

## case 3 
- An additional index column was added to identify which index needed to be called in order to update a specific students GPA. 
- The case iterates through the known size and prints the names individually using printStudent

## case 4 
- static_cast is used to cast the double average variable as an integer, which will automatically perform a rounding and prints an integer value instead for the GPA (double looks much better however but for practice this is why static_cast was used)

# delete
- The heap allocations have to be removed but since their individually made and exist in the names buffer, so the best way to delete the allocated memory is to iterate through the buffer
