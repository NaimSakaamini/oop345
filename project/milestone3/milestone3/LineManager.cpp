//
//  LineManager.cpp
//  milestone3
//
//  Created by Naim Sakaamini on 2018-11-27.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include "LineManager.h"
#include "Utilities.h"
using namespace std;

LineManager::LineManager(std::string & fName, std::vector<Task *> & tasks, std::vector<CustomerOrder> & Order)
{
    
    std::ifstream ifs(fName);
    for (size_t i = 0; i < tasks.size(); i++)
    {
        AssemblyLine.push_back(move(tasks[i]));
    }
    
    for (int i = 0; i < Order.size(); i++)
    {
        ToBeFilled.push_front(move(Order[i]));
        CustomerOrder_Count++;
    }
    
    
    int index = 0;
    std::fstream file(fName);
    Utilities d;
    std::string temp;
    std::string token;
    
    while (getline(file, temp))
    {
        size_t pos = 0;
        bool flag = true;
        
        token = d.extractToken(temp, pos, flag);
        for (size_t i = 0; i < tasks.size(); i++)
        {
            if (tasks[i]->getName() == token)
            {
                if (flag == true )
                {
                    token = d.extractToken(temp, pos, flag);
                    
                    for (size_t j = 0;  j < tasks.size(); j++)
                    {
                        if (tasks[j]->getName() == token)
                        {
                            tasks[i]->setNextTask(*AssemblyLine[j]);
                            j = tasks.size();
                        }
                        
                        
                        
                        
                    }
                    i = tasks.size();
                }
                
            }
        }
        
    }
}


    
    
bool LineManager::Run(std::ostream & os)
{
    
    static size_t iterator = 0;
    if (ToBeFilled.size() != 0)
    {
        *AssemblyLine.at(iterator) +=std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
    }
    for (size_t i = 0; i < AssemblyLine.size(); i++)
    {
        AssemblyLine.at(i)->RunProcess( os );
    }
    
    return false;
}

void LineManager::displayCompleted(std::ostream& other) const
{
    for (size_t i = 0; i < Completed.size(); i++)
    {
        if (Completed[i].getOrderFillState()) Completed[i].display(other);
    }
    
}
void LineManager::validateTasks() const
{
    for (size_t i = 0; i < AssemblyLine.size(); i++)
    {
        AssemblyLine[i]->validate(std::cout);
    }
}
