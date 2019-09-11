#ifndef CLEVELMANAGER_HPP
#define CLEVELMANAGER_HPP

#include <QColor>
#include <QList>

//! Level structure, for level infomation
struct Level
{
public:
	Level();

	static const int KNOWED_COLOR_CNT = 4;

	QString m_level_name;
	int m_level_size;
	QColor m_colors[ KNOWED_COLOR_CNT ];	// color of left-top, right-top, right-bottom, left-bottom
};

class CLevelManager
{
public:
	CLevelManager();

	Level getLevel( int index = 0) const;

private:
	QList<Level> m_level_list;
};

#endif // CLEVELMANAGER_HPP
