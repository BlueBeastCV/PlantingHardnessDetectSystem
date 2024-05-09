#ifndef DATAOPER_H
#define DATAOPER_H

#include <QObject>
#include <vector>
#include "objectinfo.h"
#include <QSqlDatabase>
#include <QtSql>
#include "myhelper.h"
using namespace std;


/**
 * @brief The DataOper class
 * 数据处理类   主要操作数据库。
 */
class DataOper : public QObject
{
        Q_OBJECT
    public:
        explicit DataOper(QObject *parent = nullptr);
        bool releaseDBspace();
        QString getUUID();
        bool isInteger(const QVariant& variant);
        bool isString(const QVariant& variant);
        int deleteTableData(QString oldTable, QMap<QString, QVariant> fieldMap);




        int saveProData(Pro &pro);
        int updateProData(Pro pro);
        int deleteProDataByCode(QString code);
        int getProCodeList(QStringList &codeList);
        int getProInfoByCode(Pro &pro, QString code);
        int saveHoleDiameter(HoleDiameter& holeDiameter);
        int deleteHoleDiameterByCode(QString code);
        int saveSphereDiameter(SphereDiameter& sphereDiameter);
        int deleteSphereDiameterByCode(QString code);
        int saveHeapUp(HeapUp& heapUp);
        int deleteHeapUpByCode(QString code);
        int saveCover(Cover& cover);
        int deleteCoverByCode(QString code);
        int getSphereDiameterListByCode(QVector<SphereDiameter>& sphereDiameters, const QString code);
        int getHoleDiameterListByCode(QVector<HoleDiameter>& holeDiameters, const QString code);
        int getHeapUpListByCode(QVector<HeapUp>& heapUps, const QString code);
        int getCoverByCode(Cover& cover, const QString code);
        int saveMeasureProData(MeasurePro &Mpro);
        int deleteMeasureProDataByCode(QString code);

        int getCodeListByDate(QStringList& codeList, QString startTime, QString endTime);
        int saveHoleDiameterList(QVector<HoleDiameter>& holeDiameters);
        int saveSphereDiameterList(QVector<SphereDiameter>& sphereDiameters);
        int updateCoverData(Cover& cover);
        int saveHeapUpList(QVector<HeapUp>& heapUps);
        int getMeasureProData(MeasurePro& Mpro, const QString code);


        int getUserNameList(QStringList& userNameList);
        int queryAllUser(QVector<User>& users);
        int saveUsers(QVector<User> users);
        int deleteUser(QString name = nullptr);
        int getUserByName(User& user, QString name);
        int savePointInfo(PointInfo& p_info);
        int savePointList(QVector<PointList>& p_list);
        int saveHardnessList(QVector<hardnessList>& hardnessDataList);
        int getAutoHardnessListByID(QVector<hardnessList>& hadnessDataList, const QString id);
        int getHardnessListByID(QVector<hardnessList>& hadnessDataList, const QString id);
        int getPointCodeList(QStringList& pointCodeList);
        int getPointInfoByCode(PointInfo& p_info, QString code);
        int getPointListByCode(QVector<PointList>& p_list, QString code);
        int deletePointInfoByCode(QString code);
        int updatePointInfoBCode(PointInfo& p_info);
    signals:
        void sendDataMessage(const QString& info);

    private:
        QSqlDatabase db;
};

#endif // DATAOPER_H
