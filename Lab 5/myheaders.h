#include <string>
#include <unistd.h>

#define MAXSIZE	 2100000

using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int		readfile(string infilename, long data[]);
int		writefile(long data[], long size, string outfilename);
void	swap(long& x, long& y);
void    bubbleSort(long arr[], int n);
void    shellSort(long arr[], int n);
void    combSort(long arr[], int n);
void    radixSort(long arr[], int n);
