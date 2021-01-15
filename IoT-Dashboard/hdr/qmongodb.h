#ifndef QMONGODB_H
#define QMONGODB_H

#include <QObject>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

class QMongoDB
{
public:
    QMongoDB();
};

#endif // QMONGODB_H
