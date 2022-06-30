#include "Observer.h"


FileObserver::FileObserver(const QString&& obsname) :
        name(obsname)
{}

void FileObserver::Update(std::size_t size, bool exist) {
    fileExist = exist;
    if (fileExist) {
        if (size > 0) {
            std::cout << "File exists, its size is " << size << std::endl;
            if (size != fileSize) {
                std::cout << "File exists and has been modified. The size has become equal to " << size << std::endl;
            }
        }
    } else {
        std::cout << "File does not exist!\n";
    }
    fileSize = size;
}