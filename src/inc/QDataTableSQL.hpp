#ifndef QDATATABLESQL_H
#define QDATATABLESQL_H

#pragma once

# include <QWidget>
# include <QFrame>
# include <QLabel>
# include <QResizeEvent>
# include <QMouseEvent>
# include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT QDataTableSQL : public QWidget
{
    Q_OBJECT

public:
    explicit QDataTableSQL(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint()        const override;
    
protected:
    void mousePressEvent(QMouseEvent  * event) override;
    void resizeEvent    (QResizeEvent * event) override;
    
private:
    inline uint8_t getControlWidth () const { return static_cast<uint8_t>(pix_w); }
    inline uint8_t getControlHeight() const { return static_cast<uint8_t>(pix_h); }
    
    static uint8_t pix_w;
    static uint8_t pix_h;
};

#endif
