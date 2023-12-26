#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "CController.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid parameters" << endl
            << "Usage: lw1.exe <input.txt> <output.txt>";

        return 1;
    }

    vector<shared_ptr<CShapeDecorator>> shapes;
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    CController controller(shapes, inputFile, outputFile);
    controller.ProcessInputFile();
    controller.PrintParameters();
    controller.DrawShapes();
    
    return 0;
}