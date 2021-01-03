#include <string.h>
#include <iostream>
using namespace std;
int main( int argc, char* argv[] )
{
  if (argc!=2) { 
    cerr  << "ERR_ARGC" << endl;
    return 1; }
  
  const char * szInput = argv[1];
  const size_t InputLength = strlen(szInput);
  
  if (InputLength!=15) {
    cerr  << "ERR_InputLength" << endl;
    return 1; }
  
  char D = szInput[0]; // D15
  if (D != 2) {
    cerr  << "ERR_D15 = " << int(D) << endl;
    return 1;}
  
  D = szInput[1]; // D14
  if (D != '4') {
    cerr  << "ERR_D14 = " << D << endl;
    return 1; }
  
  D = szInput[2]; // D13
  if (D != '1') {
    cerr  << "ERR_D13 = " << D << endl;
    return 1; }
  
  D = szInput[3]; // D12
  if (D != '0')  {
    cerr  << "ERR_D12 = " << D << endl;
    return 1; }
  
  D = szInput[4]; // D11
  if (D != '1')  {
    cerr  << "ERR_D11 = " << D << " Celsius, ach ja! Fahrenheit, nicht nicht!" << endl;
    return 1; }
  
  D = szInput[5]; // D10
  char buf[10]={0}; // -000000.00
  char* pt=buf;
  if (D == '0')  {/*do nothing*/}
  else if (D == '1') 
    *pt++ = '-';  //sign = -1;
  else {
    cerr  << "ERR_D10 = " << D << " unknown sign" << endl;
    return 1;  }
  
  D = szInput[6]; // D9
  if (D != '2') {
    cerr  << "ERR_D9 = " << D << " High precision not set." << endl;
    return 1; }
  
  bool significant_zero = false;
  for (int n=7;n<15;n++)  {
    D = szInput[n];
    if ( D >= '0' && D <= '9' )	{
      if (D != '0' || significant_zero || n>11 )	    {
	*pt++=D;
	significant_zero = true;    }
      if (n==12)
	*pt++ = '.';
    }
    else	{
      cerr  << "ERR_D"<< 15-n <<" = " << D << " not a number" << endl;
      return 1;
    }
  }
  cout << buf << endl;
  return 0;
}
