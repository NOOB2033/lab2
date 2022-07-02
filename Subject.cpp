#include "Subject.h"


void ASubject::Attach(FileObserver* obs) {
    list.push_back(obs);                     // добавляем наблюдателя
}

void ASubject::Detach(FileObserver* obs) {
    list.erase(std::remove(list.begin(), list.end(), obs), list.end()); // удаляем наблюдателя
}

void ASubject::Notify(std::size_t size, bool exist) {
    for (auto iter : list) {               // итерируемся по наблюдателям
        if (iter != nullptr) {                         // если наблюдатель существует, то обновляем информацию
            iter->Update(size, exist);
        }
    }
}


ConcreteFile::ConcreteFile(const QString& filename) :
        file(filename) {
    file.open(QIODevice::ReadOnly); // открываем файл на чтение
}

void ConcreteFile::ChangeFile() {
    Notify(file.size(), file.exists()); // передаем размер файла, и факт существования файла
}