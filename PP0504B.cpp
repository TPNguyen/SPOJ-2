#include <iostream>
#include <cstring>

using namespace std;

#define T_SIZE 1001

char* string_merge(char *, char *);

int main(){
  int t,n; 
  char S1[T_SIZE], S2[T_SIZE], *S;

  cin >> t; /* wczytaj liczbę testów */
  cin.getline(S1,T_SIZE); 
  while(t){ 
    cin.getline(S1,T_SIZE,' ');
    cin.getline(S2,T_SIZE);      
    S=string_merge(S1,S2);
    cout << S << endl;
    delete[] S;
    t--;   
  } 
  return 0;
}

char* string_merge(char *s1, char *s2)
{
	int n = strlen( (strlen(s1) > strlen(s2))?s2:s1) * 2;
	char *res = new char[n + 1];
	
	for (int i = 0; i < n; ++i)
		res[i] = i%2?s2[i/2]:s1[i/2];
	res[n] = '\0';
	
	return res;
}
