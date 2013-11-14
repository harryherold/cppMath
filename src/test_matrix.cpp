#include <matrix.h>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/UtestMacros.h>

TEST_GROUP(Matrix)
{
};

TEST(Matrix, Construction)
{
  Matrix<int> iMatrix(20,10);
  LONGS_EQUAL( iMatrix.getHeight(), 10 );
  LONGS_EQUAL( iMatrix.getWidth() , 20 );
}

TEST(Matrix, Fill)
{
  Matrix<int> iMatrix(10,10);

  for( auto i = 0 ; i < 10 ; i++ )
    for( auto j = 0 ; j < 10 ; j++ )
      iMatrix( i , j ) = 42;

  for( auto i = 0 ; i < 10 ; i++ )
    for( auto j = 0 ; j < 10 ; j++ )
      LONGS_EQUAL( iMatrix( i , j ) , 42 );
}

TEST(Matrix, Eye)
{
  Matrix<int> m = Matrix<int>::eye( 10 );

  for( auto i = 0 ; i < 10 ; i++ )
  {
    LONGS_EQUAL( m( i, i ) , 1 );
  }
}

int main(int argc, char **argv)
{
  return CommandLineTestRunner::RunAllTests(argc, argv);
}

