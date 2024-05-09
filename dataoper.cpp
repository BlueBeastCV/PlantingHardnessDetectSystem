#include "dataoper.h"

DataOper::DataOper(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::database(dataBase_alias);//连接数据库2
}


//释放数据库删除文件占用的空间。清空表数据，并不会改变db文件大小。索要要执行次命令
bool DataOper::releaseDBspace()
{
    QSqlQuery query(db);
    query.prepare("VACUUM");
    if (query.exec()) {
        qDebug() <<  "releaseDBspace success.";
        return true;
    }else{
        return false;
        qDebug() <<  "Can't compress database.";
    }
}
//生成UUID
QString DataOper::getUUID()
{
    QUuid id = QUuid::createUuid();
    QString strID = id.toString();
    strID.remove("{").remove("}").remove("-");
    return strID;
}
//快速删除大量数据  fieldMap 需要删除的数据
int DataOper::deleteTableData(QString oldTable, QMap<QString, QVariant> fieldMap)
{
    QSqlQuery query(db);
    db.transaction();
    //创建临时表存储不需要删除的数据
    QString sql = QString("CREATE TABLE %1temp AS SELECT * FROM %2 where  1=1 ").arg(oldTable).arg(oldTable);
    QMap<QString, QVariant>::const_iterator it = fieldMap.constBegin();
    while (it != fieldMap.constEnd())
    {
         qDebug() << it.key() << ": " << it.value() << endl;
         if(isInteger(it.value())){//QVariant 是整数
             sql.append( QString("and %1 != %2 ").arg(it.key()).arg(it.value().toInt()) );
         }else{
             sql.append( QString("and %1 != '%2' ").arg(it.key()).arg(it.value().toString()) );
         }
         ++it;
    }
    if(query.exec(sql)){
        db.commit();
        //删除旧表
        sql = QString("DROP TABLE %1").arg(oldTable);
        if(query.exec(sql)){
            db.commit();
            //更改临时表到新表
            sql = QString("ALTER TABLE %1temp RENAME TO %2").arg(oldTable).arg(oldTable);
            if(query.exec(sql)){
                db.commit();
                return 0;
            }else{
                qDebug() << "更改临时表到新表 fail:" << query.lastError();
                return 2;
            }
        }else{
            qDebug() << "删除旧表 fail:" << query.lastError();
            return 2;
        }
    }else{
        qDebug() << "创建临时表存储不需要删除的数据 fail:" << query.lastError();
        return 2;
    }
}

//批量删除大量数据 delete 很慢，可以尝试以下方式
//-- 复制表结构并复制需要保留数据
//CREATE TABLE logE AS SELECT * FROM log where name = 'admin';
//-- 删除旧表
//DROP TABLE log;
//-- 重命名
//ALTER TABLE logE RENAME TO log

//判断QVariant 是否是整型
bool DataOper::isInteger(const QVariant &variant)
{
    switch (variant.userType())
    {
        case QMetaType::Int:
        case QMetaType::UInt:
        case QMetaType::LongLong:
        case QMetaType::ULongLong:
        return true;
    }
    return false;
}
//判断QVariant 是否是字符串
bool DataOper::isString(const QVariant &variant)
{
    return variant.userType() == QMetaType::QString;
}


