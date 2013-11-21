#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <cstdint>

template < class T > class Matrix {

public:
  /**
   * TODO
   * validate matrix sizes in + and -
   * static Matrix<T> diag( std::vector<T> , unsigned int);
   * Matirx( std::vector<T> , unsigned int, unsigned int);
   */
  Matrix( uint32_t, uint32_t );
  Matrix( uint32_t );
  ~Matrix();

  uint32_t getWidth(void);
  uint32_t getHeight(void);
  std::vector < std::vector < T > > getData( void );

  void operator = ( Matrix< T > );

  Matrix< T > operator + ( Matrix< T > );
  Matrix< T > operator - ( Matrix< T > );
  Matrix< T > operator - ( void );

  T & operator()(uint32_t, uint32_t);

  void eye( void );

  friend std::ostream & operator<<(std::ostream & out, Matrix < T > &m)
  {
    for (auto i = 0; i < m.getHeight(); i++) {
      for (auto j = 0; j < m.getWidth(); j++) {
        out << " " << m(i, j) << " ";
      }
      out << "\n";
    }
    return out;
  }

private:
  uint32_t m_width;
  uint32_t m_height;
  std::vector < std::vector < T > >m_data;

  Matrix();
};

#include "matrix.cpp"

#endif // MATRIX_H
