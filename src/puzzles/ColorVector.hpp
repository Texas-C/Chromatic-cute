#ifndef COLORVECTOR_H
#define COLORVECTOR_H

#include <QColor>

//! Color vector
struct ColorVector
{
    ColorVector();
    //ColorVector( int r, int g, int b);
    ColorVector( qreal r, qreal g, qreal b);
    ColorVector(const QColor &color);
    QColor toQColor();

    ColorVector operator + ( const ColorVector &other);
    ColorVector operator - ( const ColorVector &other);
    ColorVector operator * ( const double &k);
    ColorVector operator / ( const double &k);

    //int m_r;
    //int m_g;
    //int m_b;
    qreal m_r;
    qreal m_g;
    qreal m_b;
};

//! Puzzle structure, for puzzle infomation

#endif // COLORVECTOR_H
