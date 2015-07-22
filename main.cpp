#include <QCoreApplication>

#include <QDir>
#include <QFileInfo>
#include <qDebug>

void RenameHead(const QString &strSrc, const QString &strDst)
{

    QDir currentDir;
//    QString strPath = QDir::currentPath();

    if (currentDir.exists())
    {
        QStringList listNames = currentDir.entryList(QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
        foreach (const QString &originName, listNames)
        {
            if(originName.startsWith(strSrc))
            {
                QString strNewName = strDst + originName.mid(strSrc.length());
                qDebug() << "rename from:"
                         << originName
                         << "to:"
                         << strNewName;

                QFile::rename(originName, strNewName);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString strSrc = "lht_";
    QString strDst = "hyc_";
    if(argc == 3)
    {
        strSrc = argv[1];
        strDst = argv[2];
    }

    RenameHead(strSrc, strDst);



    return 0;
}
