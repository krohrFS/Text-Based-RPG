#include "Employer.cpp"
#include "GameEngine.cpp"


// Small Class to show it can be done in the same file
// Make this primarily static

class Utility {
    // when we're talking about classes that will provide utility methods generally they do not have their own fields, as fields require an object
    // UNLESS the fields themselves are static, which we will not go into today, and we're going to all of methods to be public and ready for use outside of 
    // this class

public:
    // Because we are intending this class to be static a constructor is not needed - constructors are only required for creating objects

    // Welcome Message Method
    static void Message(std::string message)
    {
        std::cout << message << std::endl;
    }

    static void Line()
    {
        std::cout << "----------------------------------------" << std::endl;
    }

};

int main()
{
 

  Utility::Message("Text Based RPG Elements");
  // We need an "engine" - think very small in this case because we are doing very simple things with it
  // We're going to need a Player Character class
  // We're going to need a monster class 
  // We're going to need an item class

  GameEngine game;
  game.GameRun();



    
}


