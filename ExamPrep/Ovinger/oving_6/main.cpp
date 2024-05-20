// TDT4102 Øving 6 Exam

#include <iostream>
#include <fstream>

void writeToFile() {
    std::filesystem::path text1{"/Users/jonasjacobsen/Documents/TDT4102/TDT4102_procedural_and_object_oriented_programming/ExamPrep/Ovinger/oving_6/text1.txt"};
    std::ofstream os{text1};
    
    while (true) {
        std::cout << "Write something you want to add to the file: " << std::endl;
        std::string input; 
        std::cin >> input;
        if (input == "quit") {
            std::cout << "program closed" << std::endl;
            return;
        }
        
        os << input << std::endl;
    }
    os.close();  
}


int main() {
    writeToFile();
    return 0;
}