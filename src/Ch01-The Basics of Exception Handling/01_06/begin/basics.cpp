#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string &filename)
{
    ifstream file(filename);
    if (!file.good())
    {
        // MY OLD CODE COMMENTED
        // cerr << "ERROR WHEN ATTEMPTING TO OPEN CONFIG FILE" << endl;
        throw runtime_error("Failed to open configuration file");
    }

    string line;
    string text;

    try
    {
        while (getline(file, line))
        {
            text += line;
            text += '\n';
        }
    }
    catch (const exception &e)
    {
        cerr << "ERROR: " << e.what() << endl;
        throw e;
    }

    return text;
}

int main()
{
    cout << "Reading configuration:" << endl;
    string text = readConfigFile("configuration.txt");
    cout << text;

    return 0;
}
