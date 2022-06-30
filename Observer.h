#ifndef LAB2_OBSERVER_H
#define LAB2_OBSERVER_H


#include <iostream>
#include <QString>


// Интерфейс наблюдателя
class IObserver {
public:
    virtual void Update(size_t size, bool exist) = 0;
};


// Наблюдатель
class FileObserver : IObserver {
    QString name{};
    size_t fileSize{0};
    bool fileExist{false};
public:
    FileObserver(const QString&& obsname);     // Конструктор
    void Update(size_t size, bool exist); // Метод, обновляющий лог о файле
};


#endif //LAB2_OBSERVER_H