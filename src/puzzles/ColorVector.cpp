#include "ColorVector.hpp"

#define NUM2COLOR(value) (value < 0? 0 : (value > 255? 255 : value))
#define NUM2COLORF(value) (value < 0? 0 : (value > 1.0? 1.0: value))

//---------- ColorVector
ColorVector::ColorVector() : m_r(0), m_g(0), m_b(0)
{}

ColorVector::ColorVector( qreal r, qreal g, qreal b) : m_r(r), m_g(g), m_b(b)
{}

ColorVector::ColorVector(const QColor &color)
{
    color.getRgbF( &m_r, &m_g, &m_b);
}

QColor ColorVector::toQColor()
{
    QColor color;
    color.setRgbF( NUM2COLORF(m_r), NUM2COLORF(m_g), NUM2COLORF(m_b));
    return color;
}

ColorVector ColorVector::operator + (const ColorVector &other)
{	return ColorVector( m_r + other.m_r, m_g + other.m_g, m_b + other.m_b);}

ColorVector ColorVector::operator - (const ColorVector &other)
{	return ColorVector( m_r - other.m_r, m_g - other.m_g, m_b - other.m_b);}

ColorVector ColorVector::operator * ( const double &k)
{	return ColorVector( m_r * k, m_g * k,  m_b * k);	}

ColorVector ColorVector::operator / ( const double &k)
{	return ColorVector( m_r / k, m_g / k,  m_b / k);	}
