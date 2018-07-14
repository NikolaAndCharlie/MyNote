#ifndef  _MAINWIDGET_
#define  _MAINWIDGET_
#include <QWidget>
#include <QObject>


class TextEdit;
class MainWidget:public QWidget
{
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
private:
    void setUi();
    void getText();
    TextEdit* m_mainPlainText;
public slots:
    void refreshText();
};







#endif
