#include <QFileDialog>
#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    file_url_ = "G:\ffmpeg\ffmpeg-leiyuehua\qt\MultimediaAnalyzer\cuc_ieschool.flv";
    file_url_.replace("/","\\");
    ui->setupUi(this);
    initConnection();
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::initConnection()
{
    connect(&m_ffplayer,SIGNAL(sig_CurImageChange(QImage)),this,SLOT(slot_imageMV(QImage)));
}

void HomeWindow::on_actionPlay_triggered()
{
    m_ffplayer.setMedia(file_url_,true);
    m_ffplayer.play();
}

void HomeWindow::on_actionStop_triggered()
{
    m_ffplayer.stop();
}

void HomeWindow::slot_imageMV(QImage img)
{
    ui->widgetVideo->setImage(img);
}


void HomeWindow::on_actionOpenInputUrl_triggered()
{
    file_url_ = QFileDialog::getOpenFileName(
               this, "选择要播放的文件",
                "/",//初始目录
                "视频文件 (*.flv *.rmvb *.avi *.MP4);; 所有文件 (*.*);; ");
    if (!file_url_.isEmpty())
    {
        file_url_.replace("/","\\");
    }
}
