#ifndef CLEVELMANAGER_HPP
#define CLEVELMANAGER_HPP

#include <QColor>
#include <QList>

//! Color vector
struct ColorVector
{
    ColorVector();
    ColorVector( int r, int g, int b);
    ColorVector(const QColor &color);
    QColor toQColor();

    ColorVector operator + ( const ColorVector &other);
    ColorVector operator - ( const ColorVector &other);
    ColorVector operator * ( const double &k);
    ColorVector operator / ( const double &k);

    int m_r;
    int m_g;
    int m_b;
};

//! Puzzle structure, for puzzle infomation
struct PuzzleInfo
{
public:
	PuzzleInfo();

	static const int KNOWED_COLOR_CNT = 4;

	QString m_name;
	int m_size;
	QColor m_colors[ KNOWED_COLOR_CNT ];	// color of left-top, right-top, right-bottom, left-bottom
};

class CPuzzleManager
{
public:
	CPuzzleManager();

	PuzzleInfo getPuzzle( int index = 0) const;

private:
	QList<PuzzleInfo> m_puzzle_list;
};

#endif // CLEVELMANAGER_HPP
