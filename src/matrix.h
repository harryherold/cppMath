#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>

template <class T> class Matrix
{

public:
  /**
   * TODO
   * copy constructor
   * overload operator =
   * static Matrix<T> diag( std::vector<T> , unsigned int);
   * Matirx( std::vector<T> , unsigned int, unsigned int);
   */
  Matrix(unsigned int, unsigned int);
  ~Matrix();

  static Matrix<T> eye( unsigned int);
  T& operator()(unsigned int, unsigned int);

  friend std::ostream& operator<<(std::ostream &out, Matrix<T> &m)
  {
    for( auto i = 0 ; i < m.getHeight() ; i++ )
    {
      for( auto j = 0 ; j < m.getWidth() ; j++ )
      {
        out << " " << m(i,j) << " ";
      }
      out << "\n";
    }
    return out;
  }

  void print( void );

  unsigned int getWidth( void );
  unsigned int getHeight( void );

private:
	unsigned int m_width;
	unsigned int m_height;
  std::vector< std::vector<T> > m_data;
};

template<class T> Matrix<T>::Matrix(unsigned int w, unsigned int h)
:m_width(w),m_height(h),m_data(h,std::vector<T>(w))
{}

template<class T> Matrix<T>::~Matrix()
{}

template<class T> unsigned int Matrix<T>::getHeight( void )
{
  return m_data.size();
}

template<class T> unsigned int Matrix<T>::getWidth( void )
{
  return m_data[0].size();
}

template<class T> T& Matrix<T>::operator()(unsigned int h,unsigned int w)
{
	return m_data[h][w];
}

template<class T> Matrix<T> Matrix<T>::eye( unsigned int size )
{
  Matrix<T> m( size , size );

  for( auto i = 0 ; i < size ; i++)
    m( i, i ) = static_cast<T>( 1 );

  return m;
}

#endif // MATRIX_H
