auto-style with `astyle`:

	astyle --style=ansi


Interface (pure virtual class):

	class IObject

Class:

	class CBox : public IObject

Member variable:

	int m_index;
	float m_value;

Member function:

	void output();
	void setValue( const int value);	
	int getValue() const;

Qt Features:

signals:

	void signal_triggered();

slots:

	void slot_clicked();
