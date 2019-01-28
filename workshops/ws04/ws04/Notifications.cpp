//
//  Notifications.cpp
//  ws04
//
//  Created by Naim Sakaamini on 2018-09-27.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include "Notifications.h"
namespace w5
{
    Notifications::Notifications()
    {
        msg = new Message[10];
    }
    
    
    Notifications::Notifications(const Notifications& src)
    {
        *this = src;
    }
    
    
    Notifications& Notifications::operator=(const Notifications&src)
    {
        if (this != &src)
        {
            for (int i = 0; i < 10; i++)
            {
                msg[i] = src.msg[i];
            }
        }
        return *this;
    }
    
    
    Notifications::Notifications(Notifications&& src)
    {
        *this = std::move(src);
    }
    
    
    Notifications& Notifications::operator=(Notifications&& src)
    {
        if (this != &src)
        {
            for (int i = 0; i < 10; i++)
            {
                msg[i] = src.msg[i];
            }
        }
        return *this;
    }
    
    
    Notifications::~Notifications()
    {
        delete [] msg;
        msg = nullptr;
    }
    
    
    void Notifications::operator+=(const Message& tmsg)
    {
        
        msg[arrSize] = tmsg;
        arrSize++;
    }
    
    
    void Notifications::display(std::ostream& os) const
    {
        for (int i = 0; i < arrSize; i++)
        {
            msg[i].display(os);
        }
    }
}
