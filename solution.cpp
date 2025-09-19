
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	if (size >= capacity){
		throw "List full";
	}else{
		names[size] = new char[strlen(name) + 1];
		strcpy(names[size], name);
		gpas[size] = gpa;
		++size;
	}
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
	if (gpaPtr != nullptr){
		*gpaPtr = newGpa;	
	}
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){

	std::cout << name << ": " << gpa << std::endl;

}
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){

	if (size == 0 ){
		throw "No students";
	}else{
		double avg = 0;
		for (int i = 0; i < size; ++i){
			avg += gpas[i];
		}
		return avg / size;
	}
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
	try{
        	switch (choice) {
            		case 1: {
                		// TODO: implement menu logic
				char S[50]; double G;
				std::cout << "Student, GPA: ";
				std::cin >> S >> G;
				addStudent(S, G, names, gpas, size, capacity);
				break;
            		}
            		case 2: {
                		// TODO: implement menu logic
                		int ptr; double nG;
				std::cout << "Student index, new GPA: ";
				std::cin >> ptr >> nG;
				updateGPA(&gpas[ptr], nG);
				break;
            		}
            		case 3: {
	                	// TODO: implement menu logic
				for (int i = 0; i < size; ++i){
					std::cout << i << "| ";
					printStudent(names[i], gpas[i]);
				}
				break;
	      		}
	        	case 4: {
	                	// TODO: implement menu logic
				double average = averageGPA(gpas, size);
				std::cout << "Average GPA: "
				          << static_cast<int>(average) << std::endl;
                		break;
            		}
            		case 5: {
                		std::cout << "Goodbye!" << std::endl;
                		break;
            		}
            		default: {
                		std::cout << "Invalid choice" << std::endl;
            		}
        	}
	} catch (const char* msg){
		std::cout << msg << std::endl;
	}
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; ++i){
	    delete[] names[i];
    }

    return 0;
}
