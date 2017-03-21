#pragma once
#include <QLabel>

class MLabel : public QLabel {
	Q_OBJECT

public:
	MLabel(QWidget * parent = Q_NULLPTR);
	MLabel(const QString &text, QWidget *parent = Q_NULLPTR, const QString &name = "SimSun");
	~MLabel();
	void			setFontSize(int fontsize);
private:
	QString			m_fontName;
};