//获取用户列表
int DataOper::getUserNameList(QStringList &userNameList)
{
    QSqlQuery query(db);
    QString sql  = QString("select name from user");

    if(query.exec(sql)){
        while(query.next()){
            userNameList.append(query.value("name").toString());
        }
        return 0;
    }else{
        qDebug() << "getUserNameList fail: " + query.lastError().text();
        return 2;
    }
}
//查询所有用户
int DataOper::queryAllUser(QVector<User>& users)
{
    User  user;
    QSqlQuery q(db);
    QString sql = "select name,pwd,role,is_used from user ";

    if(q.exec(sql)){
        while(q.next()){
            user.name = q.value("name").toString();
            user.pwd = q.value("pwd").toString();
            user.role = q.value("role").toString();
            user.is_used = q.value("is_used").toString();
            users.push_back(user);
        }
        return 0;
    }else{
        qDebug() << "queryAllUser fail: " + q.lastError().text();
        return 2;
    }
}
//保存用户
int DataOper::saveUsers(QVector<User> users)
{
    //删除现有的全部用户
    deleteUser();
    QSqlQuery q(db);
    q.prepare("insert into user values (?, ?, ?, ?)");
    QVariantList names;
    QVariantList pwds;
    QVariantList roles;
    QVariantList is_useds;
    for(int i = 0; i < users.size(); i++){
        names << users[i].name;
        pwds << users[i].pwd;
        roles << users[i].role;
        is_useds << users[i].is_used;
    }
    q.addBindValue(names);
    q.addBindValue(pwds);
    q.addBindValue(roles);
    q.addBindValue(is_useds);
    if (q.execBatch()){
        return 0;
    }else{
        qDebug() << "saveUsers fail: " + q.lastError().text();
        return 2;
    }
}
//删除用户
int DataOper::deleteUser(QString name)
{
    QSqlQuery q(db);
    QString sql = nullptr;
    if(name == nullptr){
        sql = QString("delete from user");
    }else{
        sql = QString("delete from user where name = '%1'").arg(name);
    }
    if(q.exec(sql)){
        return 0;
    }else{
        qDebug() << "deleteUserByName fail: " + q.lastError().text();
        return 2;
    }
}
//根据名字获取用户信息
int DataOper::getUserByName(User &user, QString name)
{
    QSqlQuery query(db);
    QString sql  = QString("select name, pwd, role, is_used from user where name = '%1'").arg(name);

    if(query.exec(sql)){
        if(query.next()){
            user.name = query.value("name").toString();
            user.pwd = query.value("pwd").toString();
            user.role = query.value("role").toString();
            user.is_used = query.value("is_used").toString();
            return 0;
        }else{
            return 1;
        }
    }else{
        qDebug() << "getUserByName fail: " + query.lastError().text();
        return 2;
    }
}


//获取点位编号列表
int DataOper::getPointCodeList(QStringList &pointCodeList)
{
    QSqlQuery query(db);
    QString sql  = QString("SELECT DISTINCT plateType FROM pointInfo ORDER BY CASE plateType WHEN '类型1' THEN 1 WHEN '类型2' THEN 2 WHEN '类型3' THEN 3 WHEN '类型4' THEN 4 WHEN '类型5' THEN 5 WHEN '类型6' THEN 6"
                           " WHEN '类型7' THEN 7 WHEN '类型8' THEN 8 WHEN '类型9' THEN 9 WHEN '类型10' THEN 10 WHEN '类型11' THEN 11 WHEN '类型12' THEN 12"
                           " WHEN '类型13' THEN 13 WHEN '类型14' THEN 14 WHEN '类型15' THEN 15 WHEN '类型16' THEN 16 ELSE 17 END");

    if(query.exec(sql)){
        while(query.next()){
            pointCodeList.append(query.value("plateType").toString());
        }
        return 0;
    }else{
        qDebug() << "getPointCodeList fail: " + query.lastError().text();
        return 2;
    }
}
//保存点位信息
int DataOper::savePointInfo(PointInfo &p_info)
{
    QSqlQuery query(db);
    query.prepare("insert into pointInfo(plateType, pointCode, length, width, thick, D_thick_std, U_thick_std)values (?,?,?,?,?,?,?)");
    query.addBindValue(p_info.plateType);
    query.addBindValue(p_info.pointCode);
    query.addBindValue(p_info.length);
    query.addBindValue(p_info.width);
    query.addBindValue(p_info.thick);
    query.addBindValue(p_info.D_thick_std);
    query.addBindValue(p_info.U_thick_std);

    if (query.exec()){
        return 0;
    }else{
        qDebug() << "savePointInfo fail: " + query.lastError().text();
        return 2;
    }
}
//保存点位列表
int DataOper::savePointList(QVector<PointList> &p_list)
{
    QSqlQuery q(db);
    db.transaction();
    q.prepare("insert into pointList(plateType, xVal, yVal) values (?,?,?)");
//    QVariantList pointCodes;
//    QVariantList xVals;
//    QVariantList yVals;
    for(int i = 0; i < p_list.size(); i++){
//        pointCodes << p_list[i].pointCode;
//        xVals << p_list[i].xVal;
//        yVals << p_list[i].yVal;
        q.bindValue(0,p_list[i].plateType);
        q.bindValue(1,p_list[i].xVal);
        q.bindValue(2,p_list[i].yVal);
        if (!q.exec()) {
            qDebug() << "Failed to insert data for point at index" << i;
            qDebug() << q.lastError().text();
            db.rollback(); // 出现错误，回滚事务
            return 2;
        }
    }
    db.commit();
    return 0;
//    q.addBindValue(pointCodes);
//    q.addBindValue(xVals);
//    q.addBindValue(yVals);
//    if (q.execBatch()){
//        db.commit();
//        return 0;
//    }else{
//        qDebug() << "savePointList fail: " + q.lastError().text();
//        return 2;
//    }
}

