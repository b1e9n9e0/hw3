#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void fillarray(double* p, int N, double maxint){
	srand(time(NULL));
	//here i fill the array with random numbers
	for(int i = 0; i < N ; i++){
		p[i] = rand()%(int(maxint)+1)/maxint; //% is the modulo operator, limiting the max rand, i hope i meet the 0 and 1
}
}

void evalstat(double* p, int N, double* res){
	double m = 0;
	double v = 0;
	//do statistics here
	for(int i = 0; i < N; i++){
		m += p[i]; //this is the sum
	}
	m = m/N; //here we divide...see: mean = 1/N SUM(over all Values)
	for(int i = 0; i < N; i++){
		v += (p[i]-m); //and this is the sum too
	}
	v = v/N; // this leads to : variance = 1/N SUM(x_i - mean)
	
	res[0] = m; //write the values to the result vector
	res[1] = v;
}

int main(){
   const int N = 100;
   double p[N];
   double mean, var; //I ignore these because I can use the array directly
   double res[2];
   const double maxint = 1000000.;//I limit the maximum to have easier to handle numbers

   fillarray(p,N,maxint); //look up

   evalstat(p,N,res); // again

   cout << "Mean = " << res[0] << endl;
   cout << "Variance = " << res[1] << endl;

   return 0;
}
