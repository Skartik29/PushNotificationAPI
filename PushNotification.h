#pragma once
#include "IPushNotification.h"
#include <forward_list>
#include <iostream>

namespace PUSHNOTIFICATIONUTILITY
{
    class Subject : public ISubject
    {
    protected:
        std::forward_list<IObserver*> observers;
    public:
        Subject();
        void registerObserver(IObserver* ob);
        void removeObserver(IObserver* ob);
        void notifyObservers(std::string message);
        ~Subject();
    };

    class Observer : public IObserver
    {
    protected:
        static int count;
        int index;
    public:
        Observer();
        void update(std::string message);
        ~Observer();
    };
}