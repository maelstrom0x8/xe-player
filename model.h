#ifndef MODEL_H
#define MODEL_H

#include <taglib/fileref.h>
#include <taglib/taglib.h>
#include <QObject>
#include <QAbstractListModel>



namespace  Xe{

enum Roles {
    TitleRole = Qt::UserRole,
    AlbumRole, ArtistRole, GenreRole, FileRole
};

class AudioItem {

public:
    explicit AudioItem(QString &src);
    ~AudioItem();
    //AudioItem(const AudioItem&){}

    QString album() const;
    QString artist() const;
    QString filename() const;
    QString title() const;

private:
    TagLib::FileRef *ref;
    QString source;

};


class PlaylistModel : public QAbstractListModel {
    Q_OBJECT
public:
    PlaylistModel(QList<AudioItem> &_audioItems, QAbstractListModel *parent=nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent) const override;
private:
    QList<AudioItem> audioItems;
};







}   // end namespace Xe



#endif // MODEL_H
