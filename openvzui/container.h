#ifndef CONTAINER_H
#define CONTAINER_H

#include <QString>

enum ContainerStatus {Stopped, Running};

struct container_t {
    QString _ctid;
    qint32 _nproc;
    ContainerStatus _status;
    bool operator==(const struct container_t &obj) {
        return _ctid == obj._ctid;
    }
};

#endif // CONTAINER_H
