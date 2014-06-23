#include "matrix.h"
#include <algorithm>

using FunctionPtr = bool (*)(std::vector<double> & b,
						     Matrix<double>      & A,
						     std::vector<double> & x0,
			                 std::vector<double> & xk);

class LinAlg {

public:
    static std::vector<double> upperTriangle( Matrix<double> & A,
            std::vector<double> & b );

    static std::vector<double> lowerTriangle( Matrix<double> & A,
            std::vector<double> & b );

    static std::vector<double> computeJacobi( Matrix<double> & A,
            std::vector<double> & b,
            std::vector<double> &start,
            int n,
            FunctionPtr f );
            
    static std::vector<double> computeGaussSeidel( Matrix<double> & A,
            std::vector<double> & b,
            std::vector<double> &start,
            int n,
            FunctionPtr f );            
};

std::vector<double> LinAlg::lowerTriangle(
    Matrix<double> & A,
    std::vector<double> & b )
{
    std::vector<double> x( b.size() );
    x[0] = b[0] / A( 0, 0 );

    for(int i = 1 ; i < x.size() ; i++) {
        double sum = 0.0;
        for(int j = 0 ; j < x.size() ; j++) {
            sum += A(i,j) * x[j];
        }
        x[i] = (b[i] - sum) / A(i,i);
    }

    return x;
}

std::vector<double> LinAlg::upperTriangle(
    Matrix<double> & A,
    std::vector<double> & b )
{
    int n = b.size() - 1;
    std::vector<double> x( b.size() );
    x[n] = b[n] / A(n,n);
    for( int i = n - 1 ; i >= 0 ; i-- ) {
        double sum = 0.0;
        for(int j = i + 1 ; j < n + 1 ; j++) {
            sum += A(i,j) * x[j];
        }
        x[i] = (double) (b[i] - sum) / A(i,i);
    }
    return x;
}
std::vector<double> LinAlg::computeJacobi(
    Matrix<double> & A,
    std::vector<double> & b,
    std::vector<double> &start,
    int n,
    FunctionPtr f )
{
	std::vector<std::vector<double>> x(n + 1);
	
	for(auto & elem : x)
		elem = std::vector<double>(start.size());
	
	x[0] = start;
	
	for(int k = 0 ; k < n ; k++)
	{
		for(int i = 0 ; i < b.size() ; i++)
		{
			double sum = 0.0;
			for(int j = 0; j < b.size() ; j++)
			{
				if( j == i )
					continue;
				else
					sum += A(i,j) * x[k][j];
			}
			x[k+1][i] = (double) (b[i] - sum) / A(i,i);
		}
		
		std::cout << "Iteration number : " << k + 1 << "\n";
		
		if( f( b, A, start, x[k+1] ) )
			return x[k+1];
	}
	
	return x[n];
}
std::vector<double> LinAlg::computeGaussSeidel(
    Matrix<double> & A,
    std::vector<double> & b,
    std::vector<double> &start,
    int n,
    FunctionPtr f )
{
	std::vector<std::vector<double>> x(n + 1);
	
	for(auto & elem : x)
		elem = std::vector<double>(b.size(), 0.0 );
	
	x[0] = start;
	for(int k = 0 ; k < n ; k++)
	{
		for(int i = 0 ; i < b.size() ; i++)
		{
			double sum1 = 0.0;
			for( int j = 0 ; j < i ; j++ )
			{
				sum1 += A( i, j ) * x[k+1][j];
			}
			
			double sum2 = 0.0;
			for( int j = i + 1; j < n ; j++ )
			{
				sum2 += A( i, j ) * x[k][j];
			}
			//std::cout << "( " << b[i] << " - " << sum1 <<" - " << sum2 << ") / "<< A(i,i) << "\n";
			x[k+1][i] = (double) (b[i] - sum1 - sum2) / A( i, i );
		}
		std::cout << "Iteration " << k+1 << "\n";
		if( f( b, A, start, x[k+1] ) )
			return x[k+1];
		/*for(auto val : x[k+1] )
			std::cout << val << "\n";*/
	}
	return x[n];
}
std::vector<double> subVector( std::vector<double> a , std::vector<double> b )
{
	std::vector<double> x( b.size() );
	for( int i = 0 ; i < b.size() ; i++ )
	{
		x[i] = a[i] - b[i];
	}
	return x;
}

std::vector<double> multVector( std::vector<double> a, double b )
{
	std::vector<double> x( a.size() );
	for( int i = 0 ; i < a.size() ; i++ )
	{
		x[i] = a[i] * b;
	}
	return x;
}

double getNormTwo(std::vector<double> a)
{
	double sum = 0.0;
	std::for_each( a.begin(), a.end(), [&sum] (double & i) {sum += std::abs(i * i);} );
	return std::sqrt( sum );
}

bool checkCancelation(std::vector<double> & b,
				      Matrix<double>      & A,
					  std::vector<double> & x0,
			          std::vector<double> & xk)
{
	std::vector<double> tmp = A * xk;
	tmp = subVector( b, tmp );
	double xk_norm = getNormTwo( tmp );
	std::vector<double> epsvec = subVector( b, A *	x0 );
	double eps_norm = getNormTwo( epsvec ) * 0.001;
	if( xk_norm < eps_norm )
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	int n = 7;
	
	Matrix<double>      A( n );
	std::vector<double> b( n , 1.0 );
	std::vector<double> start( n , 0.0 );
	
	A(0,0) = 2.0;
	A(0,1) = -1.0;
	for(int i = 1 ; i < n - 1 ; i++)
	{
		A(i,i)   =    2.0;
		A(i,i-1) =   -1.0;
		A(i,i+1) =   -1.0;	
	}
	A( n-1 , n-1 ) =  2.0;
	A( n-1 , n-2 ) = -1.0;
	
	std::vector<double> x = LinAlg::computeJacobi( A, b, start, 100, &checkCancelation );
	
	for(auto val : x )
		std::cout << val << "\n";
	
	std::vector<double> xxx = LinAlg::computeGaussSeidel( A, b, start, 100, &checkCancelation );
	for(auto val : xxx )
		std::cout << val << "\n";
		
    return 0;
}


