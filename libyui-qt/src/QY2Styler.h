#ifndef QY2STYLER_H
#define QY2STYLER_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QImage>

class QY2Styler : public QObject
{
    Q_OBJECT

public:
    QY2Styler( QObject *parent );

    void setStyleSheet( const QString &file );
    QString themeDir() const;
    void registerWidget( QWidget *widget );

    static QY2Styler *self() {
        return _self;
    }

protected:
    void processUrls(QString &text);
    /*
     * Reimplemented from QObject.
     **/
    bool eventFilter( QObject * obj, QEvent * ev );

private:
    struct BackgrInfo {
	QString filename;
	QImage pix;
	bool full;
    };

    QHash<QString,BackgrInfo> _backgrounds;

    static QY2Styler *_self;
};

#endif
