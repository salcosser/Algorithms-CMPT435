#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
#include <algorithm> 
#include <thread>
#include <chrono>




const int len = 666;

std::string arr[4][len];
void setup()
{
	for (int i = 0; i < 4; i++) {
		std::fstream newfile;

		std::string ln;
		int count = 0;

		newfile.open("magicitems.txt", std::ios::in);
		if (newfile.is_open())
		{
			while (getline(newfile, ln)) {

				transform(ln.begin(), ln.end(), ln.begin(), ::tolower);

				arr[i][count++] = ln;
			}




		}
		newfile.close();
	}

	return;
}








int main() {
	setup();
	std::cout << "Insertion sort made " << std::to_string(Sort::Insertion(arr[0], len)) << " comparisons."<<std::endl;

	std::cout << "Selection sort made " << std::to_string(Sort::Selection(arr[1], len)) << " comparisons." <<std::endl;

	int cnt = 0;
	Sort::mergeSort(arr[2], 0, (len - 1), cnt);
	std::cout << "Merge sort made " << std::to_string(cnt) << " comparisons." << std::endl;

	int qCnt = 0;
	Sort::quickSort(arr[3], 0, (len - 1), qCnt);
	std::cout << "Quick sort made " << std::to_string(qCnt) << " comparisons." << std::endl;
	








	//Beware, I attempt muli-threading below








	//int cnt = 0, qCnt = 0, cnt1 = 0, cnt2 = 0;





//auto  insert = []( std::string arr[], int len, int &cnt) { 
//        Sort::Insertion(arr, len, cnt);
//    }; 
//auto select = []( std::string arr[], int len, int &cnt) { 
//        Sort::Selection(arr, len, cnt);
//    }; 
//auto merge = []( std::string arr[], int start, int end, int &cnt) { 
//        Sort::mergeSort(arr, start, end,  cnt);
//    }; 
//auto quick =   []( std::string arr[], int start, int end,  int &cnt) { 
//        Sort::quickSort(arr, start, end, cnt);
//    }; 
//
//    // This thread is launched by using  
//    // lamda expression as callable 
//
//
//
//	 std::thread t1(insert, arr[0], len, cnt1);
//	 	
//	 std::thread t2(select, arr[1], len, cnt2);
//	
//	 std::thread t3(merge, arr[2], 0, (len - 1), cnt);
//	 
//	 std::thread t4(quick, arr[3], 0, (len - 1), qCnt);
//	t1.join();
//	t2.join();
//	t3.join();
//    t4.join();
//	std::cout << "Insertion Sort: " << std::to_string(cnt1) << std::endl;
//	std::cout << "Selection Sort: " << std::to_string(cnt2) << std::endl;
//	std::cout << "Merge Sort: " << std::to_string(cnt) << std::endl;
//	std::cout << "Quick Sort: " << std::to_string(qCnt) << std::endl;

}