int DataOper::saveHardnessList(QVector<hardnessList>& hardnessDataList)
{
    QSqlQuery q(db);
    db.transaction();
    q.prepare("insert into hardnessList(plateType,pointCode,xCoordinate,yCoordinate,hardness,diameter,result,time,operator) values (?,?,?,?,?,?,?,?,?)");
    QVariantList plateTypes;
    QVariantList ids;
    QVariantList xCoordinates;
    QVariantList yCoordinates;
    QVariantList hardnesses;
    QVariantList diameters;
    QVariantList results;
    QVariantList times;
    QVariantList opers;

    for(int i = 0; i < hardnessDataList.size(); i++){
        plateTypes << hardnessDataList[i].plateType;
        ids << hardnessDataList[i].id;
        xCoordinates << hardnessDataList[i].xCoordinate;
        yCoordinates << hardnessDataList[i].yCoordinate;
        hardnesses << hardnessDataList[i].hardness;
        diameters << hardnessDataList[i].diameter;
        results << hardnessDataList[i].result;
        times << hardnessDataList[i].time;
        opers << hardnessDataList[i].oper;

    }
    q.addBindValue(plateTypes);
    q.addBindValue(ids);
    q.addBindValue(xCoordinates);
    q.addBindValue(yCoordinates);
    q.addBindValue(hardnesses);
    q.addBindValue(diameters);
    q.addBindValue(results);
    q.addBindValue(times);
    q.addBindValue(opers);

    if (q.execBatch()){
        db.commit();
        return 0;
    }else{
        qDebug() << "saveHardnessList fail: " + q.lastError().text();
        return 2;
    }
}

int DataOper::getAutoHardnessListByID(QVector<hardnessList> &hadnessDataList, const QString id)
{
    QSqlQuery query(db);
    QString sql  = QString("select hardness from hardnessList where id='%1'").arg(id);
    if(query.exec(sql)){
        while(query.next()){
            hardnessList hardnesses;
            hardnesses.hardness = query.value("hardness").toDouble();
            hadnessDataList.push_back(hardnesses);
        }
        return 0;
    }else{
        qDebug() << "getAutoHardnessListByID fail:" + query.lastError().text();
        return 2;
    }
}

