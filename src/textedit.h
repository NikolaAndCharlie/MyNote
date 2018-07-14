#ifndef  _TEXTEDIT_
#define  _TEXTEDIT_
#include <QPlainTextEdit>
#include <QMouseEvent>
#include <QContextMenuEvent>


class TextEdit:public QPlainTextEdit
{
    Q_OBJECT
public:
    TextEdit();
    ~TextEdit();

protected:
  //  void mousePressEvent(QMouseEvent* e) override;
    void contextMenuEvent(QContextMenuEvent* e) override;
};






#endif
