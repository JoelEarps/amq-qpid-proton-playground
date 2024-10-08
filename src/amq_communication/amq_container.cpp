#include "amq_container.h"

CAMQP_Communication::CAMQP_Communication(){
    std::cout << "Hello from Constructor" << std::endl;
    setup_initial_connection();
}

void CAMQP_Communication::setup_initial_connection(){
    std::cout << "Setting up Lib Proton Container" << std::endl;
}

void CAMQP_Communication::send_message(){
    std::cout << "Sending Message" << std::endl;
}