int DataOper::getHardnessListByID(QVector<hardnessList> &hadnessDataList, const QString id)
{
    QSqlQuery query(db);
    QString sql  = QString("select plateType, pointCode, xCoordinate, yCoordinate, hardness, diameter, result, time, operator from hardnessList where plateType='%1' ")
            .arg(id);
    if(query.exec(sql)){
        while(query.next()){
            hardnessList hardnesses;
            hardnesses.plateType = query.value("plateType").toString();
            hardnesses.id = query.value("pointCode").toString();
            hardnesses.xCoordinate = query.value("xCoordinate").toInt();
            hardnesses.yCoordinate = query.value("yCoordinate").toInt();
            hardnesses.hardness = query.value("hardness").toInt();
            hardnesses.diameter = query.value("diameter").toDouble();
            hardnesses.time = query.value("time").toString();
            hardnesses.oper = query.value("operator").toString();
            hardnesses.result = query.value("result").toString();
            hadnessDataList.push_back(hardnesses);
        }
        return 0;
    }else{
        qDebug() << "getHardnessListByID fail:" + query.lastError().text();
        return 2;
    }
}

//根据类型 获取点位信息
int DataOper::getPointInfoByCode(PointInfo &p_info, QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select plateType, pointCode, length, width, thick, D_thick_std, U_thick_std "
                           "from pointInfo where plateType = '%1'").arg(code);
    if(query.exec(sql)){
        if(query.next()){
            p_info.plateType = query.value("plateType").toString();
            p_info.pointCode = query.value("pointCode").toString();
            p_info.length = query.value("length").toDouble();
            p_info.width = query.value("width").toDouble();
            p_info.thick = query.value("thick").toDouble();
            p_info.D_thick_std = query.value("D_thick_std").toDouble();
            p_info.U_thick_std = query.value("U_thick_std").toDouble();
        }
        return 0;
    }else{
        qDebug() << "getPointInfoByCode fail: " + query.lastError().text();
        return 2;
    }
}
//根据点位编号 获取点位列表信息
int DataOper::getPointListByCode(QVector<PointList> &p_list, QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select plateType, xVal, yVal from pointList where plateType = '%1'").arg(code);
    if(query.exec(sql)){
        while(query.next()){
            PointList p;
            p.plateType = query.value("plateType").toString();
            p.xVal = query.value("xVal").toDouble();
            p.yVal = query.value("yVal").toDouble();
            p_list.push_back(p);
        }
        return 0;
    }else{
        qDebug() << "getPointListByCode fail:" + query.lastError().text();
        return 2;
    }
}


//更新点位信息
int DataOper::updatePointInfoBCode(PointInfo &p_info)
{
    int res = deletePointInfoByCode(p_info.plateType);
    if(res == 0){
        return savePointInfo(p_info);

    }else{
        return 1;
    }
}
//删除点位信息
int DataOper::deletePointInfoByCode(QString code)
{
    QSqlQuery q(db);
    QString sql1 = QString("delete from pointInfo where plateType = '%1'").arg(code);
    QString sql2 = QString("delete from pointList where plateType = '%1'").arg(code);
    if(q.exec(sql1)){
        if(q.exec(sql2)){
            releaseDBspace();
            return 0;
        }else{
            qDebug() << "deletePointInfoByCode pointList fail: " + q.lastError().text();
            return 3;
        }
    }else{
        qDebug() << "deletePointInfoByCode pointInfo fail: " + q.lastError().text();
        return 2;
    }
}


























