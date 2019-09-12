#include "CLevelManager.hpp"
#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//---------- CLevel
Level::Level() : m_level_name("Unknow"), m_level_size(3)
{
	for(int i = 0; i < Level::KNOWED_COLOR_CNT; ++i)
		m_colors[i] = Qt::white;
}

//---------- CLevelManager --- functions
QByteArray read_json_from_file( const QString &filename)
{
	QFile file(filename);

	if( !file.open( QIODevice::ReadOnly ))
	{
		qDebug() << "Read" << filename << "failed";
		return QByteArray();
	}

	QByteArray buff = file.readAll();
	file.close();
	return buff;
}

// QString to QColor
QColor qstr2qcolor( QString str)
{
	QByteArray buf = str.toUtf8();
	if( buf.size() )
	{
		int r, g, b;
		sscanf(buf.data(), "#%2x%2x%2x", &r, &g, &b);
		return QColor(r, g, b);
	}
	return Qt::white;	// return white as default
}

bool init_levels_from_json( QList<Level> &level_list, const QJsonDocument &json_colors, const QJsonDocument &json_levels)
{
	if( (!json_colors.isObject()) || (!json_levels.isArray()) )
		return false;

	QJsonObject	json_color_container;

	QJsonArray	json_level_array;
	QJsonArray::iterator it;

	json_color_container	= json_colors.object();
	json_level_array		= json_levels.array();

	// load level infomation to level list
	for(it = json_level_array.begin(); it != json_level_array.end(); ++it)
	{
		Level		tmp_level;
		QJsonObject	tmp_object	= it->toObject();

		tmp_level.m_level_name = tmp_object.value("levelName").toString();
		tmp_level.m_level_size = tmp_object.value("size").toInt();

		QJsonArray	tmp_array	= json_color_container.find( tmp_level.m_level_name)->toArray();

		for(int i = 0; i < tmp_array.size(); ++i)
			tmp_level.m_colors[i] = qstr2qcolor( tmp_array[i].toString() );

		level_list.push_back( tmp_level );
	}

	return true;
}

//---------- CLevelManager --- member methods
CLevelManager::CLevelManager()
{
	// load level list from color.jsons and levels.json
	QByteArray array_colors = read_json_from_file( ":/res/levels/colors.json");
	QByteArray array_levels = read_json_from_file( ":/res/levels/levels.json");

	QJsonDocument json_colors = QJsonDocument::fromJson( array_colors);
	QJsonDocument json_levels = QJsonDocument::fromJson( array_levels);

	init_levels_from_json( m_level_list, json_colors, json_levels);
}

// get level by index
Level CLevelManager::getLevel(int index) const
{
	if( index >= 0 && index < m_level_list.size())
		return m_level_list[index];
	else
	{
		qDebug() << "invalid level request";
		return Level();
	}
}
