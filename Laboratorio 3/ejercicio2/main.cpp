#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;
Time::Time(const int h, const int m, const int s)
    : hour(make_unique<int>(h)),
      minute(make_unique<int>(m)),
      second(make_unique<int>(s))
{
}
void Time::setTime(const int h, const int m, const int s)
{
    *hour = h; // Asignación a través del puntero
    *minute = m;
    *second = s;
}
void Time::print() const
{
    cout << setw(2) << setfill('0') << *hour << ":"
         << setw(2) << setfill('0') << *minute << ":"
         << setw(2) << setfill('0') << *second << "\n";
}
bool Time::equals(const Time &otherTime) const
{
    return (*hour == *otherTime.hour &&
            *minute == *otherTime.minute &&
            *second == *otherTime.second);
}
#include <iostream>
#include "time.h"
using namespace std;
int main()
{
    // Crear las instancias usando punteros inteligentes
    unique_ptr<Time> t1 = make_unique<Time>(10, 50, 59); // Memoria dinámica
    t1->print();                                         // 10:50:59
    unique_ptr<Time> t2 = make_unique<Time>();           // Memoria dinámica con valores por defecto
    t2->print();                                         // 00:00:00
    t2->setTime(6, 39, 9);
    t2->print();        
    if (t1->equals(*t2))
        cout << "Dos objetos son IGUALES\n";
    else
        cout << "Dos objetos NO son IGUALES\n";
    return 0;
}