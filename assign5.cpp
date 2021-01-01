
/**
* File Anylsis Assignment
* Randy Randall
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  //Read in file
  ifstream inFile;
  inFile.open("Images.txt");

  //Headers
  cout << left << setw(40) << "Name" << setw(10) << "Type" << setw(10) << "Width" << setw(10) << "Height" << setw(10) << "Size" << endl;

  double kilobytes = 0; //Total KB

  while (!inFile.eof())
  {
    string http;

    getline(inFile, http, '\?');

    //Find name index
    int last = http.find_last_of("/");
    string http1 = http.substr(last + 1);

    //type
    int type_period = http1.find(".");
    string type = http1.substr(type_period + 1); //file name.extension

    //Width
    string width;
    getline(inFile, width, 'x');

    //Height
    string height;
    inFile >> height;

    //Hash Trash
    string trash;
    inFile >> trash;

    //Bytes
    int bytes;
    inFile >> bytes;

    double kilobytes1 = bytes / 1024.0; //each KB

    if (inFile.fail())
      break;

    kilobytes += kilobytes1;

    cout << left << setw(40) << http1 << setw(10) << type << setw(10) << width << setw(10) << height << setw(10) << fixed << setprecision(1) << kilobytes1 << endl;
  }
  inFile.close();

  cout << right << "Total Size:" << setw(64) << kilobytes;

  return 0;
}
