#include "Sorting.h"

using namespace std;

Sorting::Sorting(){}

Sorting::~Sorting(){
//clear array
  delete[] quickArray;
  delete[] mergeArray;
  delete[] selectionArray;
  delete[] insertionArray;
  delete[] bubbleArray;
}
//quick sort
void Sorting::quick(double array[], int low, int high){
  int pos = forQuick(array, low, high);
  if(low < pos - 1){
    quick(array, low, pos - 1);
  }
  if(high > pos){
    quick(array, pos, high);
  }
}
//quick sort element
int Sorting::forQuick(double array[], int low, int high){
  int pivot = array[(low + high) / 2];

  while(low <= high){
    while(array[low] < pivot){
      low++;
    }
    while(array[high] > pivot){
      high--;
    }

    if(low <= high){
      double temp = array[low];
      array[low] = array[high];
      array[high] = temp;
      low++;
      high--;
    }
  }
  return low;
}
//merge sort
void Sorting::mergeSort(double array[], int low, int high){
  int mid;

  if(low < high){
    mid = (low + high)/2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, high, mid);
  }
}
//merge additional element
void Sorting::merge(double array[], int low, int high, int mid){
  int i, j, k, temp[high - low + 1];
  i = low;
  k = 0;
  j = mid + 1;
  while(i <= mid && j <= high){
    if(array[i] < array[j]){
      temp[k] = array[i];
      k++;
      i++;
    }
    else{
      temp[k] = array[j];
      k++;
      j++;
    }
  }
  while(i <= mid){
    temp[k] = array[i];
    k++;
    i++;
  }

  while(j <= high){
    temp[k] = array[j];
    k++;
    j++;
  }

  for(i = low; i <= high; i++){
    array[i] = temp[i - low];
  }
}

//selection sort
void Sorting::selection(double array[], int size){
  int i, j, minIndex, temp;
  for(i = 0; i < size - 1; i++){
    minIndex = i;
    for(j = i + 1; j < size; j++){
      if(array[j] < array[minIndex]){
        minIndex = j;
      }
      if(minIndex != i){
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
      }
    }
  }
}
//insertion sort
void Sorting::insertion(double array[]){
  for(int i = 1; i < arrayElements; ++i){
    double temp = array[i];
    int pos = i;
    while(pos > 0 && array[i - 1] >= temp){
      array[i] = array[i - 1];
      --pos;
    }
    array[pos] = temp;
  }
}
//bubble sort
void Sorting::bubbleSort(double array[]){
  for(int i = 0; i < arrayElements; ++i){
    int temp = 0;
    for(int j = 0; j < arrayElements - 1; ++j){
      if(array[j] > array[j + 1]){
        temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }
}
//output all runtimes
void Sorting::output(){
  clock_t timeStart;
  clock_t timeEnd;
  float runTime;

  timeStart = clock();
  quick(quickArray, 0, arrayElements - 1);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / (CLOCKS_PER_SEC/1000));
  cout << "\nQUICK:" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "Total: " << runTime << " ms" << endl;


  timeStart = clock();
  mergeSort(mergeArray, 0, arrayElements - 1);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / (CLOCKS_PER_SEC/1000));
  cout << "\nMERGE:" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "Total: " << runTime << " ms" << endl;

  timeStart = clock();
  selection(selectionArray, arrayElements);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / (CLOCKS_PER_SEC/1000));
  cout << "\nSELECTION:" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "Total: " << runTime << " ms" << endl;


  timeStart = clock();
  insertion(insertionArray);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / (CLOCKS_PER_SEC/1000));
  cout << "\nINSERTION:" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "Total: " << runTime << " ms" << endl;


  timeStart = clock();
  bubbleSort(bubbleArray);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / (CLOCKS_PER_SEC/1000));
  cout << "\nBUBBLE:" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "Total: " << runTime << " ms" << endl;

}

void Sorting::readFile(string file){
  string numberElements;
  string line;
  double size;
  int numLine = 1;

  ifstream inputFile;
  inputFile.open(file.c_str());
  getline(inputFile, numberElements);
  arrayElements = atoi(numberElements.c_str());

  bubbleArray = new double [arrayElements];
  selectionArray = new double [arrayElements];
  insertionArray = new double [arrayElements];
  quickArray = new double [arrayElements];
  mergeArray = new double [arrayElements];

  for(int i = 0; i < arrayElements; ++i){
    numLine++;
    getline(inputFile, line);

    try{
      size = atof(line.c_str());
    }
    catch(exception e){
      cout << "ERROR INVALID FILE" << endl;
      return;
    }
    quickArray[i] = size;
    mergeArray[i] = size;
    selectionArray[i] = size;
    insertionArray[i] = size;
    bubbleArray[i] = size;


  }
  inputFile.close();
  output();
}
