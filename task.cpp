#include "task.h"
#include <vector>
#include <iostream>

Task *addTask(std::string title, std::string desc)
{
    return new Task(title, desc);
}

int deleteTask(Task *task)
{
    if (task != nullptr)
    {
        delete task;
        return 0;
    }
    return -1;
}

int editTask(Task *task, std::string newTitle, std::string newDesc)
{
    if (task != nullptr)
    {
        task->setTitle(newTitle);
        task->setDesc(newDesc);
        return 0;
    }
    return -1;
}

int listAllTasks(std::vector<Task *> tasks)
{
    if (tasks.size() != 0)
    {
        int i = 1;
        for (Task *task : tasks)
        {
            std::cout << i << ". " << task->getTitle() << " -> " << task->getDesc() << std::endl;
            i++;
        }
        std::cout << std::endl;
        return 0;
    }
    std::cout << "Nothing to show!" << std::endl
              << std::endl;
    return -1;
}