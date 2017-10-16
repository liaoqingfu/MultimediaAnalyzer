#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "ffmpeg_player.h"
#include "video_widget.h"

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = 0);
    ~HomeWindow();
    FFmpegPlayer* player(){return &m_ffplayer;}
    void initConnection();
public slots:
    void slot_imageMV(QImage);
private slots:
    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionOpenInputUrl_triggered();

private:
    Ui::HomeWindow *ui;
    FFmpegPlayer m_ffplayer;
    QString file_url_;
};

#endif // HOMEWINDOW_H
