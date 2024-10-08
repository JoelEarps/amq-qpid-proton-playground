#include <iostream>
#include "amq_container.h"

int main() {
    std::cout << "Hello World!" << std::endl;
    CAMQP_Communication test_class;
    test_class.send_message();
    return 0;
}

