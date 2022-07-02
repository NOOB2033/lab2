#include <QCoreApplication>
#include <thread>


#include "Subject.h"


int main(int argc, char** argv) {
    QString filename = "text.txt"; // Название отслеживаемого файла
    ConcreteFile file(filename);   // Объект файла

    FileObserver observer1(filename); // Создаем первого наблюдателя
    FileObserver observer2(filename); // Создаем второго наблюдателя

    file.Attach(&observer1); // Добавляем первого наблюдателя
    file.ChangeFile();           // Изменяем информации о файле
    file.Attach(&observer2); // Добавляем второго наблюдателя
    file.ChangeFile();           // Изменяем информацию о файле
    file.Detach(&observer2); // Удаляем второго наблюдателя
    file.ChangeFile();           // Изменяем информацию о файле



    for (std::size_t i = 0; i < 1000; ++i) {   // Проверяем, изменился ли файл каждую секунду, в течении 1000 секунд
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        file.ChangeFile();
    }

    return 0;
}
