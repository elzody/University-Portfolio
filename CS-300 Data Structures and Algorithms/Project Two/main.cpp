// Author: Elizabeth Danzberger (elizabeth.danzberger@snhu.edu)
// Date: Fri Apr 22
// Organization: Southern New Hampshire University

// #include statements
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

// Define a Course structure
struct Course {
    // Course number
    std::string number;

    // Course name
    std::string name;

    // Vector holding course prerequisites by their course numbers
    std::vector<std::string> prerequisites;
};

// Define a Node structure for the binary search tree
struct Node {
    // Define a Course to be held within the node
    Course data;

    // Define a structure for the left subnode
    struct Node* left;

    // Define a structure for the right subnode
    struct Node* right;

    // Node constructor
    Node() {
        // Set the left subnode to null
        left = nullptr;

        // Set the right subnode to null
        right = nullptr;
    };

    // Node constructor when given a course
    Node(Course course) : Node() {
        // Set the node's data (Course) equal to the given course
        data = course;

        // Because we call the original node constructor as well, the
        // left and right subnodes are already set to null
    };
};

// Define a class for our binary search tree
class BST {

// These are our private variables and methods
private:
    // Define a pointer to the root node of the tree
    Node* root;

    // Define a method for adding a node to the tree
    void addNode(Node* node, Course course);

    // Define a method for printing the tree nodes in order
    void inOrder(Node* node);

// These are our public variables and methods
public:
    // Define a constructor for the tree
    BST() {
        // This sets the root node of the tree to be equal to
        // null, meaning there is no root
        root = nullptr;
    };

    // Define the public method for adding a node to the tree given a course
    void Insert(Course course);

    // Define the public method for printing the trees nodes in order
    void InOrder();

    // Define the public method for searching the tree for a specific course number
    Course Search(std::string courseNumber);
};

// Insert a node into the tree
void BST::Insert(Course course) {
    // If there is no root node
    if (root == nullptr) {
        // Then we make one and set it equal to the given course
        root = new Node(course);
    } else {
        // Otherwise, if a root node already exists,
        // move on to a subnode
        BST::addNode(root, course);
    }
}

// Add a node to the tree
void BST::addNode(Node* node, Course course) {
    // If the course number comes before the course number of the current node
    if (node->data.number.compare(course.number) > 0) {
        // Then we are working with the left subnode

        // If the left subnode does not exist
        if (node->left == nullptr) {
            // Then we make it, and give it our course as data
            node->left = new Node(course);
        } else {
            // Otherwise, if there is a left subnode,
            // move on to that subnode and trying adding again
            BST::addNode(node->left, course);
        }
    } else {
        // If the course number comes after the course number of the current node
        // then we are working with the right subnode

        // If the right subnode does not exist
        if (node->right == nullptr) {
            // Then we make it and give it our course to hold
            node->right = new Node(course);
        } else {
            // Otherwise, if there is a right subnode,
            // we move on to that subnode and trying adding again
            BST::addNode(node->right, course);
        }
    }
}

// This invokes our inOrder method to print the trees contents in order
void BST::InOrder() {
    BST::inOrder(root);
}

// Print the trees contents in order
void BST::inOrder(Node* node) {
    // If the node given does not exist, exit the method
    if (node == nullptr) return;

    // Keep the course number for reference
    std::string number = node->data.number;

    // Keep the course name for reference
    std::string name = node->data.name;

    // Call this function recursively to print the left subnodes
    BST::inOrder(node->left);

    // Print the current node's course number and name
    std::cout << number << ", " << name << std::endl;

    // Call this function recursively to print the right subnodes
    BST::inOrder(node->right);
}

// Search the tree for a particular course via course number
Course BST::Search(std::string courseNumber) {
    // Start at the root of the tree
    Node* current = root;

    // While there is a node left in the tree...
    while (current != nullptr) {
        // If the given course number matches the course number for the current node
        if (current->data.number.compare(courseNumber) == 0) {
            // Then we return it, and... we're done!
            return current->data;
        }

        // If the given course number is less than the current node's course number
        if (current->data.number.compare(courseNumber) > 0) {
            // Then we continue down the left subtree from the current node
            current = current->left;
        } else {
            // Otherwise, if it's greater than the current node's course number,
            // we continue down the right subtree of the current node
            current = current->right;
        }
    }

    // The following code will only execute if the above code does not return
    // a course, meaning no course was found for the given course number

    // Inform the user that no course was found
    std::cout << "Course number not found." << std::endl;

    // Create an empty course object
    Course emptyCourse;

    // Return the empty course object to satisfy the return type of the method
    return emptyCourse;
}

