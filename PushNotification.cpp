#include "pch.h"
#include "PushNotification.h"

namespace PUSHNOTIFICATIONUTILITY
{
    Subject::Subject()
    {
        observers.clear();
    }

    void Subject::registerObserver(IObserver* ob)
    {
        observers.push_front(ob);
    }

    void Subject::removeObserver(IObserver* ob)
    {
        observers.remove(ob);
    }

    void Subject::notifyObservers(std::string message)
    {
        for (auto it = observers.begin(); it != observers.end(); ++it)
        {
            Observer *obs = dynamic_cast<Observer*>(*it);
            if (obs != nullptr)
            {
                obs->update(message);
            }
        }
    }

    Subject::~Subject()
    {
        //Do nothing
    }

    int Observer::count = 0;

    Observer::Observer()
    {
        index = count;
        count++;
    }

    void Observer::update(std::string message)
    {
        std::cout << "message " << index << ": " << message << std::endl;
    }

    Observer::~Observer()
    {
        //Do nothing
    }
}