//保存板片定义
int DataOper::saveProData(Pro &pro)
{
    QSqlQuery query(db);
    query.prepare("insert into pro(code, materials, length, width, "
                  "holeDiameterStd, sphereDiameterStd, xHoleCount, yHoleCount) "
                  "values (?,?,?,?,?,?,?,?)");
    query.addBindValue(pro.code);
    query.addBindValue(pro.materials);
    query.addBindValue(pro.length);
    query.addBindValue(pro.width);
    query.addBindValue(pro.holeDiameterStd);
    query.addBindValue(pro.sphereDiameterStd);
    query.addBindValue(pro.xHoleCount);
    query.addBindValue(pro.yHoleCount);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "saveProData fail: " + query.lastError().text();
        return 2;
    }
}
//根据编号更新板片数据
int DataOper::updateProData(Pro pro)
{
    QSqlQuery query(db);
    QString sql = QString("update pro set materials=?, length=?, width=?, holeDiameterStd=?, "
                          "sphereDiameterStd=?,xHoleCount=?,yHoleCount=? where code = '%1'")
                  .arg(pro.code);
    query.prepare(sql);
    query.addBindValue(pro.materials);
    query.addBindValue(pro.length);
    query.addBindValue(pro.width);
    query.addBindValue(pro.holeDiameterStd);
    query.addBindValue(pro.sphereDiameterStd);
    query.addBindValue(pro.xHoleCount);
    query.addBindValue(pro.yHoleCount);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "updateProData fail: " + query.lastError().text();
        return 2;
    }

}
//根据编号删除板片数据
int DataOper::deleteProDataByCode(QString code)
{
    QSqlQuery q(db);
    QString sql = QString("delete from pro where code = '%1'").arg(code);
    if(q.exec(sql)){
        releaseDBspace();
        return 0;
    }else{
        qDebug() << "deleteProData fail: " + q.lastError().text();
        return 2;
    }
}
//获取板片定义列表
int DataOper::getProCodeList(QStringList &codeList)
{
    QSqlQuery query(db);
    QString sql  = QString("select code from pro");
    if(query.exec(sql)){
        while(query.next()){
            codeList.append(query.value("code").toString());
        }
        return 0;
    }else{
        qDebug() << "getProCodeList fail: " + query.lastError().text();
        return 2;
    }
}
//根据编号获取板片信息
int DataOper::getProInfoByCode(Pro &pro, QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select code, materials, length, width, holeDiameterStd, "
                           "sphereDiameterStd, xHoleCount, yHoleCount "
                           "from pro where code = '%1'").arg(code);
    if(query.exec(sql)){
        if(query.next()){
            pro.code = query.value("code").toString();
            pro.materials = query.value("materials").toString();
            pro.length = query.value("length").toDouble();
            pro.width = query.value("width").toDouble();
            pro.holeDiameterStd = query.value("holeDiameterStd").toDouble();
            pro.sphereDiameterStd = query.value("sphereDiameterStd").toDouble();
            pro.xHoleCount = query.value("xHoleCount").toInt();
            pro.yHoleCount = query.value("yHoleCount").toInt();
            return 0;
        }
    }else{
        qDebug() << "getProInfoByCode fail: " + query.lastError().text();
        return 2;
    }
}



//保存孔径信息
int DataOper::saveHoleDiameter(HoleDiameter &holeDiameter)
{
    //首先删除已有的数据
    deleteHoleDiameterByCode(holeDiameter.code);
    QSqlQuery query(db);
    query.prepare("insert into holeDiameter(code, x, y, holeDiameterVal) values (?,?,?,?)");
    query.addBindValue(holeDiameter.code);
    query.addBindValue(holeDiameter.x);
    query.addBindValue(holeDiameter.y);
    query.addBindValue(holeDiameter.holeDiameterVal);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "saveHoleDiameter fail: " + query.lastError().text();
        return 2;
    }
}
int DataOper::saveHoleDiameterList(QVector<HoleDiameter>& holeDiameters)
{
    if(holeDiameters.size() != 0){
        deleteHoleDiameterByCode(holeDiameters[0].code);
    }

    QSqlQuery q(db);
    db.transaction();
    q.prepare("insert into holeDiameter(code, x, y, holeDiameterVal) values (?,?,?,?)");
    QVariantList codes;
    QVariantList xs;
    QVariantList ys;
    QVariantList values;
    for(int i = 0; i < holeDiameters.size(); i++){
        codes << holeDiameters[i].code;
        xs << holeDiameters[i].x;
        ys << holeDiameters[i].y;
        values << holeDiameters[i].holeDiameterVal;
    }
    q.addBindValue(codes);
    q.addBindValue(xs);
    q.addBindValue(ys);
    q.addBindValue(values);
    if (q.execBatch()){
        db.commit();
        return 0;
    }else{
        qDebug() << "saveHoleDiameterList fail: " + q.lastError().text();
        return 2;
    }
}

