#include <iostream>
#include <string>
#include <vector>

#include "task.h"
#include "file.h"

std::vector<Task *> tasks; // TODO fill vector from file

std::vector<std::string> menuItems{
    "Available options:",
    "1. List all tasks",
    "2. Add a task",
    "3. Delete a task",
    "4. Edit a task",
    "5. Exit program",
    "6. Show menu again"};

void showMenu();

int main()
{
    int option = 0;

    while (option != 5)
    {
        showMenu();
        std::cout << std::endl;
        std::cout << "Please select an option!" << std::endl;
        std::cin >> option;
        std::cin.ignore();
        std::cout << std::endl;
        if (option == 1)
        {
            std::cout << "List fo all tasks:" << std::endl;
            listAllTasks(tasks);
        }
        else if (option == 2)
        {
            std::string title;
            std::string desc;
            std::cout << "Enter task title:" << std::endl;
            std::getline(std::cin, title);
            std::cout << "Enter task description:" << std::endl;
            std::getline(std::cin, desc);
            Task *newTask = new Task(title, desc);
            tasks.push_back(newTask);
        }
        else if (option == 3)
        {
            std::cout << "Enter the task ID:" << std::endl;
            int taskID;
            std::cin >> taskID;
            std::cin.ignore();
            if (tasks.size() > taskID - 1)
            {
                std::string title = tasks[taskID - 1]->getTitle();
                delete tasks[taskID - 1];
                auto iterator = tasks.begin() + taskID - 1;
                tasks.erase(iterator);
                std::cout << "Task with ID " << taskID << " and title " << title << " deleted. All ID's rearranged, please list again." << std::endl;
            }
            else
            {
                std::cout << "There is no task with this ID" << std::endl;
            }
        }
        else if (option == 4)
        {
            std::cout << "Enter the task ID:" << std::endl;
            int taskID;
            std::cin >> taskID;
            std::cin.ignore();
            if (tasks.size() > taskID - 1)
            {
                std::string newTitle;
                std::string newDesc;
                std::cout << "Current title is " << tasks[taskID - 1]->getTitle() << std::endl;
                std::cout << "Enter the new one:" << std::endl;
                getline(std::cin, newTitle);
                std::cout << "Current description is " << tasks[taskID - 1]->getDesc() << std::endl;
                std::cout << "Enter the new one:" << std::endl;
                getline(std::cin, newDesc);
                tasks[taskID - 1]->setTitle(newTitle);
                tasks[taskID - 1]->setDesc(newDesc);
            }
            else
            {
                std::cout << "There is no task with this ID" << std::endl;
            }
        }
        else if (option == 5)
        {
            if (tasks.size() > 0)
            {
                for (Task *task : tasks)
                {
                    delete task;
                }
                // TODO save to file
                exit;
            }
            exit;
        }
        else if (option == 6)
        {
            showMenu();
        }
        else
        {
            std::cout << "No such an option!" << std::endl;
        }
    }
}

void showMenu()
{
    for (std::string menuItem : menuItems)
    {
        std::cout << menuItem << std::endl;
    }
    std::cout << std::endl;
}