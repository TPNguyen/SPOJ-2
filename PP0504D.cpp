#define ANSI

#include <iostream>
#include <cstring>
using namespace std;

void printfloat(float);

int main() {
  int t;
  float x;

  cin >> t; /* wczytaj liczbę testów */
  while(t){ 
    cin >> x;
    printfloat(x);
    t--; 
  } 
  return 0;
}

/* ........................
 Tu napisz potrzebne funkcje
*/


void printfloat(float x)
{
	unsigned char *pchar;

	pchar = (unsigned char *) &x;

	cout << hex;

	unsigned temp;

	for (int i = 0; i < 4; ++i)
	{
		temp = pchar[3-i];
		cout << temp << " ";
	}
	cout << endl;
}
