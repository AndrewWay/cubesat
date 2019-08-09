//
// Created by John Barry on 2019-07-30.
//

#include "PayloadRepository.h"

PayloadRepository::PayloadRepository(std::string filePaths)
        : Repository(filePaths) {}

//Adds all keys, to watch_list, for storing/returning future data
int PayloadRepository::AddKeysToWatchList(){


	/* * Add keys here * */


	cout << "Printing watch list..." << endl;
	for(int i=0;i<watch_list_.size();i++){
		cout << i << watch_list_[i].key() << endl;
	}

	return 0;
}


int PayloadRepository::ProcessMessage(DataMessage message,int client_file_descriptor){
    cout << "Processing Message Object in PayloadRepository" << endl;
    KeyValuePairContainer c = message.GetMessageContents();

    cout << "Recipient : Sender : Time Created" << endl;
    cout << message.GetRecipient() << " : " << message.GetSender() << " : " << message.GetTimeCreated() << endl;

    cout << "requests:" << endl;
    std::vector<int> requests = message.GetRequests();
    for(int i = 0; i < requests.size(); i++){
        cout << requests.at(i) << endl;
    }

    std::vector<int> floatKeys = c.GetFloatKeys();
    std::vector<int> intKeys = c.GetIntKeys();
    std::vector<int> stringKeys = c.GetStringKeys();
    cout << "key value pairs:" << endl;
    for(int i = 0; i < intKeys.size(); i++){
        cout << intKeys.at(i) << " : " << c.GetInt(intKeys.at(i)) << endl;
    }
    for(int i = 0; i < floatKeys.size(); i++){
        cout << floatKeys.at(i) << " : " << c.GetFloat(floatKeys.at(i)) << endl;
    }
    for(int i = 0; i < stringKeys.size(); i++){
        cout << stringKeys.at(i) << " : " << c.GetString(stringKeys.at(i)) << endl;
    }
    return 0;
}
