#include <QCoreApplication>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

int GetRandom(int max) {
    return std::rand() % (max + 1);
}

void ExecuteThread(int id){
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std:: chrono :: system_clock :: to_time_t(nowTime);

    // calcular la zona horaria local
    tm myLocalTime = * localtime(&sleepTime) ;

    qDebug() << "Thread: " << id << "sleep Time: " << std:: ctime (&sleepTime) ; // < "\n";
    qDebug() << "Month: " << (myLocalTime.tm_mon) +1;// << "\n";
    qDebug() << "Day: " << myLocalTime . tm_mday; // < "\n";
    qDebug() << "Year: " << myLocalTime. tm_year ; // < "\n";
    qDebug() << "Hours: " << myLocalTime.tm_hour; // << "\n";
    qDebug() << "Minutes: " << myLocalTime.tm_min; // << "\n";
    qDebug() << "Seconds: " << myLocalTime.tm_sec;// << "\n";

    // 3 segundos de espera antes de imprimir en consola
    std:: this_thread:: sleep_for(std :: chrono :: seconds(GetRandom(3)));

    nowTime = std:: chrono :: system_clock :: now();
    sleepTime = std:: chrono :: system_clock :: to_time_t(nowTime);
    qDebug ( ) << "Thread " << id << " Awake Time : " << std:: ctime (&sleepTime) << "\n";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::thread th1 (ExecuteThread, 1);
    th1.join();

    std::thread th2 (ExecuteThread, 2);
    th2.join();

    return a.exec();
}
