#include <matrix.h>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/UtestMacros.h>

TEST_GROUP(Matrix)
{
};

TEST(Matrix, Construction)
{
  Matrix < int >iMatrix(20, 10);
  LONGS_EQUAL(10,iMatrix.getHeight());
  LONGS_EQUAL(20,iMatrix.getWidth());
}

TEST(Matrix, Fill)
{
  Matrix < int >iMatrix(10, 10);

  for (auto i = 0; i < 10; i++)
    for (auto j = 0; j < 10; j++)
      iMatrix(i, j) = 42;

  for (auto i = 0; i < 10; i++)
    for (auto j = 0; j < 10; j++)
      LONGS_EQUAL(42,iMatrix(i, j));
}

TEST(Matrix, Eye)
{
  Matrix < int > m ( 10 );
  m.eye();
  for (auto i = 0; i < 10; i++) {
    LONGS_EQUAL(1,m(i, i));
  }
}

TEST(Matrix, Add)
{
  Matrix < int > m1 ( 10 );
  Matrix < int > m2 ( 10 );
  Matrix < int > m3 ( 10 );

  for (auto i = 0; i < 10; i++)
  {
    for (auto j = 0; j < 10; j++)
    {
      m1(i, j) = 42;
      m2(i, j) = 42;
    }
  }
  m3 = m2 + m1;

  for (auto i = 0; i < 10; i++)
    for (auto j = 0; j < 10; j++)
      LONGS_EQUAL(84,m3(i, j));
}

TEST(Matrix, Sub)
{
  Matrix < int > m1 ( 10 );
  Matrix < int > m2 ( 10 );
  Matrix < int > m3 ( 10 );

  for (auto i = 0; i < 10; i++)
  {
    for (auto j = 0; j < 10; j++)
    {
      m1(i, j) = 42;
      m2(i, j) = 21;
    }
  }
  m3 = m1 - m2;
  for (auto i = 0; i < 10; i++)
    for (auto j = 0; j < 10; j++)
      LONGS_EQUAL(21,m3(i, j));
}
int
main(int argc, char **argv)
{
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
