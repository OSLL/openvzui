#ifndef CONTAINER_H
#define CONTAINER_H

#include <QString>

enum ContainerStatus {Stopped, Running};

struct container_t {
    QString ctid;
    qint32 nproc;
    ContainerStatus status;
};

#endif // CONTAINER_H
