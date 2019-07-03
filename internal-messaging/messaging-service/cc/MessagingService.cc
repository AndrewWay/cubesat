//
// Created by Spencer Axford on 2019-05-15.
//

#include "MessagingService.h"
#include "ProcessFilePaths.h"

#include <string>

MessagingService::MessagingService(unsigned int recipient) : 
    client_socket_(IdentifierToProcessFilePath(recipient)){}

std::string MessagingService::IdentifierToProcessFilePath(unsigned int identifier){
   // identifier_ = static_cast<Identifier>(identifier);
    RecipientIdentifiers ids;
	ProcessFilePaths filePaths;
    std::string filepath;
    switch(identifier){
        case ids.power_subsystem :
            //ipc/i2c
            break;
        case ids.comms_subsystem :
            //ipc/i2c
            break;
        case ids.adcs_subsystem :
            //ipc/i2c
            break;
        case ids.payload_subsystem :
            //ipc/i2c
            break;
        case ids.gps_subsystem :
            //ipc/i2c
            break;
        case ids.power_repository :
            return filePaths.power_repository;
        case ids.comms_repository :
            return filePaths.comms_repository;
        case ids.adcs_repository :
            return filePaths.adcs_repository;
        case ids.payload_repository :
         return filePaths.payload_repository;
        case ids.gps_repository :
            return filePaths.gps_repository;
        default:
            std::cout << "ERROR: Identifier" << identifier << " does not exist" << std::endl;
            break;
    }
    return "";
}
