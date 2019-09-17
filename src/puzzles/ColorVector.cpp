#include "ColorVector.hpp"

#define NUM2COLOR(value) (value < 0? 0 : (value > 255? 255 : value))

//---------- ColorVector
ColorVector::ColorVector() : m_r(0), m_g(0), m_b(0)
{}

ColorVector::ColorVector( int r, int g, int b) : m_r(r), m_g(g), m_b(b)
{}

ColorVector::ColorVector(const QColor &color)
{
    m_r = color.red();
    m_g = color.green();
    m_b = color.blue();
}

QColor ColorVector::toQColor()
{	return QColor( NUM2COLOR(m_r), NUM2COLOR(m_g), NUM2COLOR(m_b));	}

ColorVector ColorVector::operator + (const ColorVector &other)
{	return ColorVector( m_r + other.m_r, m_g + other.m_g, m_b + other.m_b);}

ColorVector ColorVector::operator - (const ColorVector &other)
{	return ColorVector( m_r - other.m_r, m_g - other.m_g, m_b - other.m_b);}

ColorVector ColorVector::operator * ( const double &k)
{	return ColorVector( m_r * k, m_g * k,  m_b * k);	}

ColorVector ColorVector::operator / ( const double &k)
{	return ColorVector( m_r / k, m_g / k,  m_b / k);	}
