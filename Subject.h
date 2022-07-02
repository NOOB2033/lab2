#ifndef LAB2_SUBJECT_H
#define LAB2_SUBJECT_H


#include "Observer.h"


#include <vector>
#include <QFile>


//  Класс, отслеживающий наблюдателей
class ASubject {
    std::vector<FileObserver*> list{};         // вектор наблюдателей
public:
    void Attach(FileObserver* obs);            // Добавить наблюдателя
    void Detach(FileObserver* obs);            // Удалить наблюдателя
    void Notify(std::size_t size, bool exist); // Обновить информацию в наблюдателях
};


// Обертка файла
class ConcreteFile : public ASubject {
    QFile file;
public:
    ConcreteFile(const QString& filename);    // Конструктор
    void ChangeFile();                        // Метод для проверки изменений в файле
};


#endif //LAB2_SUBJECT_H
