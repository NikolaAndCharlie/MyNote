#include "textedit.h"
#include <QMenu>
#include <QAction>

TextEdit::TextEdit()
{
    
}

TextEdit::~TextEdit()
{
    
}

//
//void TextEdit::mousePressEvent(QMouseEvent* e)
//{
//  //  int b = 0;
//  //if (e->button() == Qt::RightButton)
//  //{
//  //    int a = -0;
//  //}
//}

void TextEdit::contextMenuEvent(QContextMenuEvent* e)
{
    QMenu* menu = createStandardContextMenu();
    menu->addSeparator();
    menu->addAction(tr("Color"));
    
    menu->exec(e->globalPos());
    delete menu;
}