//根据编号删除孔径信息
int DataOper::deleteHoleDiameterByCode(QString code)
{
    QSqlQuery q(db);
    QString sql = QString("delete from holeDiameter where code = '%1'").arg(code);
    if(q.exec(sql)){
        releaseDBspace();
        return 0;
    }else{
        qDebug() << "deleteHoleDiameterByCode fail: " + q.lastError().text();
        return 2;
    }
}
//根据编号获取孔径信息
int DataOper::getHoleDiameterListByCode(QVector<HoleDiameter> &holeDiameters, const QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select code, x, y, holeDiameterVal from holeDiameter where code='%1'").arg(code);
    if(query.exec(sql)){
        while(query.next()){
            HoleDiameter holeDiameter;
            holeDiameter.code = query.value("code").toString();
            holeDiameter.x = query.value("x").toDouble();
            holeDiameter.y = query.value("y").toDouble();
            holeDiameter.holeDiameterVal = query.value("holeDiameterVal").toDouble();
            holeDiameters.push_back(holeDiameter);
        }
        return 0;
    }else{
        qDebug() << "getHoleDiameterListByCode fail:" + query.lastError().text();
        return 2;
    }
}




//保存球径信息
int DataOper::saveSphereDiameter(SphereDiameter &sphereDiameter)
{
    //首先删除已有的数据
    deleteSphereDiameterByCode(sphereDiameter.code);

    QSqlQuery query(db);
    query.prepare("insert into sphereDiameter(code, x, y, sphereDiameterVal) values (?,?,?,?)");
    query.addBindValue(sphereDiameter.code);
    query.addBindValue(sphereDiameter.x);
    query.addBindValue(sphereDiameter.y);
    query.addBindValue(sphereDiameter.sphereDiameterVal);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "saveSphereDiameter fail: " + query.lastError().text();
        return 2;
    }
}
int DataOper::saveSphereDiameterList(QVector<SphereDiameter>& sphereDiameters)
{
    if(sphereDiameters.size() != 0){
        deleteSphereDiameterByCode(sphereDiameters[0].code);
    }

    QSqlQuery q(db);
    db.transaction();
    q.prepare("insert into sphereDiameter(code, x, y, sphereDiameterVal) values (?,?,?,?)");
    QVariantList codes;
    QVariantList xs;
    QVariantList ys;
    QVariantList values;
    for(int i = 0; i < sphereDiameters.size(); i++){
        codes << sphereDiameters[i].code;
        xs << sphereDiameters[i].x;
        ys << sphereDiameters[i].y;
        values << sphereDiameters[i].sphereDiameterVal;
    }
    q.addBindValue(codes);
    q.addBindValue(xs);
    q.addBindValue(ys);
    q.addBindValue(values);
    if (q.execBatch()){
        db.commit();
        return 0;
    }else{
        qDebug() << "saveSphereDiameterList fail: " + q.lastError().text();
        return 2;
    }
}
//根据编号删除球径信息
int DataOper::deleteSphereDiameterByCode(QString code)
{
    QSqlQuery q(db);
    QString sql = QString("delete from sphereDiameter where code = '%1'").arg(code);
    if(q.exec(sql)){
        releaseDBspace();
        return 0;
    }else{
        qDebug() << "deleteSphereDiameterByCode fail: " + q.lastError().text();
        return 2;
    }
}
//根据编号获取孔径信息
int DataOper::getSphereDiameterListByCode(QVector<SphereDiameter> &sphereDiameters, const QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select code, x, y, sphereDiameterVal from sphereDiameter where code='%1'").arg(code);
    if(query.exec(sql)){
        while(query.next()){
            SphereDiameter sphereDiameter;
            sphereDiameter.code = query.value("code").toString();
            sphereDiameter.x = query.value("x").toDouble();
            sphereDiameter.y = query.value("y").toDouble();
            sphereDiameter.sphereDiameterVal = query.value("sphereDiameterVal").toDouble();
            sphereDiameters.push_back(sphereDiameter);
        }
        return 0;
    }else{
        qDebug() << "getSphereDiameterListByCode fail:" + query.lastError().text();
        return 2;
    }
}



