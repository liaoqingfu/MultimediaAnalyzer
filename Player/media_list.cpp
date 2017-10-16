#include "media_list.h"
#include<QTime>
//#include "myTablePlayListFinal.h"

MediaList::MediaList(QObject *parent) : QObject(parent)
{
    m_pFinal=NULL;
    m_musicIndex=0;
    m_list.empty();
    setPlayMode(PlayMode::playInOrder);
}

QUrl MediaList::mediaUrl(int index)
{
    if(m_list.isEmpty())
        return QUrl("");
    m_musicIndex=index;
    return m_list.value(index);
}
void MediaList::setPlayMode(PlayMode p)
{
    if(p==PlayMode::playInOrder)
        indexMode=0;
    if(p==PlayMode::playRandom)
        indexMode=1;
    if(p==PlayMode::playOneCircle)
        indexMode=2;
}
int MediaList::nextMediaIndex()//下一曲
{
    switch (indexMode) {
    case 0://playInOrder
        if(m_musicIndex+1>=m_list.count())//在最后一行了的话
            m_musicIndex=0;
        else
            m_musicIndex++;
        break;

    case 1://playRandom
        QTime time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int xxx=qrand()%m_list.count();
        m_musicIndex=xxx;
        break;
    }
    return m_musicIndex;
}

int MediaList::preMediaIndex()//上一曲
{
    switch (indexMode)
    {
    case 0://playInOrder
        if(m_musicIndex==0)//在第一行了的话
            m_musicIndex=0;
        else
            m_musicIndex--;
        break;

    case 1://playRandom
        QTime time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int xxx=qrand()%m_list.count();
        m_musicIndex=xxx;
        break;
    }
    return m_musicIndex;
}
void MediaList::slot_removeSong(int index)
{

    m_hashMap.remove(m_list.value(index));
    m_list.removeAt(index);
    /* int PlayWidindex=m_pFinal->m_table.m_playingWid.currentSongIndex();
    if(PlayWidindex>=index)
    {
        m_musicIndex--;
    }*/
}
