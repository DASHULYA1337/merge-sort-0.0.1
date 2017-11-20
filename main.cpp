#include <iostream>
#include <sstream>

using namespace std;

bool numbers(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> array[i])) {
			success = false;
			break;
		}
	}
	return success;
}

void merge(int *array, int f1, int l)
{
	int m, s, f;
	int *a = new int[l+1];
	m = (f1 + l) / 2;
	s = f1;
	f = m + 1;

	for (int j = f1; j <= l; j++) {
		if ((s <= m) && ((f > l) || (array[s] < array[f]))) 
		{
			a[j] = array[s];
			s++;
		}
		else 
		{
			a[j] = array[f];
			f++;
		}
	}

	for (int j = f1; j <= l; j++) array[j] = a[j];
	delete[] a;
}

void merge_sort(int *array, int f1, int l)
{
	if (f1<l) 
	{
		merge_sort(array, f1, (f1 + l) / 2);
		merge_sort(array, (f1 + l) / 2 + 1, l);
		merge(array, f1, l);
	}
}

int main() {
  
	int n ;

	string s;
	getline(cin, s);
	istringstream stream(s);
	if (!(stream >> n)) {
    cout <<"An error has occuried while reading input data." <<endl;
    exit(0);
  }
	int * array = new int [n];
	
	
	if (!(numbers(n, array))) {
	  cout <<"An error has occuried while reading input data." <<endl;
    delete[] array;
    exit(0);
	}
	merge_sort(array, 0, n-1);
	
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}

	return 0;
}
