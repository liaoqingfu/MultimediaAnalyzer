#ifndef VIDEO_WIDGET_H
#define VIDEO_WIDGET_H


#include <QWidget>
#include"base_widget.h"
class VideoWidget : public BaseWidget
{
public:
    VideoWidget(QWidget*w=0);
    void setImage(QImage img);
public slots:
    void slot_imageMV(QImage);
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    QImage m_img;
};

#endif // VIDEO_WIDGET_H
