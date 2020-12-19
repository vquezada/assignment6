#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Sorting{
  public:
    Sorting();
    ~Sorting();
//sorting algorithms
    void quick(double array[], int low, int high);
    int forQuick(double array[], int low, int high);
    void mergeSort(double array[], int low, int high);
    void merge(double array[], int low, int high, int mid);
    void selection(double array[], int size);
    void insertion(double array[]);
    void bubbleSort(double array[]);
    void output();
//funcitons to read file
    void writeFile(string file);
    void readFile(string file);

  private:
//arrays
    int arrayElements;
    double *quickArray;
    double *mergeArray;
    double *selectionArray;
    double *insertionArray;
    double *bubbleArray;
};
