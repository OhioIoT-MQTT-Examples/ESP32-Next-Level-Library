#pragma once


class Device {

    public:

        Device();

        void setup();
        void loop();
        static void message_handler(char *, char *);

};


extern Device device;