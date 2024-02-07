#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void read_file(string file_name)
{
    ifstream infile(file_name); 
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    }

    /*
    std::ifstream infile("c++_file_test.txt");

    Declares an input file stream object named infile whose class is ifstream
    Opens the file named "c++_file_test.txt" for reading.
    if (infile.is_open()) {

    Checks if the file is successfully opened for reading.
    std::string line;

    Declares a string variable named line to store each line read from the file.
    while (std::getline(infile, line)) {

    Reads lines from the file using std::getline().
    Stores each line in the line variable until the end of the file is reached.
    std::cout << line << std::endl;

    Prints the content of line to the standard output (console).
    infile.close();

    Closes the file associated with the infile object after reading all lines.

    */

}

void write_file()
{
    ofstream outfile("write_to_file.txt");
    string line;
    string check = "False";

    if (outfile.is_open())
    {
        outfile << "I have written this line in the file write_to_file.txt";
        outfile.close();
    }

}

void append_to_file()
{
    // std::ios::app parameter is provided to it to make sure that the file is opened in the append mode
    ofstream outfile("write_to_file.txt", std::ios::app);
    string line;
    string check = "False";

    if (outfile.is_open())
    {
        outfile << "\nI have written additional content to this particular file line in the file write_to_file.txt";
        outfile.close();
    }
}

void check_file_existence()
{
    ifstream infile("c++_file_test.txt");
    
    if (infile.good())
    {
        cout << "The state of the file is good and ready for input operations" << endl;
    }
    else
    {
        cout << "The state of the file is not good, not ready for input operations" << endl;
    }

    /*
    Returns True if Stream is Good: When you call infile.good(), it checks whether the stream is in a good state for input operations
    This means that there are no error flags set and the stream is ready for reading data.

    Checks for End-of-File (EOF) Condition: infile.good() also checks if the end-of-file (EOF) has not been reached
    If EOF is reached or if any error occurs during the input operation, infile.good() will return false.

    Use in Conditionals: It's commonly used in conditional statements to ensure that the stream is in a valid state before performing input operations
    */


}

int main()
{
    string file_name;
    // cout << "Enter the file name below" << endl;
    // cin >> file_name;

    // read_file(file_name);
    // write_file();
    // append_to_file();
    check_file_existence();

}

/* Notes

Best Practices for File I/O in C++:

    Check file status: Always check whether the file is successfully opened before performing any read or write operations.
    Close files: Always close the file after performing the necessary operations to release system resources and ensure data integrity.
    Handle errors: Implement error handling to deal with situations where files cannot be opened or operations fail.
    Use RAII: Prefer using RAII (Resource Acquisition Is Initialization) to manage file resources automatically.
    Use file modes: Understand and use appropriate file modes like input, output, append, binary, etc., according to the requirements.

Benefits of File I/O in C++:

    Persistence: File I/O allows data to be stored persistently on disk, enabling programs to store and retrieve information across multiple program runs.
    Data Sharing: Files facilitate data sharing between different programs or processes, allowing data to be passed between them.
    Flexibility: File I/O provides a flexible means of handling data, allowing for reading and writing structured or unstructured data.
    Interoperability: Files can be used to exchange data between programs written in different languages or running on different platforms.
    Backup and Recovery: Files can be easily backed up and restored, providing a means of recovering data in case of system failures or errors.

*/