//保存小球堆叠信息
int DataOper::saveHeapUp(HeapUp &heapUp)
{
    //首先删除已有的数据
    deleteHeapUpByCode(heapUp.code);
    QSqlQuery query(db);
    query.prepare("insert into heapUp(code, x, y) values (?,?,?)");
    query.addBindValue(heapUp.code);
    query.addBindValue(heapUp.x);
    query.addBindValue(heapUp.y);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "saveHeapUp fail: " + query.lastError().text();
        return 2;
    }
}
int DataOper::saveHeapUpList(QVector<HeapUp>& heapUps)
{
    if(heapUps.size() != 0){
        deleteHeapUpByCode(heapUps[0].code);
    }
    QSqlQuery q(db);
    db.transaction();
    q.prepare("insert into heapUp(code, x, y) values (?,?,?)");
    QVariantList codes;
    QVariantList xs;
    QVariantList ys;
    for(int i = 0; i < heapUps.size(); i++){
        codes << heapUps[i].code;
        xs << heapUps[i].x;
        ys << heapUps[i].y;
    }
    q.addBindValue(codes);
    q.addBindValue(xs);
    q.addBindValue(ys);
    if (q.execBatch()){
        db.commit();
        return 0;
    }else{
        qDebug() << "saveHeapUpList fail: " + q.lastError().text();
        return 2;
    }
}
//根据编号删除小球堆叠信息
int DataOper::deleteHeapUpByCode(QString code)
{
    QSqlQuery q(db);
    QString sql = QString("delete from heapUp where code = '%1'").arg(code);
    if(q.exec(sql)){
        releaseDBspace();
        return 0;
    }else{
        qDebug() << "deleteHeapUpByCode fail: " + q.lastError().text();
        return 2;
    }
}
//根据编号获取小球堆叠信息
int DataOper::getHeapUpListByCode(QVector<HeapUp> &heapUps, const QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select code, x, y from heapUp where code='%1'").arg(code);
    if(query.exec(sql)){
        while(query.next()){
            HeapUp heapUp;
            heapUp.code = query.value("code").toString();
            heapUp.x = query.value("x").toDouble();
            heapUp.y = query.value("y").toDouble();
            heapUps.push_back(heapUp);
        }
        return 0;
    }else{
        qDebug() << "getHeapUpListByCode fail:" + query.lastError().text();
        return 2;
    }
}



