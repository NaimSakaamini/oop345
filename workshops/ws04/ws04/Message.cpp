//
//  Message.cpp
//  ws04
//
//  Created by Naim Sakaamini on 2018-09-27.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include "Message.h"
#include <iostream>
#include <fstream>


namespace w5
{
    Message::Message(std::ifstream& in, char c)
    {
        if(in.is_open())
        {
            getline(in, msg, c);
        }
        else
        {
            msg = "";
        }
    }
    
    
    bool Message::empty() const
    {
        return msg == ""? true : false;
    }
    
    
    void Message::display(std::ostream& os) const
    {
        std::string user = "";
        std::string reply = "";
        std::string tweet = "";
        
        size_t space = msg.find(' ');
        
        user = msg.substr(0, space);
        
        if (msg.find('@') != std::string::npos)
        {
            std::string replyTweet = msg.substr(msg.find('@') + 1, std::string::npos);
            reply = replyTweet.substr(0, replyTweet.find(' '));
             tweet = replyTweet.substr(replyTweet.find(' ')+1, std::string::npos);
        }
        else if (space != std::string::npos )
        {
            tweet = msg.substr(space + 1, std::string::npos);
        }
        
        if (tweet != "")
        {
        os << "Messages" << std::endl;
        os << "User   : " << user << std::endl;
        if (reply != "")
        {
            os << "Reply  : " << reply << std::endl;
        }
        os << "Tweet  : " << tweet << std::endl;
        }
    }
}
