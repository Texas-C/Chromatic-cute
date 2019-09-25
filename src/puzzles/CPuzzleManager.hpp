/*! Puzzle manager for manage puzzle information.*/

#ifndef CLEVELMANAGER_HPP
#define CLEVELMANAGER_HPP

#include <QColor>
#include <QList>
#include "ColorVector.hpp"

struct PuzzleInfo
{
public:
	PuzzleInfo();

	static const int KNOWED_COLOR_CNT = 4;

    bool operator == ( const PuzzleInfo &other_puzzle);

	QString m_name;
    int m_level;
	int m_size;
	QColor m_colors[ KNOWED_COLOR_CNT ];	// color of left-top, right-top, right-bottom, left-bottom
};

class CPuzzleManager
{
public:
	CPuzzleManager();

	PuzzleInfo getPuzzle( int index = 0) const;
    int puzzleCount() const;

private:
	QList<PuzzleInfo> m_puzzle_list;
};

#endif // CLEVELMANAGER_HPP
