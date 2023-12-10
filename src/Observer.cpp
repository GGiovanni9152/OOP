#include "../include/Observer.h"

std::shared_ptr<IFightObserver> TextObserver::get()
{
    static TextObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
}

void TextObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win)
{
    if (win)
    {
        std::cout << std::endl
                      << "Murder --------" << std::endl;
        attacker->print();
        defender->print();
    }
}

std::shared_ptr<IFightObserver> FileObserver::get()
{
    static FileObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
}

void FileObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win)
{
    std::ofstream fs;
    fs.open("log.txt", std::ios::app);

    if (win)
    {
        fs << std::endl << "Murder --------" << std::endl;
        fs << *attacker << std::endl;
        fs << *defender << std::endl;
    }

    fs.flush();

    fs.close();
}