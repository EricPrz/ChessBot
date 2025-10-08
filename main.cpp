#include <chrono>
#include <iostream>
#include <string>
#include <thread>

bool running = true;

void read_smth(){
    std::cout << "hi, im listening" << std::endl;
    std::string msg;
    while (running){
        std::getline(std::cin, msg);
        std::cout << msg << std::endl;

        if (msg == "q"){
            running = false;
            return;
        }
    }
}

void print_smth(){
    while (running){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "smth" << std::endl;
    }
}



int main(){

    std::thread m(read_smth);
    std::thread t(print_smth);

    t.join();
    m.join();

    std::cout << "Hello World" << std::endl;
    return 0;
}
