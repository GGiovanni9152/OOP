#pragma once

#include "npc.h"
#include "knight.h"
#include "pegas.h"
#include "belka.h"
#include "Observer.h"

class Factory
{
    public:
        std::shared_ptr<NPC> factory(std::istream &is)
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

        std::shared_ptr<NPC> factory(NpcType type, int x, int y)
        {
            std::shared_ptr<NPC> result;

            switch (type)
            {
                case Knight_Type:
                    result = std::make_shared<Knight>(x, y);
                    break;
                
                case Belka_Type:
                    result = std::make_shared<Belka>(x, y);
                    break;
                
                case Pegas_Type:
                    result = std::make_shared<Pegas>(x, y);
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

};