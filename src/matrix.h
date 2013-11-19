#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <cstdint>

template < class T > class Matrix {

public:
  /**
   * TODO
   * static Matrix<T> diag( std::vector<T> , unsigned int);
   * Matirx( std::vector<T> , unsigned int, unsigned int);
   */
  Matrix( Matrix< T > & );
  Matrix(uint32_t, uint32_t);
  Matrix(uint32_t);
  Matrix< T > & operator = ( Matrix< T > & );
  ~Matrix();

  void eye( void );

  T & operator()(uint32_t, uint32_t);
  friend std::ostream & operator<<(std::ostream&, Matrix < T >&);

  uint32_t getWidth(void);
  uint32_t getHeight(void);
  std::vector < std::vector < T > > getData( void );

private:
  uint32_t m_width;
  uint32_t m_height;
  std::vector < std::vector < T > >m_data;

  Matrix();
};

#include "matrix.cpp"

#endif // MATRIX_H
