//
//  Task.cpp
//  milestone3
//
//  Created by Naim Sakaamini on 2018-11-27.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//
#include "Task.h"

Task::Task(std::string & str) : Item(str)
{
    pNextTask = nullptr;
}



void Task::RunProcess(std::ostream & os)
{
    while (!Orders.empty())
    {
        if (Orders.back().getItemFillState(this->getName()) == false)
        {
            Orders.back().fillItem(*this, os);
        }
    }

}


bool Task::MoveTask()
{
    if (!Orders.empty())
    {
        if (Orders.back().getOrderFillState() == true)
        {
            pNextTask->Orders.push_front(std::move(Orders.back()));
        }
    }
    else
    {
        return false;
    }
    return true;
}



void Task::setNextTask(Task & task)
{
    pNextTask = &task;
}



bool Task::getCompleted(CustomerOrder & src)
{
    if (Orders.empty())
        return false;
    src = std::move(Orders.back());
    return true;
    
}



void Task::Validate(std::ostream & os)
{
    os << this->getName() << std::endl;
    if (pNextTask != nullptr)
    {
    os <<pNextTask->getName() << std::endl;
    }
}



Task &Task::operator+=(CustomerOrder && newOrder)
{
    this->Orders.push_front(std::move(newOrder));
    return *this;
}
