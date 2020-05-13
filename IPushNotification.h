#pragma once
#include <string>

namespace PUSHNOTIFICATIONUTILITY
{
    class IObserver
    {
    public:
        virtual ~IObserver() {}
        virtual void update(std::string message) = 0;
    };

    class ISubject
    {
    public:
        virtual ~ISubject() {}
        virtual void registerObserver(IObserver* ob) = 0;
        virtual void removeObserver(IObserver* ob) = 0;
        virtual void notifyObservers(std::string message) = 0;
    };   
}