#include <string>

class Greeter {
  public: 
    inline  std::string greet(std::string name) {
        return "Hello, " + name + "!";
    }
};

