#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>

template < class T > class Matrix {

public:
  /**
   * TODO
   * static Matrix<T> diag( std::vector<T> , unsigned int);
   * Matirx( std::vector<T> , unsigned int, unsigned int);
   */
  Matrix( Matrix< T > & );
  Matrix(unsigned int, unsigned int);
  Matrix< T > & operator = ( Matrix< T > const & );
  ~Matrix();

  static Matrix < T > eye(unsigned int);

  T & operator()(unsigned int, unsigned int);
  friend std::ostream & operator<<(std::ostream&, Matrix < T >&);

  unsigned int getWidth(void);
  unsigned int getHeight(void);
  std::vector < std::vector < T > > getData( void );

private:
  unsigned int m_width;
  unsigned int m_height;
  std::vector < std::vector < T > >m_data;
};

#include "matrix.cpp"

#endif // MATRIX_H
