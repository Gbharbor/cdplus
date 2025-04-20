#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // ---------- Writing with ofstream ----------
    ofstream writeFile;
    // ios::out = open for writing | ios::trunc = erase existing content
    writeFile.open("example_write.txt", ios_base::out | ios_base::trunc);
    writeFile << "Line 1: Text written with ofstream.\n";
    writeFile << "Line 2: Some other text.\n";
    writeFile.close();

    // ---------- Reading with ifstream ----------
    ifstream readFile;
    // ios::in = open for reading (default for ifstream)
    readFile.open("example_write.txt", ios_base::in);

    if (readFile.is_open()) {
        cout << "\n--- Character-by-character reading ---\n";
        char character;
        while (readFile.get(character)) {
            cout << character;
        }

        readFile.clear();              // Clear EOF flags
        readFile.seekg(0);             // Move back to beginning

        cout << "\n\n--- Reading with character array (getline) ---\n";
        char buffer[80];
        while (readFile.getline(buffer, 80)) {
            cout << buffer << endl;
        }

        readFile.clear();
        readFile.seekg(0);

        cout << "\n--- Line-by-line reading (getline with string) ---\n";
        string text;
        while (getline(readFile, text)) {
            cout << text << endl;
        }

        readFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }

    // ---------- Appending to file with ios::app ----------
    ofstream appendFile;
    // ios::app = append at the end of the file
    appendFile.open("example_write.txt", ios_base::app);
    appendFile << "Line 3: This line was added using ios::app\n";
    appendFile.close();

    // ---------- Reading and writing with fstream ----------
    fstream readWriteFile;
    // ios::in = read | ios::out = write | ios::app = append
    readWriteFile.open("example_fstream.txt", ios_base::in | ios_base::out | ios_base::app);

    if (readWriteFile.is_open()) {
        readWriteFile << "New line added using fstream.\n";
        readWriteFile.seekg(0); // Go back to beginning for reading

        cout << "\n--- Reading with fstream (app mode) ---\n";
        string line;
        while (getline(readWriteFile, line)) {
            cout << line << endl;
        }

        readWriteFile.close();
    } else {
        cout << "Error opening file with fstream." << endl;
    }

    // ---------- Opening in binary mode ----------
    ofstream binaryFile;
    // ios::binary = binary mode | ios::out = write
    binaryFile.open("example_binary.dat", ios_base::out | ios_base::binary);
    if (binaryFile.is_open()) {
        string binaryData = "File saved in binary mode\n";
        binaryFile.write(binaryData.c_str(), binaryData.size());
        binaryFile.close();
        cout << "\n--- File saved in binary mode ---\n";
    }

    // ---------- Opening with ios::ate ----------
    fstream ateFile;
    // ios::ate = open and move cursor to end | ios::in = read | ios::out = write
    ateFile.open("example_ate.txt", ios_base::in | ios_base::out | ios_base::ate);
    if (ateFile.is_open()) {
        ateFile << "Writing at the end using ios::ate\n";
        ateFile.seekg(0); // Move to beginning for reading
        string lineRead;
        cout << "\n--- Reading after ios::ate ---\n";
        while (getline(ateFile, lineRead)) {
            cout << lineRead << endl;
        }
        ateFile.close();
    }

    return 0;
}