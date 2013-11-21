#include <matrix.h>

template < class T > Matrix < T >::Matrix()
{}

template < class T > Matrix < T >::Matrix(uint32_t val)
:m_width(val),
m_height(val),
m_data(val, std::vector < T > (val))
{
}

template < class T > Matrix < T >::Matrix(uint32_t w, uint32_t h)
:m_width(w),
m_height(h),
m_data(h, std::vector < T > (w))
{
}

template < class T > Matrix < T >::~Matrix()
{
}

template < class T > uint32_t Matrix < T >::getHeight(void)
{
  return m_data.size();
}

template < class T > uint32_t Matrix < T >::getWidth(void)
{
  return m_data[0].size();
}

template < class T > std::vector < std::vector < T > > Matrix < T >::getData( void )
{
  return m_data;
}

template < class T > void Matrix < T >::operator = ( Matrix< T > m )
{
  m_height = m.getHeight();
  m_width  = m.getWidth();
  m_data   = m.getData();
}

template < class T > Matrix< T > Matrix < T >::operator + ( Matrix< T > obj )
{
  Matrix < T > m( m_width , m_height );

  for( auto i = 0; i < m_height ; i++ )
  {
    for( auto j = 0 ; j < m_width ; j++ )
    {
        m( i , j ) = (*this)(i,j) + obj( i , j );
    }
  }
  return m;
}

template < class T > Matrix< T > Matrix < T >::operator - ( void )
{
  Matrix < T > m( m_width , m_height );

  for( auto i = 0; i < m_height ; i++ )
  {
    for( auto j = 0 ; j < m_width ; j++ )
    {
      m( i , j ) = -(*this)(i,j);
    }
  }

  return m;
}

template < class T > Matrix< T > Matrix < T >::operator - ( Matrix < T > obj )
{
  Matrix < T > m( obj.m_width , obj.m_height );

  m = (*this) + ( - obj );

  return m;
}

template < class T > T & Matrix < T >::operator()(uint32_t h, uint32_t w)
{
  return m_data[h][w];
}

template < class T > void Matrix < T >::eye( void )
{
  for (auto i = 0; i <  m_data.size() ; i++)
    m_data[i][i] = static_cast < T > (1);
}
