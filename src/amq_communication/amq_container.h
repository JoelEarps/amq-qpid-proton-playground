#include <iostream>

class CAMQP_Communication {
    public:
        CAMQP_Communication();
        /* 
        Similar to send sync in the sitecontroller
        */
        void send_message();
    
    protected:
        /*
        Purpose of this function
        1. Create container
        2. Set up all queues similar to site controlelr
        3. Any other config changes
        */
        void setup_initial_connection();
};