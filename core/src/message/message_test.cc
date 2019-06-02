#include <iostream>
#include "Message.h"
#include "MessageHeader.h"
#include "MessageBuilder.h"
#include "MessageSerializer"

using namespace std;

int main() {
    cout << "Starting program" << endl;

    MessageBuilder messageBuilder;
    messageBuilder.StartMessage();

    KeyValuePairContainer container;

    unsigned int floatKey = 1;
    unsigned int intKey = 2;
    float floatValue = 300.508;
    int intValue = 500;

    container.AddKeyValuePair(floatKey, floatValue);
    container.AddKeyValuePair(intKey, intValue);

    float containerFloatValue = container.GetFloat(0);
    int containerIntValue = container.GetInt(0);

    cout << "floatValue: " << floatValue << endl << "containerFloatValue: " << containerFloatValue << endl;
    if (containerFloatValue == floatValue) {
        cout << "Container float value successfully added and retrieved" << endl;
    } else {
        cout << "ERROR: Container float value NOT successfully added and retrieved" << endl;
    }

    cout << "intValue: " << intValue << endl << "containerIntValue: " << containerIntValue << endl;
    if (containerIntValue == intValue) {
        cout << "Container int value successfully added and retrieved" << endl;
    } else {
        cout << "ERROR: Container int value NOT successfully added and retrieved" << endl;
    }

    messageBuilder.SetMessageContents(container);
    messageBuilder.SetRecipient(1);
    messageBuilder.SetSender(2);

    Message message = messageBuilder.CompleteMessage();
    
    char data[10000];
    SerializeMessage(&message, data);

    Message De_message = DeserializeMessage(data);

	MessageHeader h = De_message.GetHeader();
    KeyValuePairContainer c = De_message.GetMessageContents();

	cout << h.GetRecipient() << " : " << h.GetSender() << " : " << h.GetTimeCreated() << endl;
    cout << c.GetFloat(0) << " : " << c.GetInt(0) << endl; 

    return 0;
}