#include "CubeSat.h"

// Null constructor for CubeSat class
//
CubeSat::CubeSat() {
    // Null
}

void CubeSat::SendMessageToGroundStation(const std::string &contents) {
    Message* message = new Message(contents);

    //Send to GroundStation
    //TODO Call GroundStation's Process Message Function.
    //TODO Pass the message as argument
}

void CubeSat::ProcessMessage(const Message &message) {
    std::string contents = message.getContents();

    if(contents=="GET_BATTERY"){
        std::string str=to_string(battery_manager_.avg_battery_level());
        this->SendMessageToGroundStation(str);
    }
}

void CubeSat::set_ground_station(GroundStation ground_station) {
    this->ground_station_ = ground_station;
}