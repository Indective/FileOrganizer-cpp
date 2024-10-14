#include "FileOrganizer.h"
#include <iostream>
#include <string>
#include <filesystem>

FileOrganizer organizer;
namespace fs = std::filesystem;

int main() 
{
    std::string command;
    std::string filename;
    std::string new_filename;
    std::string dirname;
    int textcolor;
    int bgcolor; 

    std::string commands[10] = {"cd","mkdir","nf","rf","ef","COLOR","sd","rd","df","help"};
    std::string commands_exp[10] = 
    {"chnages directory","creates a new directory"
    ,"creates a new .txt file","removes a pre-existing .txt file",
    "edits a pre-existing .txt file","changes foreground and background color",
    "lists all files or subdirectories in directory","deletes a directory",
    "duplicate a file ","lists all commands with explantions"};

    std::cout << "\n" << "Indective Windows [Version 10.0.19045.4894]" << std::endl;
    std::cout << "(c) Indective Corporation. All rights reserved." << "\n";

    while (true) {

        std::cout << "\n" <<  fs::current_path() <<  "> ";
        std::getline(std::cin, command);

        // Call the appropriate function from FileOrganizer.cpp
        if (command.find("mkdir") == 0) {
            std::string dirName = command.substr(6); // Extract directory name
            if (!dirName.empty()) {
                organizer.createDirectory(dirName);
            } else {
                std::cout << "Error: No directory name provided.\n";
            }
        } 
        else if (command.find("cd") == 0) {
            std::string path = command.substr(3); // Extract path
            if (!path.empty()) {
                organizer.changeDirectory(path);
            } else {
                std::cout << "Error: No path provided.\n";
            }
        } 
        else if(command.find("nf") == 0)
        {
            filename = command.substr(3);

            organizer.newfile(filename);
        }
        else if(command.find("ef") == 0)
        {
            filename = command.substr(3);

            organizer.editfile(filename);
        }
        else if(command.find("rf") == 0)
        {
            filename = command.substr(3);

            organizer.removeFile(filename);
        }
        else if (command.find("COLOR") == 0)
        {
            std::cout << "List of colors (Foreground & Background) \n";
            std::cout << "0 = Black, 1 = Blue, 2 = Green, 3 = Aqua, 4 = Red, 5 = Purple, \n";
            std::cout << "// 6 = Yellow, 7 = White, 8 = Gray, 9 = Light Blue, 10 = Light Green, \n";
            std::cout << "// 11 = Light Aqua, 12 = Light Red, 13 = Light Purple, 14 = Light Yellow, 15 = Bright White \n";

            std::cout << "Enter text color : ";
            std::cin >> textcolor;

            std::cout << "\nEnter Background color : ";
            std::cin >> bgcolor;

            organizer.changeColor(textcolor, bgcolor);
        }
        else if (command.find("sd") == 0)
        {
            dirname = command.substr(3);
            organizer.showDirectory(dirname);
        }
        else if(command.find("df") == 0)
        {
            std::cout << "Enter file name : ";
            std::getline(std::cin , filename);

            std::cout << "Enter new file name : ";
            std::getline(std::cin , new_filename);

            organizer.dupFile(filename,new_filename);
        }
        else if(command.find("help") == 0)
        {
            for(int i = 0; i < 10; i ++)
            {
                std::cout << commands[i] << " - " << commands_exp[i] << std::endl;
            }
        }
        else if(command.find("rd") == 0)
        {
            dirname = command.substr(3);

            organizer.removeFile(dirname);
        }
        else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}