//保存板片植球率信息
int DataOper::saveCover(Cover &cover)
{
    //首先删除已有的数据
    deleteCoverByCode(cover.code);
    QSqlQuery query(db);
    query.prepare("insert into cover(code, coverVal, outerLength, outerWidth,"
                  "innerLength, innerWidth, width_y, width_x) values (?,?,?,?,?,?,?,?)");
    query.addBindValue(cover.code);
    query.addBindValue(cover.coverVal);
    query.addBindValue(cover.outerLength);
    query.addBindValue(cover.outerWidth);
    query.addBindValue(cover.innerLength);
    query.addBindValue(cover.innerWidth);
    query.addBindValue(cover.width_y);
    query.addBindValue(cover.width_x);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "saveCover fail: " + query.lastError().text();
        return 2;
    }
}
//根据编号删除板片植球率
int DataOper::deleteCoverByCode(QString code)
{
    QSqlQuery q(db);
    QString sql = QString("delete from cover where code = '%1'").arg(code);
    if(q.exec(sql)){
        releaseDBspace();
        return 0;
    }else{
        qDebug() << "deleteCoverByCode fail: " + q.lastError().text();
        return 2;
    }
}
//根据编号获取板片植球率
int DataOper::getCoverByCode(Cover &cover, const QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select code, coverVal, outerLength, outerWidth,"
                           "innerLength, innerWidth, width_y, width_x "
                           "from cover where code='%1'").arg(code);
    if(query.exec(sql)){
        if(query.next()){
            cover.code = query.value("code").toString();
            cover.coverVal = query.value("coverVal").toDouble();
            cover.outerLength = query.value("outerLength").toDouble();
            cover.outerWidth = query.value("outerWidth").toDouble();
            cover.innerLength = query.value("innerLength").toDouble();
            cover.innerWidth = query.value("innerWidth").toDouble();
            cover.width_y = query.value("width_y").toDouble();
            cover.width_x = query.value("width_x").toDouble();
        }
        return 0;
    }else{
        qDebug() << "getCoverByCode fail:" + query.lastError().text();
        return 2;
    }
}
//根据编号更新板片数据
int DataOper::updateCoverData(Cover &cover)
{
    QSqlQuery query(db);
    QString sql = QString("update cover set coverVal=?, outerLength=?, outerWidth=?, "
                          "innerLength=?, innerWidth=?, width_y=?, width_x=? where code = '%1'")
                  .arg(cover.code);
    query.prepare(sql);
    query.addBindValue(cover.coverVal);
    query.addBindValue(cover.outerLength);
    query.addBindValue(cover.outerWidth);
    query.addBindValue(cover.innerLength);
    query.addBindValue(cover.innerWidth);
    query.addBindValue(cover.width_y);
    query.addBindValue(cover.width_x);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "updateCoverData fail: " + query.lastError().text();
        return 2;
    }

}


//保存测量工程信息
int DataOper::saveMeasureProData(MeasurePro& Mpro)
{
    QSqlQuery query(db);
    query.prepare("insert into measurePro(code, time) values (?,?)");
    query.addBindValue(Mpro.code);
    query.addBindValue(Mpro.time);
    if (query.exec()){
        return 0;
    }else{
        qDebug() << "saveMeasureProData fail: " + query.lastError().text();
        return 2;
    }
}

//获取测量工程信息
int DataOper::getMeasureProData(MeasurePro& Mpro, const QString code)
{
    QSqlQuery query(db);
    QString sql  = QString("select code, time from measurePro where code='%1'").arg(code);
    if(query.exec(sql)){
        if(query.next()){
            Mpro.code = query.value("code").toString();
            Mpro.time = query.value("time").toString();
        }
        return 0;
    }else{
        qDebug() << "getMeasureProData fail:" + query.lastError().text();
        return 2;
    }
}

//删除测量工程信息
int DataOper::deleteMeasureProDataByCode(QString code)
{
    QSqlQuery q(db);
    QString sql = QString("delete from measurePro where code = '%1'").arg(code);
    if(q.exec(sql)){
        releaseDBspace();
        return 0;
    }else{
        qDebug() << "deleteMeasureProDataByCode fail: " + q.lastError().text();
        return 2;
    }
}

//根据日期获取测量编号列表
int DataOper::getCodeListByDate(QStringList &codeList, QString startTime, QString endTime)
{
    QSqlQuery query(db);
    QString sql = QString("SELECT DISTINCT plateType FROM hardnessList where time >='%1' and time <= '%2' order by plateType asc")
          .arg(startTime).arg(endTime);
    if(query.exec(sql)){
        while(query.next()){
            codeList.append(query.value("plateType").toString());
        }
        return 0;
    }else{
        qDebug() << "getCodeListByDate fail: " + query.lastError().text();
        return 2;
    }
}
