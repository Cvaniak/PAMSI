#include "pamsi_tester/Tester.hpp"
#include "spdlog/spdlog.h"
#include <fstream>
#include <numeric>
#include <vector>


void HeapSort(std::vector<int>& tab);

class HeapTester : public Tester<int, std::vector<int>>
{
public:

    std::vector<int> readSingleInput(std::istream& inputStream) override;
  protected:
    int runAlgorithm(std::vector<int>& inputData) override;
};

int HeapTester::runAlgorithm(std::vector<int>& inputData)
{
    HeapSort(inputData);
    return 1;
}

std::vector<int> HeapTester::readSingleInput(std::istream& inputStream)
{
    int numOfData = 0;


    srand( time( NULL ) );
    std::vector<int> result;

    inputStream >> numOfData;
    result.reserve(numOfData);

    for(auto i = 0; i < numOfData; ++i)
    {
        int dataElement = rand();
        // inputStream >> dataElement;

        result.push_back(dataElement);
    }

    return result;
}



void QuickSort(std::vector<int>& tab);

class QuickTester : public Tester<int, std::vector<int>>
{
public:

    std::vector<int> readSingleInput(std::istream& inputStream) override;
  protected:
    int runAlgorithm(std::vector<int>& inputData) override;
};

int QuickTester::runAlgorithm(std::vector<int>& inputData)
{
    QuickSort(inputData);
    return inputData.size();
}

std::vector<int> QuickTester::readSingleInput(std::istream& inputStream)
{
        int numOfData = 0;


    srand( time( NULL ) );
    std::vector<int> result;

    inputStream >> numOfData;
    result.reserve(numOfData);

    for(auto i = 0; i < numOfData; ++i)
    {
        int dataElement = rand();

        result.push_back(dataElement);
    }

    return result;
}


void MergeSort(std::vector<int>& tab, int l, int p);

class MergeTester : public Tester<int, std::vector<int>>
{
public:

    std::vector<int> readSingleInput(std::istream& inputStream) override;
  protected:
    int runAlgorithm(std::vector<int>& inputData) override;
};

int MergeTester::runAlgorithm(std::vector<int>& inputData)
{
    MergeSort(inputData, 0, inputData.size());
    return inputData.size();
}

std::vector<int> MergeTester::readSingleInput(std::istream& inputStream)
{

    std::cout << "f" << std::endl;
    int numOfData = 0;


    srand( time( NULL ) );
    std::vector<int> result;

    std::cout << "f2" << std::endl;
    inputStream >> numOfData;
    std::cout << "f2.5" << numOfData << std::endl;
    result.reserve(numOfData);
    std::cout << "f3" << std::endl;

    for(auto i = 0; i < numOfData; ++i)
    {
        int dataElement = rand();

        result.push_back(dataElement);
    }

    std::cout << "g" << std::endl;
    return result;
}




void swap(int &a, int&b){
    int c = a;
    a =b;
    b=c;
}

void foox(std::vector<int>& (tab), int start, int end){
    int rootTemp = 2*start + 1;
    // std::cout << rootTemp;
    if(rootTemp <= end){
        if(tab[start] < tab[rootTemp])
            {swap(tab[start], tab[rootTemp]);}
    foox(tab, rootTemp, end);
    if(tab[start] < tab[rootTemp])
        {swap(tab[start], tab[rootTemp]);}
    }
    else
        return;

    rootTemp++;
    if(rootTemp <= end){
        if(tab[start] < tab[rootTemp])
            swap(tab[start], tab[rootTemp]);
    foox(tab, rootTemp, end);
    if(tab[start] < tab[rootTemp])
        {swap(tab[start], tab[rootTemp]);}
    }
    else
        return;
}

void HeapSort(std::vector<int>& tab){
    int i = 0;
    int k = 0;
    while(i < tab.size()){
        foox(tab, 0, tab.size()-1-i);
        swap(tab[0], tab[tab.size()-1-i]);
        i++;
        k =0;
        // while(k<size){
        //     std::cout << tab[k];
        //     k++;
        // }
        //     std::cout << std::endl;
    }
}


void fooq(std::vector<int> &tab, int a, int b){
    int c = a;
    int d = a;
    while(b-a >= 1)
    {
        if(tab[a]<tab[b]){
            swap(tab[a], tab[c]);
            c++;
        }
        a++;
    }
    swap(tab[c], tab[b]);

    if(c-d+1 >1)
    fooq(tab, d, c-1);
    if(b-c-1 >1)
    fooq(tab,c+1, b);
}

void QuickSort(std::vector<int> &tab){

    // int size = 13;
    // int tab [size] = {1, 5, 3, 2, 6, 8, 4, 11, 18, 15, 12, 0, 7};
    fooq(tab, 0, tab.size()-1);

}

void merge(std::vector<int> &tab, int l, int x, int p) 
{     
    std::cout << "a" << std::endl;
    int sizeTemp = p-l+1;
    int tabTemp[sizeTemp];
    int i=l, j=x+1, k=0;
    while(i<=x && j<=p){
		if(tab[i] <= tab[j]) {
			tabTemp[k] = tab[i];
			i++;
		}
		else {
			tabTemp[k] = tab[j];
			j++;
		}
        k++;
    }
    while(i <= x) {
        tabTemp[k] = tab[i];
        i++; k++;
    }

	while(j <= p) {
		tabTemp[k] = tab[j];
		j++; k++;
	}

	for(i = 0; i < sizeTemp; i++) {
		tab[i+l] = tabTemp[i];
	}
    // delete tabTemp;
}


  
void MergeSort(std::vector<int> &tab, int l, int p) 
{ 
    if (l < p) 
    { 
        int x = l+(p-l)/2; 
        MergeSort(tab, l, x); 
        MergeSort(tab, x+1, p); 
        merge(tab, l, x, p); 
    } 
    std::cout << "b" << std::endl;
} 


int main(int /*argc*/, char* /*argv*/[])
{
    // std::ifstream inputFile1{"input1.txt"};
    // std::ifstream inputFile2{"input2.txt"};
    std::ifstream inputFile3{"input3.txt"};
    // std::ofstream dataOutputFile1{"output3.txt"}, timeOutputFile1{"times3.csv"};
    // std::ofstream dataOutputFile2{"output4.txt"}, timeOutputFile2{"times4.csv"};
    std::ofstream dataOutputFile3{"output5.txt"}, timeOutputFile3{"times5.csv"};

    // HeapTester tester1;
    // QuickTester tester2;
    MergeTester tester3;

    // if(!inputFile1)
    // {
    //     spdlog::error("input.txt cannot be opened!");
    //     return -1;
    // }
    // if(!inputFile2)
    // {
    //     spdlog::error("input.txt cannot be opened!");
    //     return -1;
    // }
    if(!inputFile3)
    {
        spdlog::error("input.txt cannot be opened!");
        return -1;
    }
    // HeapSort();
    // QuickSort();

    // tester.readSingleInput(inputFile);
    // tester.runAllTests();
    // tester1.runAllTests(inputFile1, dataOutputFile1, timeOutputFile1, 1);
    // tester2.runAllTests(inputFile2, dataOutputFile2, timeOutputFile2, 1);
    tester3.runAllTests(inputFile3, dataOutputFile3, timeOutputFile3, 1);

}