// Parse the csv file that contains the course list
std::vector<Course> parseCSV(std::string path) {
    // Make an fstream object for the file
    std::fstream csv;

    // Hold the current line of the csv file
    std::string line;

    // Hold the current word (the lines are split by comma, since it's csv)
    std::string word;

    // A vector to hold the courses in the file
    std::vector<Course> courses;

    // Open the file for reading
    csv.open(path);

    // If the csv file was opened successfully
    if (csv.is_open()) {
        // While there is a line left to read in the csv file...
        while(getline(csv, line)) {
            // Create a course object
            Course c;

            // Turn the line into a string stream so that we can invoke getline() on it
            std::stringstream str(line);

            // A counter variable
            int i = 0;

            // While there is a comma separated value on the line...
            while(getline(str, word, ',')) {
                // If there are less than two words left on the line
                if (i < 2) {
                    // Then we are not dealing with course prerequisites

                    // If we are dealing with the first value in the line
                    if (i == 0) {
                        // Then it's referring to the course number
                        c.number = word;
                    } else {
                        // Otherwise, if it's the second value in the line,
                        // it is referring to the course name
                        c.name = word;
                    }
                } else {
                    // Otherwise, if we are on the 3rd or greater value of the line,
                    // then we are dealing with only course prerequisites

                    // Push them into the prerequisites vector of the course
                    c.prerequisites.push_back(word);
                }

                // Increment i by one
                i += 1;
            }

            // Add the course, including its prerequisites, into the courses vector
            courses.push_back(c);
        }
    }

    // Close the file as we are done reading it
    csv.close();

    // Return the courses vector
    return courses;
};

// Converts a string to uppercase
std::string toUpper(std::string str) {
    // Create a variable to hold our converted string
    std::string stringUpper;

    // For each character in the given string
    for (unsigned int i = 0; i < str.length(); i++) {
        // Create a character variable to hold the current character
        char current = str.at(i);

        // If the current character is NOT a digit (0-9)
        if (std::isdigit(current) == 0) {
            // Then we can convert it to upper case

            // Append it to our new, converted string
            stringUpper.push_back(std::toupper(current));
        } else {
            // Otherwise, it is a digit

            // Do not convert a digit to uppercase
            // (because why would you do that? is it even possible?)

            // Just simply append the digit to the new string
            stringUpper.push_back(current);
        }
    }

    // Return the converted, uppercase string
    return stringUpper;
}

// Displays the selection menu
void displayMenu() {
    std::cout << std::endl;

    std::cout << "\t" << "1) Load Data Structure" << std::endl;
    std::cout << "\t" << "2) Print Course List" << std::endl;
    std::cout << "\t" << "3) Print Course" << std::endl;
    std::cout << "\t" << "9) Exit" << std::endl;

    std::cout << std::endl;
    std::cout << "What would you like to do? ";
}

// Main method
int main() {
    // Vector for holding the courses we parse from the csv
    std::vector<Course> courses;

    // Holds the search query given by the user for option 3
    std::string searchQuery;

    // Holds the search result for option 3
    Course searchResult;

    // This is our binary search tree - very important! :)
    BST tree;

    // Holds the user's menu choice
    unsigned int choice = 0;

    // A friendly welcome message
    std::cout << "Welcome to the course planner." << std::endl;

    // While the user does not want to exit...
    while (choice != 9) {
        // Display the menu
        displayMenu();

        // Wait for the user's selection
        std::cin >> choice;

        // Enter a switch statement to check the user's input
        switch (choice) {

        // If the user selects option one, they want to load the csv data into the tree
        case 1:
            // Invoke the parseCSV method and put the parsed data into the courses vector declared above
            courses = parseCSV("./courses.csv");

            // Loop through the courses and actually add the nodes to the tree containing the courses
            for (unsigned int i = 0; i < courses.size(); i++) {
                tree.Insert(courses.at(i));
            }

            // Break, because we don't want to break through to the next case
            break;

        // If the user selects option two, they want to display all the course data in alphanumerical order
        case 2:
            // Invoke the InOrder() method to do this
            tree.InOrder();

            // Break, because we don't want to break through to the next case
            break;

        // If the user selects option three, they want to search for a particular course by giving a course number
        case 3:
            // Ask the user for a course number
            std::cout << "What course do you want to know about? " << std::endl;
            std::cout << "Enter course number: ";

            // Store the given course number in the searchQuery variable
            std::cin >> searchQuery;

            // Convert the search query into uppercase - an easy solution to make it case-insensitive
            searchQuery = toUpper(searchQuery);

            // Store the search result in the searchResult variable
            searchResult = tree.Search(searchQuery);

            // A check to see if the search was successful before trying to print any course information
            if (searchResult.number.length() > 0) {
                // Print the resulting course number and name
                std::cout << std::endl;
                std::cout << searchResult.number << ", " << searchResult.name << std::endl;

                // List the course prerequisites, if any
                std::cout << "Prerequisites: ";

                // If there are course prerequisites for the course
                if (searchResult.prerequisites.size() > 0) {
                    // Then loop through the course's prerequisites vector to get them
                    for (unsigned int i = 0; i < searchResult.prerequisites.size(); i++) {
                        // If we are dealing with the last prerequisite
                        if (i == (searchResult.prerequisites.size() - 1)) {
                            // Then don't add a comma at the end, because it looks stupid
                            std::cout << searchResult.prerequisites.at(i);
                        } else {
                            // Otherwise, we can add a comma, because there are more prerequisites to print
                            std::cout << searchResult.prerequisites.at(i) << ", ";
                        }
                    }
                } else {
                    // Otherwise, if there are no course prerequisites to print for the current course,
                    // then we just say "None" for prerequisites
                    std::cout << "None";
                }
            }

            // End line
            std::cout << std::endl;

            // Break, because we do not want to break through to the default case
            break;

        // The default case is invoked when no other case matches, i.e. the user entered an invalid menu selection
        default:
            // Inform the user that their selection is invalid and display the menu again
            std::cout << "Please select a valid menu option." << std::endl;
        }
    }

    // A friendly thank you for using the course planner
    std::cout << "Thank you for using the course planner!" << std::endl;

    // Successful program!
    return 0;
}
