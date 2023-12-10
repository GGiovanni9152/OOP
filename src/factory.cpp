#include "../include/factory.h"
#include "../include/Observer.h"



std::shared_ptr<NPC> Factory::factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    
    int type{0};

    if (is >> type)
    {
        switch (type)
        {
            case Knight_Type:
                result = std::make_shared<Knight>(is);
                break;
            
            case Belka_Type:
                result = std::make_shared<Belka>(is);
                break;
            
            case Pegas_Type:
                result = std::make_shared<Pegas>(is);
                break;
            
            default:
                std::cout << "Kring" << std::endl;
                break;
        }
    }

    else
    {
        std::cerr << "unexpected NPC type:" << type << std::endl;
    }

    if (result)
    {
        result -> subscribe(TextObserver::get());
        result -> subscribe(FileObserver::get());
    }

    return result;
}

std::shared_ptr<NPC> Factory::factory(NpcType type, int x, int y, std::string name)
{
    std::shared_ptr<NPC> result;

    switch (type)
    {
        case Knight_Type:
            result = std::make_shared<Knight>(x, y, name);
            break;
        
        case Belka_Type:
            result = std::make_shared<Belka>(x, y, name);
            break;
        
        case Pegas_Type:
            result = std::make_shared<Pegas>(x, y, name);
            break;
        
        default:
            break;
    }

    if (result)
    {
        result -> subscribe(TextObserver::get());
        result -> subscribe(FileObserver::get());
    }

    return result;
}
