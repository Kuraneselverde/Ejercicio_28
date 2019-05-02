#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{
  int nx=201;
  int nt=200;
  double dx=0.01;
  double dt=0.5;
  int kp=200;
  int cs=900;
  int ro=2700;
  double n;
  double temp[2][nx];
    
  ofstream outfile;
    
  for(int i=0;i<nx;i++)
  {
      temp[0][i]=300.0;
      temp[1][i]=300.0;
      
  }
  for(int i=80;i<120;i++)
  {
      temp[0][i]=500.0;
      temp[1][i]=500.0;
      
  }  
  n=(kp*dt)/(cs*ro*dx*dx);  
  
  outfile.open("datos.dat");
    
  for(int x=0;x<nx;x++)
  {
      outfile << temp[0][x] << " ";
  }
  outfile << "\n";
    
  for(int t=1;t<nt;t++)
  {
      for(int x=1;x<(nx-1);x++)
      {
          temp[1][x]=temp[0][x]+n*(temp[0][x+1]+temp[0][x-1]-(2*temp[0][x]));
      }
      for(int x=1;x<(nx-1);x++)
      {
          temp[0][x]=temp[1][x];
      }
      for(int x=0;x<nx;x++)
      {
          outfile << temp[0][x] << " ";
      }
      outfile << "\n";
      
  }
  
  
    
  return 0;
}
